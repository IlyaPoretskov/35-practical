#include <iostream>

int main() {
    std::initializer_list <int> l{1, 2, 3, 4, 5};
    for(auto i : l)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
