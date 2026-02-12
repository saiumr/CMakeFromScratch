# Cmake from scratch

## 里程碑的配置：206_debug_release

将静态库、动态库和可执行文件输出到设置目录下，配置可跨平台：  

```text
build
    bin
        # 此处是linux下可执行文件输出路径
        # 也是windows下动态库和可执行文件的输出目录
        Debug
        Release
    lib
        # 此处是linux和windows下静态库的输出目录
        # 也是linux下动态库以及windows下导入库的输出目录
        Debug
        Release
```

需要注意的是，linux下`CMAKE_BUILD_TYPE`默认为空，我们需要增加一个默认配置，以防直接运行：  

```bash
cmake -S . -B build
```

我们可以改变Debug/Release：  

```bash
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
```
