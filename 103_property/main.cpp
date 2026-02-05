#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Test cmake property" << std::endl;
    #ifdef PARA1
    std::cout << "PARA1 = " << PARA1 << std::endl;  // cmake 文件属性传递的宏
    #endif

    #ifdef PARA2
    std::cout << "PARA2 = " << PARA2 << std::endl;  // cmake 目标属性传递的宏
    #endif
    
    #ifdef PARA3
    std::cout << "PARA3 = " << PARA3 << std::endl;  // cmake 目标属性传递的宏
    #endif
    
    return 0;
}