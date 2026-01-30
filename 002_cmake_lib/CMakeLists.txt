cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories("xlog")

# STATIC换SHARED
add_library(xlog SHARED xlog/xlog.cpp)

# 无link_directories, 因为是直接生成的, 不需要指定路径了

add_executable(test_xlog test_xlog/test_xlog.cpp)
target_link_libraries(test_xlog xlog)

# 若在linux下，可以用ldd查看程序依赖
# 动态库依赖路径是绝对路径就可以把可执行文件放到外部运行
