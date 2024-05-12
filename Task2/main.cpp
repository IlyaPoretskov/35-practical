#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>

auto Function = [](const std::vector<int>& Vec) {
    std::unordered_set<int> Array;
    auto UniqVector = std::make_unique<std::vector<int>>();
    for (const auto &i : Vec) {
        if (Array.insert(i).second) {
            UniqVector->push_back(i);
        }
    }
    return UniqVector;
};

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> vec = {1, 1, 6, 3, 56, 45, 3, 6, 1};
    auto UniqVector = Function(vec);
    std::cout << "Vector: ";
    for (const auto &i : *UniqVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
