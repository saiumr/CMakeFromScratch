cmake_minimum_required(VERSION 3.20)
project(install_component)

file(WRITE a.cpp "")
file(WRITE b.cpp "")
file(WRITE doc.html "")

set(CMAKE_INSTALL_PREFIX out)
install(FILES a.cpp b.cpp
DESTINATION src COMPONENT src
)

install(FILES doc.html
DESTINATION doc COMPONENT doc
)

# cmake -S . -B build
# cmake -DCOMPONENT=src -P build/cmake_install.cmake
# cmake -DCOMPONENT=doc -P build/cmake_install.cmake
