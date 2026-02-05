cmake_minimum_required(VERSION 3.20)
project(cmake_property)

message(----------------------------------------------------)

# 全局属性
# 设置全局属性
set_property(GLOBAL PROPERTY TEST_GLOBAL "test property 001")
# 获取全局属性
get_property(val GLOBAL PROPERTY TEST_GLOBAL)
message("TEST_GLOBAL = ${val}")

message(----------------------------------------------------)

# 访问子目录中的全局变量
add_subdirectory(sub1)
get_property(val GLOBAL PROPERTY SUB1_GLOBAL)
message("SUB1_GLOBAL = ${val}")

message(----------------------------------------------------)

# APPEND
# 数组方式添加，可用for循环访问；TEST_APPEND = append 001;append 002;append 003
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 001")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 002")
set_property(GLOBAL APPEND PROPERTY TEST_APPEND "append 003")
get_property(val GLOBAL PROPERTY TEST_APPEND)
message("TEST_APPEND = ${val}")

message(----------------------------------------------------)

# APPEND_STRING
# 字符串拼接；TEST_APPEND_STRING = append 001 append 002 append 003
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append 001 ")
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append 002 ")
set_property(GLOBAL APPEND_STRING PROPERTY TEST_APPEND_STRING "append 003 ")
get_property(val GLOBAL PROPERTY TEST_APPEND_STRING)
message("TEST_APPEND_STRING = ${val}")

message(----------------------------------------------------)

# get_property SET | DEFINED
set_property(GLOBAL PROPERTY P1 "p1")
get_property(val GLOBAL PROPERTY P1 SET)        # 1
message("P1 SET = ${val}")
get_property(val GLOBAL PROPERTY P1 DEFINED)    # 0  只有调用define_property之后才会为1
message("P1 DEFINED = ${val}")

# 定义属性，不需要赋值
define_property(GLOBAL PROPERTY TEST_DEF BRIEF_DOCS "test_def brief docs")
get_property(val GLOBAL PROPERTY TEST_DEF DEFINED)
message("TEST_DEF = ${val}")

# 获取属性概要说明
get_property(val GLOBAL PROPERTY TEST_DEF BRIEF_DOCS)
message("TEST_DEF BRIEF_DOCS = ${val}")

message(----------------------------------------------------)

# 目录属性
set_property(DIRECTORY . PROPERTY DIR1 "dir001")
get_property(val DIRECTORY . PROPERTY DIR1)
message("DIR1 = ${val}")
# 获取子目录sub1中的目录属性
get_property(val DIRECTORY sub1 PROPERTY DIR1)
message("sub1 DIR1 = ${val}")

message(----------------------------------------------------)

# 文件属性
set_property(SOURCE main.cpp PROPERTY S1 "s1 value")
get_property(val SOURCE main.cpp PROPERTY S1)
message("S1 = ${val}")

# 预置属性设置 COMPILE_DEFINITIONS 传递宏变量
set_property(SOURCE main.cpp PROPERTY COMPILE_DEFINITIONS "PARA1=7890")
add_executable(${PROJECT_NAME} main.cpp)

message(----------------------------------------------------)

# cmake 目标属性  目标必须已经存在（上面已经生成）
set_property(TARGET ${PROJECT_NAME} PROPERTY TVAR "tval")
get_property(val TARGET ${PROJECT_NAME} PROPERTY TVAR)
message("TVAR = ${val}")

# 给目标传递宏变量
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA2=\"test_para2\"")
# 直接写会覆盖PARA2
# set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "PARA3=\"test_para3\"")
# 追加宏变量
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS "PARA3=\"test_para3\"")
# 设置宏变量本质是生成命令中加-DPARA2="test_para2"...，只有追加（APPEND）会-DPARA2=... -DPARA3=...，否则就是最后一个生效

message(----------------------------------------------------)

