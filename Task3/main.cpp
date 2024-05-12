#include <iostream>
#include <vector>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

auto recursiveGetFileNamesByExtension = [](const fs::path& path, const std::string& extension) -> std::vector<std::string> {
    std::vector<std::string> fileNames;
    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto& entry : fs::recursive_directory_iterator(path)) {
            if (entry.is_regular_file() && entry.path().extension() == extension) {
                fileNames.push_back(entry.path().string());
            }
        }
    }
    return fileNames;
};

int main() {
    std::string path;
    std::string extension;

    std::cout << "Enter the directory path: ";
    std::cin >> path;
    std::cout << "Enter the file extension (include the dot, e.g., '.txt'): ";
    std::cin >> extension;

    auto fileNames = recursiveGetFileNamesByExtension(path, extension);
    for (const auto& fileName : fileNames) {
        std::cout << fileName << std::endl;
    }

    return 0;
}
