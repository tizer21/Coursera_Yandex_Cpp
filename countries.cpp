#include <iostream>
#include <string>
#include <map>

void dump_request(std::map<std::string, std::string>& capitals) {
    if (capitals.empty()) {
        std::cout << "There are no countries in the world" << std::endl;
    } else {
        for (const auto &tmp : capitals) {
            std::cout << tmp.first << "/" << tmp.second << " ";
        }
        std::cout << std::endl;
    }
}

void about_request(std::map<std::string, std::string>& capitals) {
    std::string country;
    std::cin >> country;

    if (capitals.find(country) == capitals.end()) {
        std::cout << "Country " << country << " doesn't exist" << std::endl;
    } else {
        std::string capital = capitals[country];
        std::cout << "Country " << country << " has capital " << capital << std::endl;
    }
}

void rename_request(std::map<std::string, std::string>& capitals) {
    std::string old_country_name, new_country_name;
    std::cin >> old_country_name >> new_country_name;

    if (old_country_name == new_country_name ||
            capitals.find(old_country_name) == capitals.end() ||
            capitals.find(new_country_name) != capitals.end()) {
        std::cout << "Incorrect rename, skip" << std::endl;
    } else {
        std::string capital = capitals[new_country_name] = capitals[old_country_name];
        capitals.erase(old_country_name);

        std::cout << "Country " << old_country_name << " with capital " << capital << 
            " has been renamed to " << new_country_name << std::endl;
    }
}

void change_request(std::map<std::string, std::string>& capitals) {
    std::string country, new_capital;
    std::cin >> country >> new_capital;

    if (capitals.find(country) == capitals.end()) {
        capitals[country] = new_capital;

        std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
    } else {
        if (capitals[country] == new_capital) {
            std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
        } else {
            std::string old_capital = capitals[country];
            capitals[country] = new_capital;

            std::cout << "Country " << country << " has changed its capital from " << 
                old_capital << " to " << new_capital << std::endl;
        }
    }
}

void request(std::string& s, std::map<std::string, std::string>& capitals) {
    if (s == "DUMP") {
        dump_request(capitals);
    }
    if (s == "ABOUT") {
        about_request(capitals);
    }
    if (s == "RENAME") {
        rename_request(capitals);
    }
    if (s == "CHANGE_CAPITAL") {
        change_request(capitals);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::map<std::string, std::string> capitals;
    while (n != 0) {
        --n;

        std::cin >> s;
        request(s, capitals);
    }
}