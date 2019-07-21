#include <iostream>
#include <string>
#include <vector>

void parse(int& month, std::vector<std::vector<std::string> >& days) {
    const std::vector<int> count = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::string s;
    std::cin >> s;
    if (s == "NEXT") {
        size_t prev = count[(month++) % 12];
        size_t now = count[month % 12];

        if (now < prev) {
            for (size_t i = now; i != prev; ++i) {
                days[now - 1].insert(end(days[now - 1]), begin(days[i]), end(days[i]));
            }
        }
        days.resize(now);
    }
    if (s == "ADD") {
        int day;
        std::string concern;
        std::cin >> day >> concern;

        days[--day].push_back(concern);
    }
    if (s == "DUMP") {
        int day;
        std::cin >> day;

        std::cout << days[--day].size();
        for (auto & concern : days[day]) {
            std::cout << " " << concern;
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    int month = 0;
    std::vector<std::vector<std::string> > days(31);
    while (n > 0) {
        --n;
        parse(month, days);
    }

    return 0;
}