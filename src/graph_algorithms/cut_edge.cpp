#include <iostream>
#include <vector>

using namespace std;

int cut_edge(int u, int p, int &num, vector<int> &mark, vector<vector<int>> graph) {
	int low = mark[u] = ++num;

	for (int v : graph[u]) {
		if (!mark[v]) {
			int curr_low = cut_edge(v, u, num, mark, graph);

			if (curr_low > mark[u])
				cout << u << " " << v << "\n";

			low = min(low, curr_low);
		} else if (v != p) {
			low = min(low, mark[v]);
		}
	}

	return low;
}

int main() {
	vector<vector<int>> graph = {
		{1},
		{0, 2, 3},
		{1, 4},
		{1, 4},
		{2, 3, 5, 6},
		{4, 6},
		{4, 5, 7},
		{6}
	};

	int n = graph.size();

	vector<int> mark(n);

	int num = -1;

	cut_edge(0, -1, num, mark, graph);

	return 0;
}