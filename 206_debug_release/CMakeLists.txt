cmake_minimum_required(VERSION 3.20)
project(cmake_debug_release)

message("----------------------------------------")
message("System is ${CMAKE_SYSTEM_NAME}")
message(STATUS "C compiler ID: ${CMAKE_C_COMPILER_ID}")
message(STATUS "CXX compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message("----------------------------------------")

# Linux 单配置 Debug，linux 下 CMAKE_BUILD_TYPE 默认为空
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    message("CMAKE_BUILD_TYPE is NULL, set Debug")
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 输出目录统一到 build 下
# CMAKE_BINARY_DIR 是build目录
# CMAKE_SOURCE_DIR 是当前执行的CMakeLists.txt所在目录
set(OUT_LIB_PATH ${CMAKE_BINARY_DIR}/lib)
set(OUT_EXE_PATH ${CMAKE_BINARY_DIR}/bin)

# 生成静态库源码
file(WRITE src/slib.cpp [=[
#include <iostream>
void SLib() {
    std::cout << "call slib" << std::endl;
}
]=])

add_library(slib STATIC src/slib.cpp)

# 生成动态库头文件
file(WRITE include/dlib.h [=[
#pragma once

#ifdef _WIN32
    #ifdef dlib_EXPORTS
        #define XCPP_API __declspec(dllexport)
    #else
        #define XCPP_API __declspec(dllimport)
    #endif
#else
    #define XCPP_API
#endif

XCPP_API void DLib();
]=])

# 动态库实现
file(WRITE src/dlib.cpp [=[
#include "dlib.h"
#include <iostream>
void DLib() {
    std::cout << "call dlib" << std::endl;
}
]=])

add_library(dlib SHARED src/dlib.cpp)
target_include_directories(dlib PUBLIC include)

# 主程序
file(WRITE src/main.cpp [=[
#include "dlib.h"
#include <iostream>
void SLib();

int main() {
    std::cout << "In main():\n";
    DLib();
    SLib();
    return 0;
}
]=])

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE dlib slib)

# 统一输出目录（跨平台关键）
# $<CONFIG> 生成器表达式代表Debug或者Release，cmake自动生成
foreach(target dlib slib main)
    set_target_properties(${target} PROPERTIES
        # windows linux 静态库以及 windows 导入库输出路径
        ARCHIVE_OUTPUT_DIRECTORY ${OUT_LIB_PATH}/$<CONFIG>
        # linux .so 和 mac 动态库输出路径
        LIBRARY_OUTPUT_DIRECTORY ${OUT_LIB_PATH}/$<CONFIG>
        # windows动态库，以及 windows 和 linux 可执行文件输出路径
        RUNTIME_OUTPUT_DIRECTORY ${OUT_EXE_PATH}/$<CONFIG>
    )
endforeach()

message("----------------------------------------")
