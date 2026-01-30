cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories("xlog")

# STATIC换SHARED
# 添加xlog库编译，cmake项目自带预处理变量xlog_EXPORTS（没有就自行传递）
# 可以使用它来区分我们当前是在生成库还是使用库
add_library(xlog SHARED xlog/xlog.cpp)

# 无link_directories, 因为是直接生成的, 不需要指定路径了

add_executable(test_xlog test_xlog/test_xlog.cpp)
target_link_libraries(test_xlog xlog)

# 若在linux下，可以用ldd查看程序依赖
# 动态库依赖路径是绝对路径就可以把可执行文件放到外部运行
