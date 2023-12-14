#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string text = "Hello world!!";

    std::map<char, int> count_sym;

    for (char c: text) {
        count_sym[c]++;
    }

    std::vector<std::pair<char, int>> count_symVector(count_sym.begin(), count_sym.end());

    std::sort(count_symVector.begin(), count_symVector.end(),
              [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
                  return a.second > b.second;
              });

    std::cout << "Count symbols:\n";
    for (const auto &pair: count_symVector) {
        std::cout << "'" << pair.first << "': " << pair.second << "\n";
    }

    return 0;
}
