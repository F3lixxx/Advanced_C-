#include <iostream>
#include <vector>
#include <iterator>


int main() {
    int size;
    int numbers;
    std::cin >> size;
    std::vector<int> vec;
    for (int i = 0; i < size; i++) {
        std::cin >> numbers;
        vec.push_back(numbers);
    }
    for (auto &p: vec) {
        if (p % 2 != 0)
            p *= 3;
    }
    std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}

/*
#include <iostream>
#include <iterator>

int main(){
    int a[] = { 20, 1, 7, 3, 5, 2, 4, 6, 11 };

    for(auto& x : a){
        if((x % 2) == 0)
            x *= x;
        else
            x *= 2;
    }
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}*/
