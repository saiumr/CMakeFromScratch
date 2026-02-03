cmake_minimum_required(VERSION 3.20)
project(sub1)
message("--in sub1")
message("VAR1 = ${VAR1}")
message("VAR_NORMAL = ${VAR_NORMAL}")

set(VAR2_NORMAL "DEFINED")
set(VAR2_CACHE "CACHE VAR2 " CACHE STRING "cache doc")

message("VAR2_NORMAL = ${VAR2_NORMAL}")
message("VAR2_CACHE = ${VAR2_CACHE}")

message("out sub1--")