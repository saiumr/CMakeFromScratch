cmake_minimum_required(VERSION 3.20)
project(cmake_macro)

message("----------------------------------------")

macro(my_macro)
    message("in my macro")
    set(RET 1)
endmacro()

# 宏名称大小写不敏感，尽量只用小写
# cmake的宏调用是将宏代码复制过来
my_macro()
My_mAcrO()
message("RET = ${RET}")

message("----------------------------------------")

# [传递宏参数，固定数量形参]
macro(foo arg1 arg2)
    message("arg1 = ${arg1}, arg2 = ${arg2}")
    if(arg1)
        message("-> arg1 is TRUE <-")  # 此句不会打印，因为宏参数不是变量，不能用于判断什么的
    endif()

    if(${arg1})  # 只能用来取值<-只能用它的值做些什么事
        message("-> $\{arg1\} is TRUE <-")
    endif()
endmacro()

foo(TRUE hello)

message("----------------------------------------")

# [不固定数量形参]
set(argn_list "")
macro(foo2)
    message("ARGC = ${ARGC}")

    # ARGN 不是变量，只能取值使用
    # 使用ITEMS对内容遍历
    foreach(var IN ITEMS ${ARGN})
        string(APPEND argn_list ${var} " ")
    endforeach()
    
    message("argn_list = ${argn_list}")
    
    # 直接用索引取值
    message("ARGV0 = ${ARGV0}")
    message("ARGV1 = ${ARGV1}")
    message("ARGV2 = ${ARGV2}")
    message("ARGV3 = ${ARGV3}")
endmacro()

foo2("My" "name" "is" "Lee.")

message("----------------------------------------")

# [宏传递属性类]
macro(my_parse)
    message("ARGN = ${ARGN}")
    cmake_parse_arguments(
        "MY"        # 前缀
        "LOG;FILE"  # option
        "BIN;LIB"   # 单值
        "TARGETS"   # 多值
        ${ARGN}     # 参数数组
    )
    message("MY_LOG = ${MY_LOG}")
    message("MY_FILE = ${MY_FILE}")
    message("MY_BIN = ${MY_BIN}")
    message("MY_LIB = ${MY_LIB}")
    message("MY_TARGETS = ${MY_TARGETS}")

    # 打印传入parse中错误的参数，注意加上前缀
    message("MY_UNPARSED_ARGUMENTS = ${MY_UNPARSED_ARGUMENTS}")

    # 打印没有传值的变量
    message("MY_KEYWORDS_MISSING_VALUES = ${MY_KEYWORDS_MISSING_VALUES}")
    
endmacro()

my_parse(
    "hello"
    LOG
    BIN "../../bin"
    LIB
    TARGETS "tar1" "tar2"
)

message("----------------------------------------")
