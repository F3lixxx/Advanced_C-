#include <iostream>

template<class T>
class table {
public:
    table(T row, T col) : rows(row), cols(col) {
        arr = new T *[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = i + 1;
            }
        }
    }

    T *operator[](int index) { return arr[index]; };

    const T *operator[](int index) const { return arr[index]; };

    ~table() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    friend std::ostream &operator<<(std::ostream &os, table &table) {
        for (int i = 0; i < table.rows; ++i) {
            for (int j = 0; j < table.cols; ++j) {
                os << table.arr[i][j] << '\t';
            }
            os << '\n';
        }
        return os;
    }

    T size() const {
        return rows * cols;
    }

private:
    int rows;
    int cols;
    int **arr{};
};


int main() {
    int rows;
    int cols;

    auto test = table<int>(5, 3);

    test[0][0] = 4;
    std::cout << test << std::endl;
    std::cout << test[rows][cols] << std::endl;
    std::cout << test[0][0] << std::endl;
    std::cout << test.size();
    return 0;
}
