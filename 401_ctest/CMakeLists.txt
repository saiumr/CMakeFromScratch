cmake_minimum_required(VERSION 3.20)
project(cmake_ctest)

file(WRITE main.cpp [=[
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << argc << '\n';
    if (argc <= 1) return -1;
    std::cout << argv[1] << '\n';
    return 0;
}
]=])

add_executable(main main.cpp)

# 添加测试用例，设定用例名称，检查返回值
add_test(NAME ctest_return-1
COMMAND main
)

add_test(NAME ctest_return-0
COMMAND main any_parameter
)

# 打印特定信息
add_test(NAME ctest_success
COMMAND main success
)
# 设定测试用例属性，相当于设定生成的目标属性
set_tests_properties(ctest_success
PROPERTIES
PASS_REGULAR_EXPRESSION success
)

add_test(NAME ctest_failed
COMMAND main
)
# 在windows上貌似并不输出正则匹配设定的字符啊
set_tests_properties(ctest_failed
PROPERTIES
FAIL_REGULAR_EXPRESSION failed
)

# 执行测试用例
enable_testing()

# cd build
# ctest -C Debug/Release
