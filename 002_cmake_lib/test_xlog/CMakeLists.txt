cmake_minimum_required(VERSION 3.20)
project(test_xlog)

# 指定头头文件查找路径
# 同gcc的'-I'
include_directories("../xlog")

# 指定库查找路径
# 注意要实际看看编译的库文件路径
# 不同平台默认生成位置不同
# MSVC是"../xlog/Debug", 默认也会到相应位置(Debug下)查找库，编译不会出错
link_directories("../xlog/build")

add_executable(test_xlog test_xlog.cpp)

# 指定加载的库
target_link_libraries(test_xlog xlog)

