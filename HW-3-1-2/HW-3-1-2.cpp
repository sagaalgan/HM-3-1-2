#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <cstdlib>
#include <ctime>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable) {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main() {
    std::variant<int, std::string, std::vector<int>> result = get_variant();

    if (std::holds_alternative<int>(result)) {
        int value = std::get<int>(result);
        std::cout << "Integer value doubled: " << (value * 2) << std::endl;
    }
    else if (std::holds_alternative<std::string>(result)) {
        std::string value = std::get<std::string>(result);
        std::cout << "String value: " << value << std::endl;
    }
    else if (std::holds_alternative<std::vector<int>>(result)) {
        std::vector<int> value = std::get<std::vector<int>>(result);
        std::cout << "Vector values: ";
        for (int num : value) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}