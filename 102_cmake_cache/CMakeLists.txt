cmake_minimum_required(VERSION 3.20)
project(cmake_cache)

# 设置缓存变量：变量名 值 字符串类型 说明
set(VAR1 "CACHE VAR1 VALUE1-1 " CACHE STRING "cache doc")
# 缓存变量修改不生效
set(VAR1 "CACHE VAR1 VALUE1-2 " CACHE STRING "cache doc")
message("VAR1 = ${VAR1}")

# 强制修改缓存变量
set(VAR1 "CACHE VAR1 VALUE1-3 " CACHE STRING "cache doc" FORCE)
message("VAR1 = ${VAR1}")

# CACHE变量的作用域是全局的
# 普通变量的作用域在自身和子模块内
set(VAR_NORMAL "test normal")
message("--in main")
message("VAR_NORMAL = ${VAR_NORMAL}")
add_subdirectory(sub1) # 如果在sub1中设置一个变量需要在sub2中使用，就需要缓存变量了
add_subdirectory(sub2)

