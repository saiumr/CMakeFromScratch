cmake_minimum_required(VERSION 3.20)
project(gtest_fetch)

# 使用FetchContent下载googletest
include(FetchContent)
# 下载代码 git svn http
# 默认下载到build/deps中
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    )
# 编译安装gtest
# 配置时指定安装路径：
# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out
# cmake --install build --config=Debug --prefix=out
FetchContent_MakeAvailable(googletest)

# 测试用例
file(WRITE gtest_fetch.cpp [=[
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
]=])

add_executable(gtest_fetch gtest_fetch.cpp)
# 设定gtest的库，头文件会自动推导
target_link_libraries(
    gtest_fetch
    GTest::gtest_main
)

# 联合ctest和gtest（最后还是运行ctest的）
include(GoogleTest)
gtest_discover_tests(gtest_fetch)

# 打开才能运行ctest
# cd build
# ctest -C Debug
enable_testing()
