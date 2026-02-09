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
