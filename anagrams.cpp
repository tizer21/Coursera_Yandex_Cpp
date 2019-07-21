#include <iostream>
#include <map>

bool is_anagrams(std::string &s, std::string &t) {
    std::map<char, int> count_in_s, count_in_t;

    for (const char c : s) {
        ++count_in_s[c];
    }
    for (const char c : t) {
        ++count_in_t[c];
    }

    if (count_in_s.size() != count_in_t.size()) {
        return 0;
    }
    for (const auto &tmp: count_in_s) {
        if (count_in_t[tmp.first] != tmp.second) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    std::cin >> n;
    while (n != 0) {
        --n;

        std::string s, t;
        std::cin >> s >> t;
    
        if (is_anagrams(s, t)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}