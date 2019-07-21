class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        std::sort(std::begin(strings), std::end(strings));
        return strings;
    }
private:
    std::vector<std::string> strings;
};