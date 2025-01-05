#include <gtest/gtest.h>
#include "protobuf_generated_file.pb.h" // Thay bằng file Protobuf thực tế của bạn
#include <nlohmann/json.hpp>

// Test serialize và deserialize Protobuf
TEST(ProtobufTest, SerializeDeserialize)
{
    // Tạo một object protobuf
    ExampleMessage msg;
    msg.set_id(123);
    msg.set_name("Test Message");

    // Serialize
    std::string serialized;
    msg.SerializeToString(&serialized);

    // Deserialize
    ExampleMessage deserialized_msg;
    ASSERT_TRUE(deserialized_msg.ParseFromString(serialized));
    EXPECT_EQ(deserialized_msg.id(), 123);
    EXPECT_EQ(deserialized_msg.name(), "Test Message");
}

// Test JSON parsing
TEST(JsonTest, ParseJson)
{
    nlohmann::json json_data = {{"id", 123}, {"name", "Test JSON"}};
    EXPECT_EQ(json_data["id"], 123);
    EXPECT_EQ(json_data["name"], "Test JSON");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
