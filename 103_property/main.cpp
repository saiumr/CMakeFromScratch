#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Test cmake property" << std::endl;
    std::cout << PARA1 << std::endl;  // cmake 文件属性传递的宏
    return 0;
}