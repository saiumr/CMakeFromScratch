cmake_minimum_required(VERSION 3.20)
project(cmake_sub1_function)

function(func_sub1)
    message("in sub1 function")
    math(EXPR sub1_var "${sub1_var} + 1")
    set(sub1_var ${sub1_var} PARENT_SCOPE)  # 开放给调用者
endfunction()

func_sub1()
func_sub1()

message("sub1_var = ${sub1_var} in sub1")

set(sub1_var ${sub1_var} PARENT_SCOPE)  # 开放给父目录
