#include <string>
#include <iostream>

#define P 31
#define M 1000000009

using namespace std;

int num(char c) {
	return (int)(c - 'a' + 1);
}

int add(int a, int b) {
	return ((long long)a + b) % M;
}

int sub(int a, int b) {
	return ((long long)M + a - b) % M;
}

int mul(int a, int b) {
	return ((long long)a * b) % M;
}

int pow(int a, int n) {
	int an = 1;
	for (int i = 0; i < n; i++) {
		an = mul(an, a);
	}
	return an;
}

int hash_str(string s) {
	int hash = 0;

	for (char c : s) {
		hash = add(mul(hash, P), num(c));
	}

	return hash;
}

int search(string s, string text) {
	int n = s.size();
	int m = text.size();

	int s_hash = hash_str(s);
	int curr_text = hash_str(text.substr(0, n));

	if (s_hash == curr_text) {
		cout << 0 << " ";
	}

	int p_n = pow(P, n-1);

	for (int i = n; i < m; i++) {
		curr_text = sub(curr_text, mul(p_n, num(text[i - n])));
		curr_text = mul(curr_text, P);
		curr_text = add(curr_text, num(text[i]));

		if (s_hash == curr_text)
			cout << i - n + 1 << " ";
	}
	cout << "\n";
}

int main() {
	string s = "abc";
	string text = "ababcdeababcd";

	search(s, text);

	return 0;
}