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
