cmake_minimum_required(VERSION 3.20)
project(install_code)

file(WRITE a.h "")
file(WRITE b.h "")

# 安装时打印信息
install(CODE "message(\"begin install\")")

set(CMAKE_INSTALL_PREFIX out)
install(FILES a.h TYPE INCLUDE)
install(CODE "message(\"a.h install success\")")
install(FILES b.h TYPE INCLUDE)
install(CODE "message(\"b.h install success\")")

# 写入安装时间
install(CODE [=[
string(TIMESTAMP now "%Y-%m-%d %H:%M:%S")
message(${now})
FILE(APPEND install_log.txt "${now}\n")
]=])
