# cmake 多行注释
#[[
message(arg1 arg2 arg3)
]]

cmake_minimum_required(VERSION 3.20)
project(message)
message("参数1")  # 测试message
message("参数p1" "参数p2" #[[注释在message中]] 123 456 测试)
