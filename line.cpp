#include <iostream>
#include <string>
#include <vector>

void parse(const std::string& s, const int k, std::vector<bool>& line, int& count) {
    if (s == "COME") {
        if (k < 0) {
            for (size_t i = 0; i != (size_t)-k; ++i) {
                if (line[line.size() - 1 - i]) {
                    --count;
                }
            }
        }
        line.resize((int)line.size() + k);
    }
    if (s == "QUIET") {
        if (line[k]) {
            line[k] = 0;
            --count;
        }
    }
    if (s == "WORRY") {
        if (!line[k]) {
            line[k] = 1;
            ++count;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::string s;
    int k;

    std::vector<bool> line;
    int count = 0;

    while (n > 0) {
        --n;

        std::cin >> s;
        if (s == "WORRY_COUNT") {
            std::cout << count << std::endl;
        } else {
            std::cin >> k;
            parse(s, k, line, count);
        }
    }

    return 0;
}