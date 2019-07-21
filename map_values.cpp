std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> res;
    for (const auto& tmp : m) {
        res.insert(tmp.second);
    }
    return res;
}