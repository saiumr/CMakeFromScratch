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

# 设置头文件属性
set_target_properties(slib PROPERTIES PUBLIC_HEADER  include/slb.h)
set_target_properties(slib PROPERTIES PRIVATE_HEADER include/slb_pri.h)

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

######################################################################

# 安装目标  DESTINATION 指定相对 CMAKE_INSTALL_PREFIX 的输出路径
# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./out
# cmake --install build --config Debug    默认是Release
# 和设置target输出路径不同，install是拷贝目标到指定目录
set(CMAKE_INSTALL_PREFIX ./out)
message("install prefix: ${CMAKE_INSTALL_PREFIX}")
install(TARGETS slib dlib main DESTINATION bin)

######################################################################
#[=[
目标分类：
RUNTIME -> 执行程序、windows 动态链接库dll文件
ARCHIVE -> 静态库、windows动态库导出符号
LIBRARY -> linux .so 和 mac .dylib 动态库
PUBLIC_HEADER, PRIVATE_HEADER -> 通过 set_target_properties 设定不同的头文件类型
]=]

install(TARGETS main dlib slib
RUNTIME DESTINATION test_install/bin  # main.exe *.dll -> ./out/bin
ARCHIVE DESTINATION test_install/lib
LIBRARY DESTINATION test_install/lib  # for linux and mac
PUBLIC_HEADER DESTINATION target_install/include  # 公开头文件
PRIVATE_HEADER DESTINATION target_install/inc  # 内部头文件
)


