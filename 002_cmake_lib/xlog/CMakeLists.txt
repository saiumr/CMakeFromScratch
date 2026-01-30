cmake_minimum_required(VERSION 3.20)
project(xlog)

# 添加库(名称 类型 依赖文件)
# 编译完之后会出现静态库xlog.lib
add_library(xlog STATIC xlog.cpp xlog.h)
