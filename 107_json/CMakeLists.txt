cmake_minimum_required(VERSION 3.20)
project(cmake_json)

message("---------------------------------------")

# 测试使用 json
# json 对象 {}    json 数组 []
# 格式 key:value
set( tjson
[=[
{
    "webs": {
        "web": [
        {
            "name": "cmake",
            "url": "cmake.org.cn"
        },
        {
            "name": "ffmpeg",
            "url": "ffmpeg.club"
        }
        ]
    }
}
]=]
)

message(${tjson})

# 访问webs->web[0]->name
string(JSON var ERROR_VARIABLE evar
        GET ${tjson} webs web 0 name
)
message("webs web 0 name = ${var}")

string(JSON var ERROR_VARIABLE evar
        GET ${tjson} webs web 1 name
)
message("webs web 1 name = ${var}")
message("error evar = ${evar}")            # 无错误发生，NOTFOUND

string(JSON var ERROR_VARIABLE evar
        GET ${tjson} webs non_web 0 name
)
message("webs non_web 0 name = ${var}")    # webs-non_web-NOTFOUND 后缀 NOTFOUND 可以用于if判断
if(NOT non_web)
    message("error evar = ${evar}")
endif()

message("---------------------------------------")

# 获取json长度信息
string(JSON web_count ERROR_VARIABLE evar
        LENGTH ${tjson} webs web
)
message("webs length = ${web_count}")

# json的增加和修改
# 添加webs->web[2]对象，会自动格式化
# 在结尾处增加，使用数组长度变量
string(JSON set_out SET ${tjson} webs web ${web_count} [=[
    {
        "name": "cpp",
        "url": "learncpp.com"
    }
]=])
message("set_out = ${set_out}")

# 修改webs->web[1]
string(JSON set_out2 SET ${set_out} webs web 1 [=[
    {
        "name": "ffmpeg2",
        "url": "ffmpeg2.club"
    }
]=])
message("set_out2 = ${set_out2}")

# json的删除
string(JSON remove_out REMOVE ${set_out2} webs web 0)
string(JSON remove_out REMOVE ${remove_out} webs web 1)
message("remove_out = ${remove_out}")

message("---------------------------------------")
