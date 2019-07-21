#include <iostream>
#include <map>
#include <string>
#include <vector>

void request(std::map<std::vector<std::string>, int>& buses) {
    int n;
    std::cin >> n;

    std::vector<std::string> stops(n);
    for (auto& stop : stops) {
        std::cin >> stop;
    }

    if (buses.count(stops) == 0) {
        int numb = buses.size() + 1;
        buses[stops] = numb;

        std::cout << "New bus " << numb << std::endl;
    } else {
        int numb = buses[stops];

        std::cout << "Already exists for " << numb << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::map<std::vector<std::string>, int> buses;
    while (n != 0) {
        --n;

        request(buses);
    }
}