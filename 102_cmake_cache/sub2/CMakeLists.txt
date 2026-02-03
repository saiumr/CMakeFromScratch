cmake_minimum_required(VERSION 3.20)
project(sub2)
message("--in sub2")
message("VAR1 = ${VAR1}")
message("VAR_NORMAL = ${VAR_NORMAL}")

if(NOT DEFINED VAR2_NORMAL)
    message("cannot find VAR2_NORMAL in sub2")
endif()

if(DEFINED VAR2_CACHE)
    message("VAR2_CACHE = ${VAR2_CACHE}")
endif()

message("out sub2--")