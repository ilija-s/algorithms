#include <vector>
#include <iostream>

using namespace std;

vector<int> manacher(string s) {
	int n = s.size();
	vector<int> r(n, 1);

	int l = 0, d = 0;

	for (int i = 1; i < n; i++) {
		if (i <= d)
			r[i] = min(r[d - i + l], d - i + 1);

		while(i - r[i] >= 0 && i + r[i] < n && s[i-r[i]] == s[i + r[i]])
			r[i]++;

		if (i + r[i] - 1 > d) {
			l = i - r[i] + 1;
			d = i + r[i] - 1;
		}
	}

	return r;
}

int main() {


	return 0;
}