cmake_minimum_required(VERSION 3.20)
project("cmake_include")
message("begin include")

include("cmake/test_cmake.cmake")  # 直接拷贝过来
include("cmake/test_cmake.cmake")  # 会重复拷贝
include("cmake/test_cmake1.cmake" OPTIONAL)  # OPTIONAL可选，文件不存在不会报错
include("cmake/test_cmake1.cmake" OPTIONAL  RESULT_VARIABLE ret)  # RESULT_VARIABLE 返回值，判断是否引用成功
message("RESULT_VARIABLE ret=${ret}")  # NOT FOUND
include("cmake/test_cmake.cmake" OPTIONAL  RESULT_VARIABLE ret)
message("RESULT_VARIABLE ret=${ret}")  # 打印导入文件的绝对路径

message("end include")
