cmake_minimum_required(VERSION 3.20)
project(install_dir)

file(WRITE doc/index.html "")
file(WRITE doc/doc.html "")
file(WRITE doc/doc2.htm "")
file(WRITE doc/doc.cc "")
file(WRITE doc/doc.c "")
file(WRITE doc/sub/doc.html)
file(WRITE doc/include/doc.h)
file(WRITE doc/.git/config)
file(WRITE doc/.svn/config)

# 先指定前缀
# 安装doc目录下所有文件，包含子目录
set(CMAKE_INSTALL_PREFIX out)

# 通过文件类型指定目录
install(DIRECTORY doc TYPE DOC)
install(DIRECTORY doc DESTINATION doc2)

# 过滤只复制*.html *.htm文件  包含子目录  空子目录也创建
install(DIRECTORY doc DESTINATION html_doc
FILES_MATCHING
PATTERN "*.html"
PATTERN "*.htm"
)

# 排除.git .svn 目录
install(DIRECTORY doc DESTINATION no_git_doc
PATTERN ".git" EXCLUDE
PATTERN ".svn" EXCLUDE
)

# 结合过滤方式提取源码文件到src目录
install(DIRECTORY doc DESTINATION src
FILES_MATCHING
PATTERN "*.cc"
PATTERN "*.c"
PATTERN ".git" EXCLUDE
PATTERN ".svn" EXCLUDE
)
