cmake_minimum_required(VERSION 3.20)
project(xlog)

# 1. 提供信息的变量 ${PROJECT_NAME}
# 2. 改变行为的变量 BUILD_SHARED_LIBS(缓存变量) ON动态库 OFF静态库 默认OFF
# set(BUILD_SHARED_LIBS ON)
set(BUILD_SHARED_LIBS OFF)  # 静态库

# cmake传递变量给c++
add_definitions(-Dxlog_STATIC)  # 默认值1

# 3. 描述系统的变量
message("MSVC = " ${MSVC})
message("WIN32 = " ${WIN32})
message("UNIX = " ${UNIX})
message("CMAKE_SYSTEM_NAME = " ${CMAKE_SYSTEM_NAME})

# 4. 控制构建过程的变量，输出路径控制    CMAKE_COLOR_MAKEFILE控制是否生成makefile颜色，默认ON
set(CMAKE_COLOR_MAKEFILE OFF)
add_library(${PROJECT_NAME} xlog.cpp xlog.h)
