#include <zmq.hpp>
#include "data.pb.h"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

void process_data(const SensorData &data)
{
    json output = {
        {"id", data.id()},
        {"type", data.type()},
        {"value", data.value()},
        {"timestamp", data.timestamp()}};

    std::cout << output.dump(4) << std::endl;
}

int main()
{
    zmq::context_t context(1);

    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://127.0.0.1:5556");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    while (true)
    {
        zmq::message_t message;
        subscriber.recv(message, zmq::recv_flags::none);

        SensorData data;
        data.ParseFromArray(message.data(), message.size());
        process_data(data);
    }
    return 0;
}
