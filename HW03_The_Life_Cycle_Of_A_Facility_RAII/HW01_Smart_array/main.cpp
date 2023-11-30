#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int *data;
    int size_;
    int capacity;
public:
    explicit smart_array(int initcap, int initsize) : size_(0),  capacity(initcap) {
        if (initsize > initcap) {
            throw std::invalid_argument("Initial size cannot be greater than capacity");
        }
            data = new int[capacity];
    }

    void add_element(int value) {
        if (size_ < capacity) {
            data[size_] = value;
            size_++;
        } else {
            // Если массив полон, увеличиваем его емкость и копируем элементы
            capacity *= 2;
            int *newData = new int[capacity];
            for (int i = 0; i < size_; ++i) {
                newData[i] = data[i];
            }
            newData[size_] = value;
            size_++;
            delete[] data;
            data = newData;
        }
    }

    void display_arr() {
        for (int i = 0; i < size_; ++i) {
            std::cout << data[i] << " ";
        }
    }
    int get_element(int k) const {
        std::cout << "\nyou are in get_element" << std::endl;

        if (k < 0 || k >= size_) {
            throw std::out_of_range("out of range in get_element");
        }
        return data[k];
    }

    ~smart_array() {
        std::cout << "~smart_array" << std::endl;
        delete[] data;
    }
};

int main() {
    int capacity = 0;
    int initialSize = 0;

    std::cout << "Enter capacity: ";
    std::cin >> capacity;

    std::cout << "Enter initial size: ";
    std::cin >> initialSize;

    try {
        smart_array arr(capacity, initialSize);
        arr.add_element(1);
        arr.add_element(45);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        arr.add_element(65);
        arr.display_arr();
        std::cout << arr.get_element(1) << std::endl;
    } catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
