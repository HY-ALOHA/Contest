#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MX 100001

using namespace std;

struct Edge {
	int v, u, w;
	Edge() {}
	Edge(int v, int u, int w) :v(v), u(u), w(w) {}
	bool operator< (const Edge &other) {
		return w < other.w;
	}
};

typedef long long ll;

int parent[MX];
vector<Edge> e;

int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u); v = find(v);

	if (u == v)
		return false;

	parent[u] = v;
	return true;
}

int main() {
	int V, E;
	ll ans = 0;
	int edge_count = 0;
	int from, to, w;

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &w);
		e.push_back(Edge(from, to, w));
	}

	sort(e.begin(), e.end());

	for (int i = 0; i < E; i++) {
		if (merge(e[i].u, e[i].v)) {
			edge_count++;
			ans += (ll)(e[i].w);
		}
	}

	ll B; scanf("%lld", &B);
	if (edge_count < V-1 || ans > B) {
		printf("%d\n", -1);
	} else {
		printf("%lld\n", ans);
	}

	return 0;
}
