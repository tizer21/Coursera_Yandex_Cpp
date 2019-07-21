#include <iostream>
#include <map>
#include <set>
#include <string>

void request(std::map<std::set<std::string>, int>& buses) {
	int n;
	std::cin >> n;

	std::set<std::string> stops;
	std::string stop;
	while (n != 0) {
		--n;

		std::cin >> stop;
		stops.insert(stop);
	}

	if (buses.count(stops) == 0) {
		int numb = buses.size() + 1;
		buses[stops] = numb;
		std::cout << "New bus " << numb << std::endl;
	} else {
		std::cout << "Already exists for " << buses[stops] << std::endl;
	}
}

int main() {
	int q;
	std::cin >> q;

	std::map<std::set<std::string>, int> buses;
	while (q != 0) {
		--q;

		request(buses);
	}
}