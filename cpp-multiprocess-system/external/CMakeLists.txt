include(ExternalProject)

# ZeroMQ
ExternalProject_Add(
    zeromq_project
    GIT_REPOSITORY https://github.com/zeromq/libzmq.git
    GIT_TAG v4.3.4
    PREFIX ${CMAKE_BINARY_DIR}/external/zeromq
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/zeromq/install
    # BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/external/zeromq/install/lib/libzmq.a
    BUILD_COMMAND ${CMAKE_COMMAND} --build . --target install
    LOG_DOWNLOAD ON
    LOG_BUILD ON
    LOG_INSTALL ON
)
ExternalProject_Get_Property(zeromq_project install_dir)
set(ZMQ_INSTALL_DIR ${install_dir})

# Chỉ tạo target nếu file thư viện tồn tại
# if (EXISTS ${ZMQ_INSTALL_DIR}/lib/libzmq.a AND EXISTS ${ZMQ_INSTALL_DIR}/include)
    add_library(ZeroMQ::ZeroMQ STATIC IMPORTED GLOBAL)
    set_target_properties(ZeroMQ::ZeroMQ PROPERTIES
        IMPORTED_LOCATION ${ZMQ_INSTALL_DIR}/lib/libzmq.a
        INTERFACE_INCLUDE_DIRECTORIES ${ZMQ_INSTALL_DIR}/include
    )
    
    # Đảm bảo rằng ZeroMQ::ZeroMQ phụ thuộc vào việc build zeromq_project
    add_dependencies(ZeroMQ::ZeroMQ zeromq_project)
# else()
#     message(FATAL_ERROR "ZeroMQ library not found at ${ZMQ_INSTALL_DIR}/lib/libzmq.a")
# endif()

message(STATUS "ZeroMQ install dir: ${ZMQ_INSTALL_DIR}")
message(STATUS "ZeroMQ library: ${ZMQ_INSTALL_DIR}/lib/libzmq.a")

# Đảm bảo các target khác phụ thuộc vào zeromq_project
# add_custom_target(build_zmq ALL DEPENDS zeromq_project)
# add_dependencies(ZeroMQ::ZeroMQ build_zmq)

# nlohmann_json
ExternalProject_Add(
    nlohmann_json_project
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
    PREFIX ${CMAKE_BINARY_DIR}/external/json
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/json/install
        BUILD_COMMAND ${CMAKE_COMMAND} --build . --target install
    LOG_DOWNLOAD ON
    LOG_BUILD ON
    LOG_INSTALL ON
)
ExternalProject_Get_Property(nlohmann_json_project install_dir)
set(JSON_INSTALL_DIR ${install_dir})
add_library(nlohmann_json::nlohmann_json STATIC IMPORTED GLOBAL)
set_target_properties(nlohmann_json::nlohmann_json PROPERTIES
    IMPORTED_LOCATION ${JSON_INSTALL_DIR}/lib/libnlohmann_json.a
    INTERFACE_INCLUDE_DIRECTORIES ${JSON_INSTALL_DIR}/include
)

# Đảm bảo các target khác phụ thuộc vào nlohmann_json_project
add_dependencies(nlohmann_json::nlohmann_json nlohmann_json_project)

# Protobuf
ExternalProject_Add(
    protobuf_project
    GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
    GIT_TAG v21.9
    PREFIX ${CMAKE_BINARY_DIR}/external/protobuf
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/protobuf/install
)
ExternalProject_Get_Property(protobuf_project install_dir)
set(PROTOBUF_INSTALL_DIR ${install_dir})
add_library(protobuf::protobuf STATIC IMPORTED GLOBAL)
set_target_properties(protobuf::protobuf PROPERTIES
    IMPORTED_LOCATION ${PROTOBUF_INSTALL_DIR}/lib/libprotobuf.a
    INTERFACE_INCLUDE_DIRECTORIES ${PROTOBUF_INSTALL_DIR}/include
)

# spdlog
ExternalProject_Add(
    spdlog_project
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
    PREFIX ${CMAKE_BINARY_DIR}/external/spdlog
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/spdlog/install
)
ExternalProject_Get_Property(spdlog_project install_dir)
set(SPDLOG_INSTALL_DIR ${install_dir})
add_library(spdlog::spdlog STATIC IMPORTED GLOBAL)
set_target_properties(spdlog::spdlog PROPERTIES
    IMPORTED_LOCATION ${SPDLOG_INSTALL_DIR}/lib/libspdlog.a
    INTERFACE_INCLUDE_DIRECTORIES ${SPDLOG_INSTALL_DIR}/include
)
