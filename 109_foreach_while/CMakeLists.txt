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

# [遍历list数组]

message("LISTS")

set(args "a" "b" "c" "d" "e")
foreach(var IN LISTS args)
message(${var})
endforeach()

message("ITEMS 1")

foreach(var IN ITEMS ${args})  # ITEMS 直接访问list变量
message(${var})
endforeach()

message("ITEMS 2")

foreach(var IN ITEMS 1;2;3;4)
message(${var})
endforeach()

message("---------------------------------------------------")

# 按次序多个lists按条件拼接，遍历多个lists
set(A "0;1;2;3")
set(B "4;5;6;7")
set(out "")
foreach(var IN LISTS A B)
    string(APPEND out ${var} " ")
endforeach()
message("LISTS:${out}")

message("---------------------------------------------------")

# 同步遍历多个lists，用变量索引取值
set(arr1 "1;2;3;4;5")
set(arr2 "A;B;C;D;E")
foreach(var IN ZIP_LISTS arr1 arr2)
    message("${var_0}: ${var_1}")    
endforeach()

# 同步遍历多个lists，直接用多个变量
set(arr1 "1;2;3;4;5")
set(arr2 "A;B;C;D;E")
foreach(var1 var2 IN ZIP_LISTS arr1 arr2)
    message("${var1}-${var2}")
endforeach()



message("---------------------------------------------------")
