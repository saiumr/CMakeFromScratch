cmake_minimum_required(VERSION 3.20)
project(cmake_vs_multi_thread)

file(WRITE slib.cpp [=[
#include <iostream>
void SLib() {
    std::cout << "call slib\n";
}
]=]
)

add_library(slib STATIC slib.cpp)
# 静态导入运行时库（使用MT，MultiThreaded）
set_target_properties(slib PROPERTIES
MSVC_RUNTIME_LIBRARY "MultiThreaded"    # 配置MSVC使用运行时库
)

file(WRITE main.cpp [=[
#include <iostream>
void SLib();
int main() {
    std::cout << "In main\n";
    SLib();
    return 0;
}
]=])

# 默认运行时库是MD（MultiThreadedDLL）
add_executable(main main.cpp)
# 需要统一配置成使用静态MT
set_target_properties(main PROPERTIES
MSVC_RUNTIME_LIBRARY "MultiThreaded"    # 配置MSVC使用运行时库
)
target_link_libraries(main slib)


