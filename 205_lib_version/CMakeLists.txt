cmake_minimum_required(VERSION 3.20)
project(cmake_lib_version)

# 此课题为生成动态库的符号链接（Linux下的内容）
# 只有动态库有版本号
# 在linux下执行课题，mingw没生成对应内容

file(WRITE a.cpp [=[
#include <iostream>
void A() {
    std::cout << "A\n";
}
]=]
)

file(WRITE main.cpp [=[
#include <iostream>
void A();
int main() {
    A();
    std::cout << "main\n";
    return 0;
}
]=]
)

message("------------------------------------------")

add_library(a SHARED a.cpp)
# 指定版本号
set_target_properties(a PROPERTIES
VERSION    "2.0.1"
SOVERSION  "15"
# NO_SONAME  ON      # ON 不生成库的符号链接
)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC a)
# 可执行程序生成版本号符号链接
set_target_properties(a PROPERTIES
VERSION    "1.0.2"
# SOVERSION  "3"     # 此设置对可执行程序无效
# NO_SONAME  ON      # ON 不生成库的符号链接
)

message("------------------------------------------")
