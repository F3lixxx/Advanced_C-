#include <iostream>
#include <algorithm>
#include <vector>

void uniq(std::vector<int>& mas){
    {
        auto end = mas.end();
        for (auto it = mas.begin(); it != end; ++it) {
            end = std::remove(it + 1, end, *it);
        }

        mas.erase(end, mas.end());
    }
}

int main() {
    std::vector<int> arr = {1, 1, 2, 5, 6, 1, 2, 4};
    uniq(arr);
    std::sort(arr.begin(), arr.end());
    //arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    for(auto el : arr){
        std::cout << el << ' ';
    }
    return 0;
}
