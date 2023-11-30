#include <iostream>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(time(nullptr));
    int random_variable = std::rand() % 3;


    std::variant<int, std::string, std::vector<int>> result = {1, 2, 3};
    switch (random_variable) {
        case 0:
            result = 5;
            break;
        case 1:
            result = "string";
            break;
        case 2:
            result = std::vector<int>{1, 2, 3, 4, 5};
            break;
        default:
            break;
    }
    return result;
}

int main() {
    auto value = get_variant();
    std::string strings;
    std::vector<int> vec;
    std::cin >> vec;
    get_variant() = vec;

    std::cout << "Write (int or string): ";
    if (std::holds_alternative<int>(value)) {
        std::variant<int, std::string, std::vector<int>> number = get_variant();
        std::cin >> number;
        get_variant() = number;
        std::cout << "It is int: " << std::get<int>(value) << std::endl;
    } else if (std::holds_alternative<std::string>(value)) {
        std::variant<int, std::string, std::vector<int>> value = get_variant();
        std::cin >> strings;
        get_variant() = strings;
        std::cout << "It is string : " << std::get<std::string>(value) << std::endl;

    } else if (std::holds_alternative<std::vector<int>>(value)) {
        std::vector<int> vec = get_variant();
        std::cin >> vec;
        get_variant() = vec;
        std::cout << "It is vector<int>: ";
        for (int i: std::get<std::vector<int>>(value)) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
