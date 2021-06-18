#include <vector>
#include <iostream>

using namespace std;

void add_edge(vector<vector<int>> &adj_list, int u, int v) {
	adj_list[u].push_back(v);
}

vector<int> topsort(vector<vector<int>> &adj_list) {
	int n = adj_list.size();

	vector<int> indeg(n, 0);
	for (vector<int> vertex : adj_list)
		for (int neighbour : vertex)
			indeg[neighbour]++;

	vector<int> q;
	for (int i = 0; i < n; i++)
		if (indeg[i] == 0)
			q.push_back(i);

	for (int i = 0; i < q.size(); i++) {
		int curr = q[i];
		for (int neighbour : adj_list[curr]) {
			indeg[neighbour]--;
			if (indeg[neighbour] == 0)
				q.push_back(neighbour);
		}
	}

	return q;
}

int main() {
	vector<vector<int>> adj_list(6);

	add_edge(adj_list, 1, 3);
	add_edge(adj_list, 2, 3);
	add_edge(adj_list, 2, 4);
	add_edge(adj_list, 5, 4);
	add_edge(adj_list, 0, 1);
	add_edge(adj_list, 5, 0);

	vector<int> sorted = topsort(adj_list);

	for (int v : sorted)
		cout << v << " => ";
	cout << "\n";

	return 0;
}