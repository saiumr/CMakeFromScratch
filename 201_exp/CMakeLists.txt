cmake_minimum_required(VERSION 3.20)
project(cmake_exp)

add_executable(cmake_exp cmake_exp.cpp)

message("-----------------------------------------------")

# 生成表达式
# [逻辑运算符]
# 一定要配合条件表达式使用

target_compile_definitions(cmake_exp PUBLIC "$<$<BOOL:OFF>:TEST1=123>")
target_compile_definitions(cmake_exp PUBLIC "$<$<BOOL:ON>:TEST2=456>")

# [测试生成表达式的方式]
# 第一种测试方式：利用cmake的错误查看
# target_include_directories(cmake_exp PUBLIC "$<AND:1,0>")
# target_include_directories(cmake_exp PUBLIC "$<OR:0,0>")

set(LIB OFF)
# LIB 为OFF时显示STATIC，ON显示空
# target_include_directories(cmake_exp PUBLIC "$<$<NOT:$<BOOL:${LIB}>>:STATIC>")
# 在配置阶段不处理生成表达式（cmake有配置和生成两个阶段）
# message($<$<NOT:$<BOOL:${LIB}>>:STATIC>)

# 第二种测试方式：生成一个自定义目标
# cmake 生成表达式调试方法（官方）
# cmake -E echo "生成表达式"  --> cmake 执行指令
# cmake --build build --target gen    ->   打印 STATIC=1
add_custom_target(gen COMMAND ${CMAKE_COMMAND} -E echo "$<$<NOT:$<BOOL:${LIB}>>:STATIC=1>")

message("-----------------------------------------------")

# 字符串比较
# $<STREQUAL:string1, string2>
# $<EQUAL:string1, string2>
# target_include_directories(cmake_exp PUBLIC "$<STREQUAL:string1,string1>")
# target_include_directories(cmake_exp PUBLIC "$<EQUAL:9,9>")

# 变量查询
# $<CONFIG:cfgs>
# $<CONFIG> Debug Release ...
# target_include_directories(cmake_exp PUBLIC "$<CONFIG>")
# target_include_directories(cmake_exp PUBLIC "$<CONFIG:Debug,Release>")

# $<PLATFORM_ID:platform_ids>  platform_ids是系统名称，只有两个值：Windows，Linux
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
# target_include_directories(cmake_exp PUBLIC "$<PLATFORM_ID:Windows,Linux>")

# 条件表达式
# $<IF:condition,true_string,false_string>
set(LIB OFF)
target_include_directories(cmake_exp PUBLIC "$<IF:$<BOOL:${LIB}>,ON_STRING,OFF_STRING>")

message("-----------------------------------------------")
