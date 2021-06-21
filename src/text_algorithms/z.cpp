#include <vector>
#include <iostream>

using namespace std;

vector<int> z_alg(string s, string text) {
	s.append("$");
	s.append(text);

	int n = s.size();
	vector<int> z(n);

	int l = 0, d = 0;

	for (int i = 1; i < n; i++) {
		if (i <= d)
			z[i] = min(z[i - l], d - i + 1);

		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;

		if (i + z[i] - 1 > d) {
			l = i;
			d = i + z[i] - 1;
		}
	}

	return z;
}

int main() {
	string str = "ababc";
	string text = "abbacbaababcac";

	vector<int> z = z_alg(str, text);

	for (int i = 0; i < z.size(); i++)
		if (z[i] == str.size())
			cout << i - str.size() - 1 << " ";
	cout << "\n";

	return 0;
}