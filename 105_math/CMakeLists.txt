cmake_minimum_required(VERSION 3.20)
project(cmake_math)

set(exp "(3*10) + 5")
math(EXPR out ${exp})
message("${exp} = ${out}")
math(EXPR out ${exp} OUTPUT_FORMAT DECIMAL)      # 十进制打印结果
message("${exp} = ${out}")
math(EXPR out ${exp} OUTPUT_FORMAT HEXADECIMAL)  # 十六进制打印结果
message("${exp} = ${out}")
