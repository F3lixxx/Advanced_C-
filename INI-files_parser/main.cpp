#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

template<typename T>
class ini_parser{
    public:

    private:

};

int main() {
    ini_parser parser ("D:\\ClionProjects\\Advanced_CPP_Programming\\INI-files_parser\\ini_file.ini");
    auto value = parser.get_value<int>(section.value);
    return 0;
}
