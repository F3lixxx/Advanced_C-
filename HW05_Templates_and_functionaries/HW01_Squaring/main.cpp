#include <iostream>
#include <vector>
#include <cmath>

template<class square>
square squaring(square number) {
    return pow(number, 2);
}

template <>
std::string squaring(std::string a){
    return a;
}

template<class square>
std::vector<square> squaring(std::vector<square> &number) {
    std::vector<square> result;
    for (square element : number) {
        result.push_back(square(element * element));
    }
    return result;
}



int main() {
    std::string str = "watching how to work template<> ";
    std::cout << squaring(str) << std::endl;

    int num = 4;
    std::cout << "[IN]:" << num << std::endl;
    std::cout << "[OUT]:" << squaring(num) << std::endl;



    std::vector<int> numbers = {-1, 4, 8};
    std::cout << "[IN]:";
    for(auto element : numbers) {
        std::cout << element << ' ';
    }

    std::cout << "\n[OUT]: ";
    for (int number : squaring(numbers)) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
