cmake_minimum_required(VERSION 3.20)
project(cmake_string)

message("---------------------------------------------")

# 取出 begin 和 end 之间的内容
set(STR1 "  begin test cmake string end  ")
# 查找的开头字符串
set(BSTR "begin")

# 查找起点位置存入 b
# cmake 字符索引从 0 开始
string(FIND ${STR1} ${BSTR} b)
message("FIND ${BSTR} POS ${b}")

# 查找终点位置 e
string(FIND ${STR1} "end" e)
message("FIND end POS ${e}")

# 获取字符串长度
string(LENGTH ${BSTR} bsize)
# 计算截取字符串的起点（此处开始位置在test前面的空格）
math(EXPR b "${b} + ${bsize}")
message("b = ${b}")
# 获取截取字符串长度
math(EXPR length "${e} - ${b}")
message("length = ${e}")
# 获取截取字符串：源字符串 开始位置 截取长度
string(SUBSTRING ${STR1} ${b} ${length} substr)
message("substr = [${substr}]")
# 去掉头尾空白 \t \n \r
string(STRIP ${substr} substr)
message("substr = [${substr}]")
# 转成大写
string(TOUPPER ${substr} substr)
message("substr = [${substr}]")

message("---------------------------------------------")
