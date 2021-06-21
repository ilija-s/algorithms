#include <iostream>
#include <vector>

using namespace std;

void add_edge(int u, int v, vector<vector<int>> &graph) {
	graph[u].push_back(v);
}

void transpose_graph(vector<vector<int>> graph, vector<vector<int>> &transposed) {
	int n = graph.size();
	
	for (int i = 0; i < n; i++) {
		for (int v : graph[i]) {
			add_edge(v, i, transposed);
		}
	}
}

void numerate_edges(int u, int &num, vector<int> &marked, vector<bool> visited, vector<vector<int>> graph) {
	marked[++num] = u;
	visited[u] = true;

	for (int v : graph[u]) {
		if (!visited[v]) {
			numerate_edges(v, num, marked, visited, graph);
		}
	}
}

void dfs(int u, vector<bool> &visited, vector<vector<int>> graph) {
	visited[u] = true;
	cout << u << " ";

	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, visited, graph);
		}
	}
}

int main() {
	vector<vector<int>> graph = {
		{1},
		{2},
		{0, 3},
		{4},
		{5, 7},
		{6},
		{4, 7},
		{}
	};

	int n = graph.size();
	int num = -1;

	vector<int> numerated(n, 0);
	vector<bool> visited(n, false);
	vector<vector<int>> transposed(n);

	// numerate all edges by the order that they are visited
	numerate_edges(0, num, numerated, visited, graph);

	// transpose graph
	transpose_graph(graph, transposed);

	for (int i = 0; i < n; i++)
		visited[i] = false;

	// do a dfs on every edge in the order they are visited
	// all edges visited in one dfs are strongly connected
	for (int v : numerated) {
		if (!visited[v]) {
			dfs(v, visited, transposed);
			cout << "\n";
		}
	}

	return 0;
}