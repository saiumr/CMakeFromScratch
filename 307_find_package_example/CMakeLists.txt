cmake_minimum_required(VERSION 3.20)
project(find_package_utility)

# 需要先导出306的slib
# cd 306_find_package
# cmake -S . -B build
# cmake --build build
# cmake --install build --config Debug

# find_package寻找路径
set(CMAKE_PREFIX_PATH ../306_find_package/out/config)
message("CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")
find_package(slib)

file(WRITE main.cpp [=[
#include "slib.h"
#include <iostream>

int main() {
    std::cout << "In main, start!\n";
    SLib();
    std::cout << "In main, end!\n";
    return 0;
}

]=])

add_executable(main main.cpp)
target_link_libraries(main slib)

# 头文件路径写在了属性中
get_target_property(inc slib INTERFACE_INCLUDE_DIRECTORIES)
message("INTERFACE_INCLUDE_DIRECTORIES = ${inc}")

# find_package还可以根据版本导入库，多版本package共存，不写了...
