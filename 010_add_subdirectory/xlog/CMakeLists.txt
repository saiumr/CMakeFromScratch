cmake_minimum_required(VERSION 3.20)
project(xlog)

# 3. 描述系统的变量
message("MSVC = " ${MSVC})
message("WIN32 = " ${WIN32})
message("UNIX = " ${UNIX})
message("CMAKE_SYSTEM_NAME = " ${CMAKE_SYSTEM_NAME})

# 4. 控制构建过程的变量，输出路径控制    CMAKE_COLOR_MAKEFILE控制是否生成makefile颜色，默认ON
set(CMAKE_COLOR_MAKEFILE OFF)
add_library(${PROJECT_NAME} xlog.cpp xlog.h)
