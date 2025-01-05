include(ExternalProject)

# Tải và build Google Test
ExternalProject_Add(
    googletest_project
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
    PREFIX ${CMAKE_BINARY_DIR}/external/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/googletest/install
)

ExternalProject_Get_Property(googletest_project install_dir)
set(GTEST_INSTALL_DIR ${install_dir})
set(GTEST_INCLUDE_DIR ${GTEST_INSTALL_DIR}/include)
set(GTEST_LIB_DIR ${GTEST_INSTALL_DIR}/lib)

add_library(GTest::GTest STATIC IMPORTED)
set_target_properties(GTest::GTest PROPERTIES
    IMPORTED_LOCATION ${GTEST_LIB_DIR}/libgtest.a
    INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIR}
)

add_library(GTest::Main STATIC IMPORTED)
set_target_properties(GTest::Main PROPERTIES
    IMPORTED_LOCATION ${GTEST_LIB_DIR}/libgtest_main.a
    INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIR}
)

add_dependencies(GTest::GTest googletest_project)
add_dependencies(GTest::Main googletest_project)

# Tạo target test
add_executable(test_myproject test_main.cpp)
target_link_libraries(test_myproject PRIVATE GTest::GTest GTest::Main ZeroMQ::ZeroMQ nlohmann_json::nlohmann_json protobuf::protobuf spdlog::spdlog)

# Đăng ký test
add_test(NAME MyProjectTests COMMAND test_myproject)
