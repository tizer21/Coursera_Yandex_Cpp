#include <map>
#include <string>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }
    
    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }

    std::string GetFullName(int year) {
        auto iter_first_name = GetIterFirstName(year);
        auto iter_last_name = GetIterLastName(year);

        if (iter_first_name == first_names.end()) {
            if (iter_last_name == last_names.end()) {
                return "Incognito";
            } else {
                return iter_last_name->second + " with unknown first name";
            }
        } else {
            if (iter_last_name == last_names.end()) {
                return iter_first_name->second + " with unknown last name";
            } else {
                return iter_first_name->second + " " + iter_last_name->second;
            }
        }
    }

    std::string GetFullNameWithHistory(int year) {
        auto first_names_in_period = GetFirstNameWithHistory(year);
        auto last_names_in_period = GetLastNameWithHistory(year);

    }

private:
    std::map<int, std::string> first_names, last_names;
    
    const std::map<int, std::string>::const_iterator GetIterByYear(const std::map<int, std::string>& m, int year) {
        if (m.empty()) {
            return m.end();
        }
        auto iter = m.upper_bound(year);
        if (iter == m.begin()) {
            return m.end();
        } else {
            return --iter;
        }
    }
    
    const std::map<int, std::string>::const_iterator GetIterFirstName(int year) {
        return GetIterByYear(first_names, year);
    }
    
    const std::map<int, std::string>::const_iterator GetIterLastName(int year) {
        return GetIterByYear(last_names, year);
    }

    const std::vector<std::string> GetNameWithHistory(const std::map<int, std::string>& m, int year) {
        std::vector<std::string> res;
        for (const auto& tmp : m) {
            if (tmp.first)
        }
    }    

    const std::vector<std::string> GetFirstNameWithHistory(int year) {
        
    }
};