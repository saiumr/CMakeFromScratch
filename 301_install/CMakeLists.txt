cmake_minimum_required(VERSION 3.20)

project(cmake_install)

#####################################################################

### 静态库  导出  .lib  .a

# 私有头文件
file(WRITE include/slib_pri.h "#define PRI")

# 公开头文件
file(WRITE include/slib.h "void SLib();")
file(WRITE slib.cpp "void SLib() {}")
add_library(slib STATIC slib.cpp include/slib.h include/slib_pri.h)

#####################################################################

# 动态库 在windows下需要导出
# windows .lib .dll
# linux .so
#mac .dylib
file(WRITE include/dlib.h [=[
#ifdef _WIN32
__declspec(dllexport)
#endif
void DLib();
]=])

file(WRITE dlib.cpp [=[
#include "dlib.h"
void DLib() {}
]=])

add_library(dlib SHARED dlib.cpp include/dlib.h)
target_include_directories(dlib PUBLIC include)

#####################################################################

# 执行程序
file(WRITE main.cpp [=[
#include "slib.h"
#include "dlib.h"

int main() {
    SLib();
    DLib();
    return 0;
}
]=])

add_executable(main main.cpp)

target_include_directories(main PUBLIC include)

target_link_libraries(main dlib slib)
