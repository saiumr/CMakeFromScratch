cmake_minimum_required(VERSION 3.20)
project(message_color)

# \033o -> 27 Esc ascii
string(ASCII 27 Esc)

# 颜色开始 \033[0;31m
set(R "${Esc}[0;31m")
set(G "${Esc}[0;32m")
set(Y "${Esc}[0;33m")
set(B "${Esc}[0;34m")
# 高亮(看不出来)
set(HR "${Esc}[0;31m")
set(HG "${Esc}[0;32m")
set(HY "${Esc}[0;33m")
set(HB "${Esc}[0;34m")
# 颜色结束 \033[0m
set(E "${Esc}[0m")

message("${R}红${E} 默认颜色")
message("${G}绿${E} 默认颜色")
message("${Y}黄${E} 默认颜色")
message("${B}蓝${E} 默认颜色")
message("${HR}红${E} 默认颜色")
message("${HG}绿${E} 默认颜色")
message("${HY}黄${E} 默认颜色")
message("${HB}蓝${E} 默认颜色")
