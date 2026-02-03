cmake_minimum_required(VERSION 3.20)

project("if_judge")

if(TRUE)
    message("1/TRUE/ON is true")
endif()

if(-NOTFOUND)
else()
    message("-NOTFOUNT is false")
endif()

if()
else()
    message("none is false")
endif()

set(VAR1 ON)
if(VAR1)  # defined var
    message("defined var is true")
endif()

unset(VAR1)
if(VAR1)
else()
    message("undefined var is false")
endif()


if("OFF")
else()
    message("string var is false so it is false")
endif()

if("HAPPY")
else()
    message("string var is undefined var so it is false")
endif()

if("999")
    message("number string(not 0) is true")
endif()

set(VAR_OFF OFF)
if(NOT VAR_OFF)   # NOT AND OR
    message("NOT VAR_OFF")
endif()


# if一元、二元比较，正则匹配
# DEFINED EXISTED COMMAND
# EQUAL ...
# MATCHES  正则
set(VAR_DEF OFF)
if(DEFINED VAR_OFF)
    message("DEFINED judge")
endif()

if(1 EQUAL 1)  # 数字比较
    message("EQUAL judge")
endif()
if("happy" STREQUAL "happy")  # 字符串比较
    message("STREQUAL judge")
endif()