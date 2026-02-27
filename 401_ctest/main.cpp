#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << argc << '\n';
    if (argc <= 1) return -1;
    std::cout << argv[1] << '\n';
    return 0;
}
