cmake_minimum_required(VERSION 3.20)
project(test_ver)

set(VAR1 "测试VAR1的值")

message("\${VAR1} = " "${VAR1}")
message("\${VAR1} = " ${VAR1})
message("VAR1 in a string ${VAR1}")

set(VAR2 "VAR1")
message("VAR2 = " ${VAR2}) 
message("VAR2 = " ${${VAR2}})

message("\$VAR2 = ${VAR2}")
# unset删除变量本身而不是简单清除变量值
unset(VAR2)
message("\$VAR2 = ${VAR2}")



