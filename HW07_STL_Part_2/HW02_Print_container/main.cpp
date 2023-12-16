#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

template<typename T>
void print_container(T str) {
    auto p = str.cbegin();

    for (p = str.cbegin(); p != str.cend(); p++) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    str.insert(str.cbegin(), "2 10");
    for (p = str.cbegin(); p != str.cend(); p++) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;

    // str.insert(str.cbegin(), 2, "10");
    // for (p = str.cbegin(); p != str.cend(); p++) {
    //     std::cout << *p << " ";
    // }

    std::advance(p, 1);
    std::cout << *p << std::endl;   
    auto found = std::find (str.cbegin(), str.cend(), "two");
    bool is_equal = p == found;
    std::cout << is_equal << ' ';
   // std::cout << std::endl;

    // auto remove = std::remove_if (str.cbegin(), str.cend(),
    // [](const std::string& str) {
    //    return [1] == 'o';
    // })
    // str.erase(remove, str.cend());

}

int main() {
    std::set<std::string> test_set = {"one", "two", "three", "four"};
    print_container(test_set); // four one three two. помните почему такой порядок? :)
    std::cout << std::endl;


    std::list<std::string> test_list = {"one", "two", "three", "four"};
    print_container(test_list);
    std::cout << std::endl;

    std::vector<std::string> test_vector = {"one", "two", "three", "four"};
    print_container(test_vector);
    return 0;
}
