std::vector<int> Reversed(const std::vector<int>& v) {
	std::vector<int> res;
	for (size_t i = 0; i != v.size(); ++i) {
		res.push_back(v[v.size() - 1 - i]);
	}
	return res;
}