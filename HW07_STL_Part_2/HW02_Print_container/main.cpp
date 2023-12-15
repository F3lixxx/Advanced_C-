#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

template<typename T>
void print_container(T str) {
    typename T::iterator p;
    for (p = str.begin(); p != str.end(); p++) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = {"one", "two", "three", "four"};
    print_container(test_set); // four one three two. помните почему такой порядок? :)

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
    return 0;
}
