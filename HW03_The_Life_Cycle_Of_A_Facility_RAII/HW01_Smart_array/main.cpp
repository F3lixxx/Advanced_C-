#include <iostream>
#include <vector>

class smart_array{
private:
    int *mass;
public:
    int size;
    smart_array(int size) : size(size){
        mass = new int [size];
        std::cout << size << std::endl;
    }

    ~smart_array() {
        delete[] mass;
    }
};

int main() {
    int size = 0;
    std::cin >> size;
    smart_array arr (size);
    //system("pause");
    return 0;
}