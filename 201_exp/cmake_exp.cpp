#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "cmake_exp test" << std::endl;

    #ifdef TEST1
        std::cout << "TEST1: " << TEST1 << std::endl;
    #endif

    #ifdef TEST2
        std::cout << "TEST2: " << TEST2 << std::endl;
    #endif

    return 0;
}