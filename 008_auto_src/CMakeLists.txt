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

# 打印详细的编译日志，默认OFF
#set(CMAKE_VERBOSE_MAKEFILE ON)
#cmake --build build -v命令


set(INCLUDE_PATH "./include")

# 头文件加载路径
include_directories(${INCLUDE_PATH})

# 找到目录下的源码写到变量中
aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)
# 现代cmake并不推荐用aux_source_directory
# 使用target_source或者直接set将源文件名包含进变量

# 读取所有的头文件
file(GLOB H_FILE "${INCLUDE_PATH}/*.h*")

add_executable(${PROJECT_NAME} ${M_SRC} ${SRC} ${H_FILE})

# targer使用方式（windows中使用nmake或者MinGW，用MSVC貌似没有这些）
#[[
cmake --build build --target help
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... edit_cache
... rebuild_cache
... cmake_auto_src
... main.obj
... main.i
... main.s
... src/xlog.obj
... src/xlog.i
... src/xlog.s
... src/xtest.obj
... src/xtest.i
... src/xtest.s
... src/xthread.obj
... src/xthread.i
... src/xthread.s
]]

