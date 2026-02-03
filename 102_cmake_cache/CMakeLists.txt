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


message("-----------------------------------------")
set(VAR_BOOL1 "ON" CACHE BOOL "VAR bool 001")
set(VAR_BOOL2 "OFF" CACHE BOOL "VAR bool 002")
message("VAR_BOO1 = ${VAR_BOOL1}")
message("VAR_BOO2 = ${VAR_BOOL2}")
set(VAR_FILE "FILEPATH" CACHE FILEPATH "var FILEPATH")      # 文件选择
set(VAR_PATH "FILEPATH" CACHE PATH "var PATH")              # 目录选择
set(VAR_INTERNAL "INTERNAL" CACHE INTERNAL "var INTERNAL")

option(OPT1 "opt1 doc" OFF)
option(OPT2 "opt2 doc" ON)

# 使用cmake-gui配置变量
# ccmake build 控制台配置缓存变量或者可选(option)变量  windows上似乎没有


message("-----------------------------------------")
# CACHE覆盖策略设置
set(NVAR1 "normal var1")

# 设置缓存变量覆盖同名变量的策略
# OLD 删除同名普通变量
# NEW 不删除普通变量，要访问cache要用$CACHE{var_name}
cmake_policy(SET CMP0126 NEW) # OLD NEW，默认OLD

set(NVAR1 "cache var1" CACHE STRING "cache doc")


message("NVAR1 = ${NVAR1}")
message("CACHE NVAR1 = $CACHE{NVAR1}")
