# Thêm target producer
if(TARGET ZeroMQ::ZeroMQ)
    add_executable(producer producer.cpp)
    target_link_libraries(producer PRIVATE ZeroMQ::ZeroMQ)
    add_dependencies(producer zeromq_project)
else()
    message(FATAL_ERROR "Target zmq not available. Ensure zmq_project is built first.")
endif()
# add_dependencies(producer build_zmq)

# Thêm target broker
# add_executable(broker broker.cpp)
# target_link_libraries(broker PRIVATE ZeroMQ::ZeroMQ nlohmann_json::nlohmann_json protobuf::protobuf spdlog::spdlog)
# add_dependencies(broker zeromq_project)

# # Thêm target consumer
# add_executable(consumer consumer.cpp)
# target_link_libraries(consumer PRIVATE ZeroMQ::ZeroMQ nlohmann_json::nlohmann_json protobuf::protobuf spdlog::spdlog)
# add_dependencies(consumer zeromq_project)
