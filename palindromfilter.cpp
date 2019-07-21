bool IsPalindrom(std::string& word) {
    for (size_t i = 0; i != word.size() / 2; ++i) {
        if (word[i] != word[word.size() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

std::vector<std::string> PalindromFilter(std::vector<std::string>& words, int minLength) {
    std::vector<std::string> res;
    for (string &word : words) {
        if (IsPalindrom(word) && (int)word.size() >= minLength) {
            res.push_back(word);
        }
    }
    return res;
}