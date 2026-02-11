#include <iostream>
void A();
void B() {
    A();
    std::cout << "A_VAR in B: " << A_VAR << std::endl;
    #ifndef B_VAR
        std::cout << "cannot find B_AVAR in B lib" << std::endl;
    #endif
}
