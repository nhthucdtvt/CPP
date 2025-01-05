cmake_minimum_required(VERSION 3.16)
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Cài đặt tiêu chuẩn C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tùy chọn để dùng thư viện hệ thống hoặc subproject
option(USE_SYSTEM_LIBS "Use system-installed libraries instead of subprojects" ON)

# Tìm thư viện hoặc thêm thư viện từ external/
if(USE_SYSTEM_LIBS)
    find_package(ZeroMQ REQUIRED)
    find_package(nlohmann_json REQUIRED)
    find_package(Protobuf REQUIRED)
    find_package(spdlog REQUIRED)
else()
    add_subdirectory(external) # Tải và build các thư viện phụ thuộc
endif()

# Thêm thư mục src
add_subdirectory(src)

# Tùy chọn kiểm tra với Google Test
option(ENABLE_TESTS "Enable building tests" ON)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
