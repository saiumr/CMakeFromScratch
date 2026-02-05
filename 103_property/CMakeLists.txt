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

