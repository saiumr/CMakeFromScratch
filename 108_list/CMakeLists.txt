cmake_minimum_required(VERSION 3.20)
project(cmake_list)

message("--------------------------------------")

# cmake的值是纯字符串，列表的形式是用';'隔开两个值，所以我们可以直接传入相同形式创建两个值
set(src "a" "b" "c" "d;e")
message("src = ${src}")

# 计算list长度
list(LENGTH src length)
message("list length = ${length}")

# 在list中追加
list(APPEND src "f")
list(APPEND src "g;h")
list(APPEND src "i" "j")
message("src = ${src}")

# list访问，正向：0,1,2...  逆向：-1，-2，-3...
list(GET src 1 var)
message("GET src 1 = ${var}")
list(GET src -1 var)
message("GET src -1 = ${var}")

# 拼接所有节点：使用别的间隔符号
list(JOIN src "|" var)
message("JOIN ${var}")
list(JOIN src "" var)
message("JOIN ${var}")

# 取其中一部分数组：开始索引 长度
list(SUBLIST src 1 3 var)
message("sublist [1,3) = ${var}")

# 查找内容：返回正向索引
list(FIND src "d" d_index)
message("FIND d = ${d_index}")
# 取某一位置到结尾的数组内容
list(LENGTH src length)
math(EXPR sub_length "${length} - ${d_index}")
list(SUBLIST src ${d_index} ${sub_length} var)
message("sub var = ${var}")

# 插入节点：在节点前面插入
list(FIND src "e" e_index)
list(INSERT src ${e_index} "d")  # 插入d，这时有两个d
message("INSERT src = ${src}")

# 删除和修改节点
# 直接指定删除元素
list(REMOVE_ITEM src "d")        # 删除元素d，会全部删除
message("REMOVE_ITEM src = ${src}")
# 指定索引删除元素
list(REMOVE_AT src 5)
message("REMOVE_AT src 5 = ${src}")
# 重新插入，相当于修改
list(INSERT src 5 "E")
message("RE INSERT src = ${src}")

message("--------------------------------------")

# 双向队列操作方式
list(POP_BACK src var)
message("POP_BACK ${var}")
message("src = ${src}")

# 前端出队 先进先出
list(POP_FRONT src var)
message("POP_FRONT ${var}")
message("src = ${src}")

# 去除重复元素
set(rsrc "g;f;c;d;d;e;c;b;b;a")
message("rsrc = ${rsrc}")
list(REMOVE_DUPLICATES rsrc)
message("REMOVE_DUPLICATES rsrc = ${rsrc}")

# 排序
list(SORT rsrc)
message("SORT rsrc = ${rsrc}")

# 默认字符串排序
set(arr "12;3;64;40;2;83;7;9")
list(SORT arr)
message("SORT arr = ${arr}")
# 使用自然数排序
list(SORT arr COMPARE NATURAL)
message("NATURAL SORT = ${arr}")

message("--------------------------------------")
