#include <zmq.hpp>
#include "data.pb.h"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

void send_protobuf_data(zmq::socket_t &publisher)
{
    SensorData data;
    data.set_id(1);
    data.set_type("temperature");
    data.set_value(23.5);
    data.set_timestamp("2025-01-02 12:00:00");

    std::string serialized_data;
    data.SerializeToString(&serialized_data);

    zmq::message_t message(serialized_data.size());
    memcpy(message.data(), serialized_data.data(), serialized_data.size());
    publisher.send(message, zmq::send_flags::none);
}

int main()
{
    std::ifstream config_file("../config.json");
    json config;
    config_file >> config;

    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind(config["producer"]["endpoint"]);

    while (true)
    {
        send_protobuf_data(publisher);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
