void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void Reverse(std::vector<int>& v) {
    for (size_t i = 0; i != v.size() / 2; ++i) {
        Swap(v[i], v[v.size() - 1 - i]);
    }
}