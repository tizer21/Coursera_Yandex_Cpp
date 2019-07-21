#include <iostream>
#include <map>
#include <set>

void add_request(std::map<std::string, std::set<std::string> >& synonims) {
    std::string word1, word2;
    std::cin >> word1 >> word2;

    synonims[word1].insert(word2);
    synonims[word2].insert(word1);
}

void count_request(const std::map<std::string, std::set<std::string> >& synonims) {
    std::string word;
    std::cin >> word;

    if (synonims.count(word) != 0) {
        std::cout << synonims.at(word).size() << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

void check_request(const std::map<std::string, std::set<std::string> >& synonims) {
    std::string word1, word2;
    std::cin >> word1 >> word2;

    if (synonims.count(word1) != 0) {
        std::cout << (synonims.at(word1).count(word2) != 0 ? "YES" : "NO") << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::string request;
    std::map<std::string, std::set<std::string> > synonims;

    while (n != 0) {
        --n;

        std::cin >> request;
        if (request == "ADD") {
            add_request(synonims);
        }
        if (request == "COUNT") {
            count_request(synonims);
        }
        if (request == "CHECK") {
            check_request(synonims);
        }
    }
}