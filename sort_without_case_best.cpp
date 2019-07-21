#include <algorithm>
#include <locale>
#include <iostream>
#include <string>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::string> data(n);
	for (auto& v : data) {
		std::cin >> v;
	}

	std::sort(std::begin(data), std::end(data), [](const std::string& l, const std::string& r) {
		return lexicographical_compare(begin(l), end(l), begin(r), end(r), [](const char l, const char r) {
			return std::tolower(l) < std::tolower(r);
		});
	});

	for (const auto& v : data) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}