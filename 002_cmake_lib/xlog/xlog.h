#pragma once

#include <iostream>

// window下动态库调用需要.lib(函数地址索引，索引到dll中，这个文件只是名称和静态库相同)和.dll(函数二进制代码)
// 引用动态库需要用__declspec(dllexport)导出和__declspec(dllexport)导入

// __declspec(dllexport)
// 导出XLog类的函数到lib文件中
// xlog库文件调用 dllexport（生成）
// test_xlog 调用 dllimport（使用）
// 可以使用宏区分是生成库文件还是使用库文件

#ifndef _WIN32
    #define XCPP_API
#else
    #ifdef xlog_EXPORTS
        #define XCPP_API __declspec(dllexport)    // 库项目调用
    #else
        #define XCPP_API __declspec(dllimport)    // 调用库项目调用
    #endif
#endif
class XCPP_API XLog {
public:
    XLog();
};


