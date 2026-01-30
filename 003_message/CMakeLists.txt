# cmake 多行注释
#[[
message(arg1 arg2 arg3)
]]

cmake_minimum_required(VERSION 3.20)
project(message)
message("参数1")  # 测试message
message("参数p1" "参数p2" #[[注释在message中]] 123 456 测试)

# message 日志级别
# 进程退出，生成退出
# message(FATAL_ERROR "TEST FATAL_ERROR") # stderr
# 进程继续，生成退出  不会生成add_executable add_library
message(SEND_ERROR "TEST SEND_ERROR") # stderr
add_executable(test_message test_message.cpp)
message("after ERROR")          # stderr
# NOTICE 等同于不加
message(NOTICE "TEST NOTICE")   # stderr
# WARING和ERROR都打印报错行号
message(WARNING "TEST WARNING") # stderr
# STATUS 打印加了"--"前缀
message(STATUS "TEST STATUS")   # stdout

# 下面不同级别都有前缀"--""
# VERBOSE 更详细的日志，默认不显示
message(VERBOSE "TEST VERBOSE") # stdout
# 设置日志显示级别
# cmake -S . -B build --log-level=VERBOSE
message(DEBUG "test DEBUG")
# cmake -S . -B build --log-level=DEBUG
message(TRACE "test TRACE")
# cmake -S . -B build --log-level=TRACE

# 重定向标准输出到文件
# cmake -S . -B build --log-level=VERBOSE > log.txt
# 重定向标准错误输出到文件
# cmake -S . -B build --log-level=VERBOSE > log.txt 2>&1

message("=============================分割线==============================")

# 查找库日志
#[[
CHECK_START 开始记录将要执行检查的消息
CHECK_PASS  记录检查成功结果
CHECK_FAIL  记录检查失败结果
]]

# 开始查找
message(STATUS "开始查找库文件")
message(CHECK_START "查找xcpp")
# 查找库的代码

# 为嵌套查找增加缩进
set(CMAKE_MESSAGE_INDENT "+-")

# 嵌套查找
message(CHECK_START "查找xlog")
# 查找中

# 嵌套查找结果
message(CHECK_PASS "成功")

# 取消缩进
set(CMAKE_MESSAGE_INDENT "")

# 结束查找
message(CHECK_FAIL "失败")
message(STATUS "结束查找库文件")
