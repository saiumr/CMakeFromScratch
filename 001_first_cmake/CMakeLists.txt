# 虽然对文件名大小写不敏感，但还是用标准的CMakeLists.txt

# 指定最低版本
cmake_minimum_required(VERSION 3.20)

# 构建项目名称
project(first_cmake)

# 构建执行程序
add_executable(first_cmake 001_first_cmake.cpp)

# 当前路径构建到build目录(S for source, B for build)：
# cmake -S . -B build [-G "MinGW Makefiles"]
# -G是选取编译器(generate 'x type build')
# windows上如果装了vs默认会用MSVC
# 用cmake -G能看到支持生成的构建文件类型

# 用cmake --build build去编译项目
