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


set(BUILD_SHARED_LIBS ON)  # 动态库
# 把另一个目录里的 CMakeLists.txt 当作“本项目的一部分”来执行。
add_subdirectory("xlog")
add_subdirectory("test_xlog")
