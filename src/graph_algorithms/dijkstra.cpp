#include <vector>
#include <iostream>
#include <set>

using namespace std;

using edge = pair<int, int>;

void add_edge(int u, int v, int w, vector<vector<edge>> &graph) {
	graph[u].push_back({v, w});
	graph[v].push_back({u, w});
}

void dijkstra(int u, vector<int> &distance, vector<int> &parent, vector<vector<edge>> graph) {
	set<edge> pq;
	pq.insert({distance[u] = 0, u});

	while(!pq.empty()) {
		int v = pq.begin()->second;
		pq.erase(pq.begin());

		for (edge e : graph[v]) {
			int t = e.first;
			int w = e.second;

			if (distance[v] + w < distance[t]) {
				pq.erase({distance[t], t});
				distance[t] = distance[v] + w;
				parent[t] = v;
				pq.insert({distance[t], t});
			}
		}
	}	
}

int main() {
	vector<vector<edge>> graph(6);
	int n = graph.size();

	add_edge(0, 3, 1, graph);
	add_edge(3, 2, 2, graph);
	add_edge(3, 1, 4, graph);
	add_edge(2, 0, 2, graph);
	add_edge(2, 1, 1, graph);
	add_edge(2, 4, 4, graph);
	add_edge(2, 5, 17, graph);
	add_edge(4, 5, 1, graph);

	vector<int> distance(n, INT32_MAX);
	vector<int> parent(n, -1);

	dijkstra(0, distance, parent, graph);

	int i = 0;
	for (int x : distance)
		cout << "From node 0 to node " << i++ << ": " << x << endl;

	return 0;
}