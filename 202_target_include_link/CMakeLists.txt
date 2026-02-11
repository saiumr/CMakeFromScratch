cmake_minimum_required(VERSION 3.20)
project(cmake_target_include_link)

# WRITE 写文件 清空原数据
file(WRITE a.cpp [=[
#include <iostream>
void A() {
    std::cout << "A_VAR in A: " << A_VAR << std::endl;
}
]=])

# 静态库
add_library(A STATIC a.cpp)

# 设置头文件
# 调试方式一：cmake --build build -v
# 可以看到/I\A_PUBLIC (MSVC) /I/A_PUBLIC (GCC)
# 相对路径会自动转为绝对路径
# PUBLIC 改变 INCLUDE_DIRECTORIES 和 INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A PUBLIC "/A_PUBLIC")
# PRIVATE 只改变 INCLUDE_DIRECTORIES
target_include_directories(A PRIVATE "/A_PRIVATE")
# INTERFACE 只改变 INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A INTERFACE "/A_INTERFACE")

# 设定A库的宏
target_compile_definitions(A PUBLIC "A_VAR=1")

# 调试方式二
# 打印属性
#[[
 Properties for TARGET A:
   A.INCLUDE_DIRECTORIES = "/A_PUBLIC;/A_PRIVATE"
   A.INTERFACE_INCLUDE_DIRECTORIES = "/A_PUBLIC;/A_INTERFACE"
]]
include(CMakePrintHelpers)
cmake_print_properties(TARGETS A PROPERTIES
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES
)

# B->A 把他俩链接一下，创建一个有依赖项的场景
file(WRITE b.cpp [=[
#include <iostream>
void A();
void B() {
    A();
    std::cout << "A_VAR in B: " << A_VAR << std::endl;
    #ifndef B_VAR
        std::cout << "cannot find B_AVAR in B lib" << std::endl;
    #endif
}
]=])

add_library(B STATIC b.cpp)
target_link_libraries(B PUBLIC A)
target_include_directories(B PUBLIC "/B_PUBLIC")

# 设定B库的宏，编译B时不需要，依赖B的需要
target_compile_definitions(B INTERFACE B_VAR=2)

#[[
 Properties for TARGET B:
   B.INCLUDE_DIRECTORIES = "/B_PUBLIC"
   B.INTERFACE_INCLUDE_DIRECTORIES = "/B_PUBLIC"
]]
# 打印不出继承的属性
cmake_print_properties(TARGETS B PROPERTIES
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES
)

# 设置cmake原生属性调试接口，可以打印继承的属性
set(CMAKE_DEBUG_TARGET_PROPERTIES
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES
)

# main->B->A
file(WRITE main.cpp [=[
#include <iostream>
int main() {
    void B();
    B();
    std::cout << "B_VAR in main: " << B_VAR << std::endl;
}
]=])

add_executable(main main.cpp)
target_link_libraries(main PUBLIC B)