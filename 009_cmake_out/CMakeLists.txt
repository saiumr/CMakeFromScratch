cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories("xlog")

# CMakeLists.txt路径
message("CMAKE_CURRENT_LIST_DIR = ${CMAKE_CURRENT_LIST_DIR}")
# .so库输出路径(Linux)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")
# 执行程序和.dll 动态库pdb调试文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")
# 归档输出路径：Windows静态库.lib和静态库pdb调试文件，Windows动态库地址文件.lib，linux静态库.a
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/lib")


# STATIC换SHARED
# 添加xlog库编译，cmake项目自带预处理变量xlog_EXPORTS（没有就自行传递）
# 可以使用它来区分我们当前是在生成库还是使用库
# add_library(xlog SHARED xlog/xlog.cpp)

# 上面是动态库，下面是静态库
set(BUILD_SHARED_LIBS OFF)  # 静态库
# cmake传递变量给c++
add_definitions(-Dxlog_STATIC)  # 默认值1
add_library(xlog xlog/xlog.cpp)


# 无link_directories, 因为是直接生成的, 不需要指定路径了

add_executable(test_xlog test_xlog/test_xlog.cpp)
target_link_libraries(test_xlog xlog)

# 若在linux下，可以用ldd查看程序依赖
# 动态库依赖路径是绝对路径就可以把可执行文件放到外部运行
