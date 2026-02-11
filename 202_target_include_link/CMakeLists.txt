cmake_minimum_required(VERSION 3.20)
project(cmake_target_include_link)

# WRITE 写文件 清空原数据
file(WRITE a.cpp [=[
void A() {}
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
void A();
void B() {
    A();
}
]=])

add_library(B STATIC b.cpp)
target_link_libraries(B PUBLIC A)
target_include_directories(B PUBLIC "/B_PUBLIC")
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
int main() {
    void B();
    B();
}
]=])

add_executable(main main.cpp)
target_link_libraries(main PUBLIC B)