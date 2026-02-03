#include <iostream>
#include "xlog.h"
#include "xthread.hpp"

int main() {
    std::cout << "Test cmake auto source/head found" << std::endl;
    
    xlog();
    xthread();
    
    return 0;
}
