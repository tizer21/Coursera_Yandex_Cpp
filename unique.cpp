#include <iostream>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string t;
    std::set<std::string> s;

    while (n != 0) {
        --n;
        std::cin >> t;
        s.insert(t);
    }

    std::cout << s.size() << std::endl;
}