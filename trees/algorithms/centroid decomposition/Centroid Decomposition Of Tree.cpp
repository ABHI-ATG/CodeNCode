const int N = 1e5 + 5;
set <int> graph[N];
int parent[N];
int sz[N];
void dfs2(int node, int par) {
	sz[node] = 1;
	for (auto& it : graph[node]) {
		if (it == par) continue;
		dfs2(it, node);
		sz[node] += sz[it];

	}
}
int getCentroid(int node, int par, int currSize) {
	for (auto& it : graph[node]) {
		if (it != par && sz[it] > currSize / 2) return getCentroid(it, node, currSize);
	}
	return node;
}
void dfs1(int node, int par) {
	dfs2(node, 0);
	int currSize = sz[node];
	int centroid = getCentroid(node, par, currSize);
	parent[centroid] = par;
	set <int> children = graph[centroid];
	for (auto& it : children) {
		graph[centroid].erase(it);
		graph[it].erase(centroid);
		dfs1(it, centroid);
	}

}