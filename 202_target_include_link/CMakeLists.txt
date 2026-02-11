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
