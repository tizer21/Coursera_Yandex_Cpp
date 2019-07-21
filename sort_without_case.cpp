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
		std::string tmp1(l.size(), ' '), tmp2(r.size(), ' ');
		std::transform(std::begin(l), std::end(l), std::begin(tmp1), [](const unsigned char c) {
			return std::tolower(c);
		});
		std::transform(std::begin(r), std::end(r), std::begin(tmp2), [](const unsigned char c) {
			return std::tolower(c);
		});
		return tmp1 < tmp2;
	});

	for (const auto& v : data) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}