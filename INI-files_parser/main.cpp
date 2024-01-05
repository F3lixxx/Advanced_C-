/*#include <iostream>
#include <fstream>

class file{
public:
    file( std::string name = ("out.txt")) : fileName(name){
        std::ifstream file(name);
        if (!file.is_open()) // вызов метода is_open()
            std::cout << "Not Working!" << std::endl;
        else
        {
            std::cout << "Alles Gut!" << std::endl;
        }
    }
private:
    std::string fileName;
};

int main()
{
    //std::ifstream file_in ("out.txt");
    file f;
    return 0;
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<std::string, std::map<std::string, std::string>> readIniFile(const std::string &filename) {
    std::map<std::string, std::map<std::string, std::string>> iniData;
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

                    // Сохраняем данные в std::map
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
    std::string filename = "D:\\ClionProjects\\Advanced_CPP_Programming\\INI-files_parser\\ini_file.ini";
    std::map<std::string, std::map<std::string, std::string>> iniData = readIniFile(filename);

    for (const auto &section: iniData) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (const auto &pair: section.second) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
