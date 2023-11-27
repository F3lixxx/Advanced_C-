#include <iostream>
#include <variant>
#include <windows.h>
#include <string>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::variant<int, std::string> in;

    std::cout << "Write (int or string): ";

    std::string str;
    std::cin >> str;

    try {
        in = std::stoi(str);
    }
    catch (std::invalid_argument) {
        in = str;
    }

    // Вывести значение, независимо от типа
    if (std::holds_alternative<int>(in)) {
        std::cout << "You are written <int>: " << std::get<int>(in) << std::endl;
    }
    else {
        std::cout << "You are written <string>: " << std::get<std::string>(in) << std::endl;
    }

    return 0;
}
