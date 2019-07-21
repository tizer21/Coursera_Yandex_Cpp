#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    int sum = 0;
    std::vector<int> data(n);
    for (int& day : data) {
        std::cin >> day;
        sum += day;
    }

    int i = 0;
    std::vector<int> res;
    for (int& day : data) {
        if (day * n > sum) {
            res.push_back(i);
        }
        ++i;
    }

    std::cout << res.size() << std::endl;
    for (int& pos : res) {
        std::cout << pos << ' ';
    }
    std::cout << std::endl;
}
