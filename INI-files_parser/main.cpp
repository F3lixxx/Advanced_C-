#include <iostream>
#include <fstream>
#include <string>
#include <map>

template<typename KeyType, typename ValueType>
std::map<KeyType, std::map<KeyType, ValueType>> readIniFile(const std::string &filename) {
    std::map<KeyType, std::map<KeyType, ValueType>> iniData;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string currentSection;
        std::string line;

        while (std::getline(file, line)) {
            // Пропускаем пустые строки и комментарии
            if (line.empty() || line[0] == ';') {
                continue;
            }

            // Проверяем, является ли строка секцией
            if (line[0] == '[' && line.back() == ']') {
                currentSection = line.substr(1, line.size() - 2);
            } else {
                // Разделяем строку на ключ и значение
                size_t delimiterPos = line.find('=');
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 1);

                    iniData[currentSection][key] = value;
                }
            }
        }

        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return iniData;
}

int main() {
    auto data = readIniFile<std::string, std::string>("D:\\ClionProjects\\Advanced_CPP_Programming\\INI-files_parser\\ini_file.ini");

    for (const auto& section : data) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (const auto& pair : section.second) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
