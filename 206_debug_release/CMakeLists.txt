cmake_minimum_required(VERSION 3.20)
project(cmake_debug_release)

# 静态库
#[[
src
    slib.cpp
    dlib.cpp
    main.cpp
bin
    debug
        main
        dlib.dll  [windows]
    release
lib
    debug
        slib.lib  [windows]
        dlib.lib  [windows]
        dlib.so
        slib.a
    release
]]

file(WRITE src/slib.cpp [=[
void SLib() {}
]=])

#[[
Debug
    -g
Release
    -O2/3
RelWithDebInfo
    -O2 -g
MinSizeRel
    -O3

1) Linux mac 控制方法，vs不可用
    CMAKE_BUILD_TYPE
    linux 默认为空
    一：set(CMAKE_BUILD_TYPE Debug)
    二：cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
    使用cmake --build build -v查看长生成命令加入的编译选项

2) windows：MSVC, nmake
    vs在生成阶段无法控制配置（自动生成4种）
    但可以在编译命令中传参控制：
    cmake --build build --config Debug
    cmake --build build --config Release
    nmake和linux mac下一致
]]

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_library(slib STATIC src/slib.cpp)



