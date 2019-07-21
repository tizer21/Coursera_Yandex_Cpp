#include <iostream>
#include <map>
#include <string>
#include <vector>

void print_all_buses(const std::map<std::string, std::vector<std::string> >& bus_to_stops) {
    if (bus_to_stops.empty()) {
        std::cout << "No buses" << std::endl;
    } else {
        for (const auto& tmp : bus_to_stops) {
            std::cout << "Bus " << tmp.first << ":";
            for (const auto& stop : tmp.second) {
                std::cout << " " << stop;
            }
            std::cout << std::endl;
        }
    }
}

void print_buses_through_stop(const std::map<std::string, std::vector<std::string> >& stop_to_buses) {
    std::string stop;
    std::cin >> stop;

    if (stop_to_buses.find(stop) == stop_to_buses.end()) {
        std::cout << "No stop" << std::endl;
    } else {
        for (const auto& bus : stop_to_buses.at(stop)) {
            std::cout << bus << " ";
        }
        std::cout << std::endl;
    }
}

void print_change_bus(const std::map<std::string, std::vector<std::string> >& bus_to_stops, 
    const std::map<std::string, std::vector<std::string> >& stop_to_buses) {
    std::string bus;
    std::cin >> bus;

    if (bus_to_stops.find(bus) == bus_to_stops.end()) {
        std::cout << "No bus" << std::endl;
    } else {
        for (const auto& stop : bus_to_stops.at(bus)) {
            std::cout << "Stop " << stop << ":";
            if (stop_to_buses.at(stop).size() == 1) {
                std::cout << " no interchange" << std::endl;
            } else {
                for (const auto& nbus : stop_to_buses.at(stop)) {
                    if (nbus == bus) {
                        continue;
                    }
                    std::cout << " " << nbus;
                }
                std::cout << std::endl;
            }
        }
    }
}

void add_new_bus(std::map<std::string, std::vector<std::string> >& bus_to_stops,
    std::map<std::string, std::vector<std::string> >& stop_to_buses) {
    std::string bus;
    std::cin >> bus;

    int n;
    std::cin >> n;

    std::string stop;
    for (int i = 0; i != n; ++i) {
        std::cin >> stop;
        bus_to_stops[bus].push_back(stop);
        stop_to_buses[stop].push_back(bus);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, std::vector<std::string> > stop_to_buses;
    std::map<std::string, std::vector<std::string> > bus_to_stops;

    std::string request;

    while (n != 0) {
        --n;
        std::cin >> request;
        if (request == "NEW_BUS")
            add_new_bus(bus_to_stops, stop_to_buses);
        if (request == "BUSES_FOR_STOP")
            print_buses_through_stop(stop_to_buses);
        if (request == "STOPS_FOR_BUS")
            print_change_bus(bus_to_stops, stop_to_buses);
        if (request == "ALL_BUSES")
            print_all_buses(bus_to_stops);
    }
}