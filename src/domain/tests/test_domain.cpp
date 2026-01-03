#include <cassert>
#include <iostream>

#include "domain.hpp"

int main() {
    assert(example_function() == 42);
    std::cout << "Domain logic test passed.\n";
    return 0;
}
