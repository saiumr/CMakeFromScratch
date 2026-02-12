cmake_minimum_required(VERSION 3.20)
project(vs_group)

file(WRITE main.cpp [=[
#include <iostream>
int main() {
    std::cout << "In main\n";
    return 0;
}
]=])

file(WRITE a.cpp "")
file(WRITE b.cpp "")
file(WRITE a.h "")
file(WRITE b.h "")
add_executable(vs_group main.cpp a.cpp b.cpp a.h b.h)

# vs 中创建 src和include，并存放相应源码文件
source_group(src FILES a.cpp b.cpp)
source_group(include FILES b.h)
# 创建树形目录，需要指定一个根目录前缀
source_group(TREE . PREFIX include/inc FILES a.h)
