cmake_minimum_required(VERSION 3.20)
project(cmake_object)

message("--------------------------------------------")

# a.cpp b.cpp => testa
# main.cpp libtesta.so => main
file(WRITE a.cpp [=[
#include <iostream>
void A() {
    std::cout << "A\n";
}
]=]
)

file(WRITE b.cpp [=[
#include <iostream>
void B() {
    std::cout << "B\n";
}
]=]
)

file(WRITE main.cpp [=[
#include <iostream>
void A();
void B();
int main() {
    A();
    B();
    std::cout << "main\n";
    return 0;
}
]=]
)

# 添加OBJECT对象  testa_obj -> a.cpp.o b.cpp.o
add_library(testa_obj OBJECT a.cpp b.cpp)

# -fPIC表示生成与位置无关的代码
# 在linux下编译动态库时需要加这个选项
# if(NOT WIN32)
#     message("not Windows, add '-fPIC' compile option")
#     target_compile_options(testa_obj PRIVATE "-fPIC")
# endif()

# 使用另一种方式添加 -fPIC
set_target_properties(testa_obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

# obj -> so
# 用生成器表达式获取object对象
# $<TARGET_OBJECTS:testa_obj> -> a.cpp.o b.cpp.o
# Windows下使用MinGW编译没问题，Linux下可能需要添加-fPIC
# MSVC 需要 dllexport 和 dllimport 导出和导入动态库，我们可以用MinGW或者直接Linux测试此课题
add_library(testa SHARED $<TARGET_OBJECTS:testa_obj>)

add_executable(main main.cpp)
target_link_libraries(main testa)

message("--------------------------------------------")
