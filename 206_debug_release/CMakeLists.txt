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

#[[
CMAKE_BUILD_TYPE配置代表不同编译选项
    Debug -g
    Release -O2/3
    RelWithDebInfo -O2 -g
    MinSizeRel -O3
1) Linux mac 控制方法，vs不可用
    CMAKE_BUILD_TYPE linux 默认为空
    一：set(CMAKE_BUILD_TYPE Debug)
    二：cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
    使用cmake --build build -v查看长生成命令加入的编译选项
2) windows：MSVC, nmake
    vs在生成阶段无法控制配置（自动生成4种） 
    但可以在编译命令中传参控制： cmake --build build --config Debug 
    cmake --build build --config Release
    nmake和linux mac下一致
]]

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

        # Debug版本加后缀"d"
        # DEBUG_POSTFIX "d"

        # windows pdb调试文件输出路径
        # PDB_OUTPUT_DIRECTORY ${OUT_LIB_PATH}/pdb
        # PDB_OUTPUT_DIRECTORY_DEBUG ${OUT_LIB_PATH}/debug/pdb
        # PDB_OUTPUT_DIRECTORY_RELEASE ${OUT_LIB_PATH}/release/pdb
    )
endforeach()

message("----------------------------------------")
