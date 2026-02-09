cmake_minimum_required(VERSION 3.20)
project(cmake_exp)

add_executable(cmake_exp cmake_exp.cpp)

# 生成表达式
# [逻辑运算符]
# 一定要配合条件表达式使用

target_compile_definitions(cmake_exp PUBLIC "$<$<BOOL:OFF>:TEST1=123>")
target_compile_definitions(cmake_exp PUBLIC "$<$<BOOL:ON>:TEST2=456>")

