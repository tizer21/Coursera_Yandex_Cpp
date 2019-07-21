#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> data(n);
	for (int& v : data) {
		std::cin >> v;
	}

	std::sort(std::begin(data), std::end(data), [](const int& l, const int& r) {
		return std::abs(l) < std::abs(r);
	});

	for (const int& v : data) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}