cmake_minimum_required(VERSION 3.20)
project(cmake_compile_features)

message("------------------------------------------")

file(WRITE main.cpp [=[
#include <iostream>
int main() {
    std::cout << "test cmake compile features config." << std::endl;
    return 0;
}

]=]
)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)  # 使用c++17标准

message("------------------------------------------")

# 列出所有支持的特性
message("CMAKE_CXX_COMPILE_FEATURES: ")
set(cxx_compile_features_list ${CMAKE_CXX_COMPILE_FEATURES})
list(SORT cxx_compile_features_list)
foreach(var IN LISTS cxx_compile_features_list)
    message(${var})
endforeach()

message("------------------------------------------")

# 判断支持不支持某个特性
set(input_feature cxx_std_23)
message("Input feature is: ${input_feature}")
if(input_feature IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message("SUPPORTED!")
    target_compile_features(main PRIVATE ${input_feature})  # 使用c++23标准
else()
    message("NO SUPPORTED!")
endif()

message("------------------------------------------")
