#include <gtest/gtest.h>
TEST(MyTest, MyDownload) {
    EXPECT_EQ(7*6, 42);
}
TEST(MyTest, MyUpload) {
    EXPECT_EQ(7-6, 42);
}

int main(int argc, char* argv[]) {
    // 初始化gtest
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
