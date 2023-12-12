#include <iostream>
#include <vector>
#include <algorithm>

class counter{
public:
    counter() : sum(0), count(0){};

    void operator()(int x) {
        if(x % 3 == 0) {
            ++count;
            sum += x;
        }
    }
    int get_sum() const { return sum; }
    int get_count() const { return count; }

private:
    int sum;
    int count;
};

int main() {
    counter Functor;
    int array [] = {4, 1, 3, 6, 25, 54};
    for (auto mass : array) {
        std::cout << mass << ' ';
    }
    Functor = std::for_each(array, array+sizeof(array)/sizeof(array[0]), Functor);
    std::cout << std::endl;
    std::cout <<  Functor.get_sum() << ' ' << std::endl;
    std::cout <<  Functor.get_count() << ' ' << std::endl;
    return 0;
}
