#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void add_edge(vector<vector<int>> &adj_list, int u, int v) {
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

bool is_bipartite(vector<vector<int>> adj_list, vector<int> &colors) {
	queue<int> q;
	q.push(0);

	colors[0] = 1;
	int color;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (colors[curr] == 1)
			color = 2;
		else
			color = 1;

		for (int neighbour : adj_list[curr]) {
			if (colors[neighbour] == 0) {
				colors[neighbour] = color;
				q.push(neighbour);
			} else if (colors[neighbour] == color) {
				continue;
			} else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	vector<vector<int>> adj_list = {
		{1, 3},
		{0, 2},
		{1, 3},
		{0, 2}
	};
	int n = adj_list.size();
	vector<int> colors(n, 0);	

	if (is_bipartite(adj_list, colors)) {
		cout << "True\n";
		for (int x : colors) {
			cout << x << " ";
		}
		cout << '\n';
	} else {
		cout << "false\n";
		for (int x : colors) {
			cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}
