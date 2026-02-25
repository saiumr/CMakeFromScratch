cmake_minimum_required(VERSION 3.20)
project(install_file)

file(WRITE a.h "")
file(WRITE b.h "")

# 文件安装到指定目录
set(CMAKE_INSTALL_PREFIX out)
install(FILES a.h b.h DESTINATION include)  # 和Debug Release无关

# 目标可选 文件不存在不报错（下面的inc会创建，但目录下为空）
install(FILES c.h DESTINATION inc OPTIONAL)

# 根据类型自动分类
# 文件类型  TYPE DOC LIB INCLUDE
include(GNUInstallDirs)  # 引用此头文件才能看到下面的变量值
message("CMAKE_INSTALL_DATAROOTDIR = ${CMAKE_INSTALL_DATAROOTDIR}")
install(FILES a.h TYPE DOC)        # <DATAROOT dir>/doc
install(FILES b.h TYPE LIB)        # lib
install(FILES c.h TYPE INCLUDE)    # include

# 文件权限  window目录无效
# 不想写了...事无巨细啊
install(FILES a.h DESTINATION pub
PERMISSIONS
OWNER_READ OWNER_WRITE OWNER_EXECUTE
GROUP_READ GROUP_WRITE GROUP_EXECUTE
WORLD_READ WORLD_WRITE WORLD_EXECUTE
)
