#include <iostream>
#include <set>
#include <algorithm>

struct Shorterint {
    bool operator()(const int & a, const int& b) const {
        return a > b;
    }
};

int main() {
    int count;
    int num;
    std::set<int, Shorterint> number;
    std::cout << "[IN]" << std::endl;
    std::cin >> count;

    for (int i = 0; i < count; i++) {
       std::cin >> num;
       number.insert(num);
    }

    std::cout << "[OUT]" << std::endl;
    for (auto el: number) {
        std::cout << el << std::endl;
    }
    return 0;
}
