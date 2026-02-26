cmake_minimum_required(VERSION 3.20)
project("find_package")

# find_package(slib)
# add_execute(main main.cpp)
# target_link_libraries(main slib)

# 我使用过SDL库
# 只是在windows上需要配置环境变量，让find_package找到SDL库

# MODULE Mode
## Find<PackageName>.cmake
## CMAKE_MODULE_PATH

# CONFIG Mode (SDL库就是这样查到的)
## 查找路径 CMAKE_PREFIX_PATH
## 读取文件 config: <lowercasePackageName>-config.cmake; <PackageName>Config.cmake
##          version: <lowercasePackageName>-config-version.cmake; <PackageName>ConfigVersion.cmake

## 生成CONFIG Mode文件  config: install(.. EXPORT ..); version: ...事无巨细，不写这个

message("CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")  # 默认是空的
set(CMAKE_INSTALL_PREFIX out)

###############################################################################

file(WRITE include/slib.h "void SLib();")
file(WRITE slib.cpp [=[
#include "slib.h"
#include <iostream>
void SLib() {
    std::cout << "In SLib function!\n";
}
]=])

add_library(slib STATIC slib.cpp)
# 需要导出头文件
set_target_properties(slib PROPERTIES PUBLIC_HEADER include/slib.h)

# 路径被两次引用，编译slib时，install export写入config时
# target_include_directories(slib PUBLIC include)
target_include_directories(slib PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>   # 只有编译时有值
$<INSTALL_INTERFACE:include>  # 只有install时有值，安装后被引用使用这个路径
)


install(TARGETS slib
EXPORT slib
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
PUBLIC_HEADER DESTINATION include
)

# 生成下面的文件才能用find_package查找到slib
# <PackageName>Config.cmake
# slibConfig.cmake  写入库路径，头文件路径
install(EXPORT slib FILE slibConfig.cmake DESTINATION config)
