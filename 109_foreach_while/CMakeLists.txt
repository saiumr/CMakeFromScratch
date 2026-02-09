cmake_minimum_required(VERSION 3.20)
project(cmake_foreach_while)

message("---------------------------------------------------")

# [计算0到5的和]
set(exp "")
foreach(var RANGE 5)
# message("var = ${var}")
string(APPEND exp ${var} "+")
endforeach()

# 去掉末尾的+
string(LENGTH ${exp} exp_length)
math(EXPR exp_length "${exp_length} - 1")
message("origin exp = ${exp}")
string(SUBSTRING ${exp} 0 ${exp_length} exp)
message("exp = ${exp}")

# 计算
math(EXPR out ${exp})
message("out = ${out}")

message("---------------------------------------------------")

# [遍历指定范围[1,3] ]
set(out "")
foreach(var RANGE 1 3)
# message("var = ${var}")
string(APPEND out ${var} " ")
endforeach()
message("out = ${out}")

message("---------------------------------------------------")

# [以step步进循环]
set(out "")
foreach(var RANGE 0 50 5)
string(APPEND out ${var} " ")
endforeach()
message("out = ${out}")

message("---------------------------------------------------")
