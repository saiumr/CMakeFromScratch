#[[
    CMakeLists.txt
    main.cpp
    src
        xlog.cpp
        xthread.cc
        xtest.c
    include
        xlog.h
        xthread.hpp
]]

cmake_minimum_required(VERSION 3.20)
project("cmake_auto_src")

# 头文件加载路径
include_directories("./include")

# 找到目录下的源码写到变量中
aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)
# 现代cmake并不推荐用aux_source_directory
# 使用target_source或者直接set将源文件名包含进变量

add_executable(${PROJECT_NAME} ${M_SRC} ${SRC})

