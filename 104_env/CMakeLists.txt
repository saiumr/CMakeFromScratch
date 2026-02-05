cmake_minimum_required(VERSION 3.20)
project(cmake_env)

message("--------------------------------------------")

# 环境变量使用  全局无缓存变量
# 自定义环境变量
set(ENV{MYENV} "test env value")
message("MYENV = $ENV{MYENV}")
add_subdirectory(sub1)
message("SUB1 ENV = $ENV{SUB1ENV}")

# 系统环境变量
# linux中用env列举环境变量
# windows powershell中用gci Env:列举环境变量
message("USER NAME = $ENV{USERNAME}")

message("--------------------------------------------")
