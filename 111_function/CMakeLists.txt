cmake_minimum_required(VERSION 3.20)
project(cmake_function)

message("-----------------------------------------------------")

# 不同于macro，cmake 函数传递参数，形参是变量
function(func1 arg1 arg2)
    if(arg1)
        message("arg1 is TRUE")
        return()
    endif()
    

    message("IN function func1 arg1 = ${arg1}, arg2 = ${arg2}")
    if(NOT arg1)  # arg1是变量，可以直接判断
        message("arg1 is OFF or FALSE or NOTFOUND")
    endif()

    # 遍历所有变参
    foreach(var IN LISTS ARGN)
        message("var = ${var}")
    endforeach()
    
    
endfunction()

func1(OFF TRUE "test func1" 1 3 ON)
func1(ON TRUE "test func1" 1 3 ON)

message("-----------------------------------------------------")

# [函数参数的作用域]
function(func_var arg1)
    message("var1 = ${var1}")  # 可以访问
    message("arg1 = ${arg1}")
    set(var1 "var1 changed in func_var")  # 不能修改外部变量，这一步相当于创建了局部变量
    set(RET "1" PARENT_SCOPE)  # 设定变量的作用域到父目录（调用者，但不跨目录）
endfunction()

set(var1 "main")
set(arg1 "main arg1")  # 名称和局部变量相同，值被局部变量覆盖
func_var(123)
message("var1 = ${var1}")
message("RET = ${RET}")

message("-----------------------------------------------------")

# 添加子目录
add_subdirectory(sub1)
func_sub1()
message("sub1_var = ${sub1_var} in main")

message("-----------------------------------------------------")
