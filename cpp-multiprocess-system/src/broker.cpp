#include <zmq.hpp>
#include "data.pb.h"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

void log_data_to_json(const SensorData &data)
{
    json log_entry = {
        {"id", data.id()},
        {"type", data.type()},
        {"value", data.value()},
        {"timestamp", data.timestamp()}};

    std::ofstream log_file("broker_log.json", std::ios::app);
    log_file << log_entry.dump() << std::endl;
}

int main()
{
    // Khởi tạo logger
    auto logger = spdlog::basic_logger_mt("broker_logger", "logs/broker.log");
    spdlog::set_level(spdlog::level::debug); // Đặt log level (debug, info, warn, error)

    logger->info("Broker started");

    try
    {
        // Giao tiếp với Producer và Consumer
        logger->debug("Waiting for message from producer...");
        // Nhận tin nhắn (giả sử qua ZeroMQ)
        // Deserialize Protobuf
        logger->info("Received message from producer");

        // Serialize sang JSON và ghi log
        nlohmann::json log_data = {{"id", 123}, {"name", "Converted JSON"}};
        logger->debug("Converted to JSON: {}", log_data.dump());
    }
    catch (const std::exception &e)
    {
        logger->error("Error occurred: {}", e.what());
    }

    logger->info("Broker shutting down");

    zmq::context_t context(1);

    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://127.0.0.1:5555");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://127.0.0.1:5556");

    while (true)
    {
        zmq::message_t message;
        subscriber.recv(message, zmq::recv_flags::none);

        SensorData data;
        data.ParseFromArray(message.data(), message.size());
        log_data_to_json(data);

        publisher.send(message, zmq::send_flags::none);
    }
    return 0;
}
