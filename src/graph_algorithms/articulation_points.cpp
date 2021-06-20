#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, int p, int &num, vector<int> &mark, vector<vector<int>> graph) {
	int low = mark[u] = ++num;
	int count = 0;
	bool articulation_point = false;

	for (int v : graph[u]) {
		if (!mark[v]) {
			int curr_low = dfs(v, u, num, mark, graph);

			if (p != -1 && curr_low >= mark[u])
				articulation_point = true;

			low = min(low, curr_low);
				
			count++;	
		} else if (v != p) {
			low = min(low, mark[v]);
		}
	}

	if (articulation_point || (p == -1 && count > 1))
		cout << u << " ";

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

	dfs(0, -1, num, mark, graph);

	cout << "\n";

	return 0;
}