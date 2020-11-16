#include "bits/stdc++.h"
using namespace std;
#ifdef ONLINE_JUDGE
#define trace(...)
#endif

using LL = long long;
const int N = 2e5, INF = 1e9 + 100;

vector<int> adj[N];
int a[N], s[N];
bool valid = true;

void dfs(int u, int p) {
	if (s[u] == -1) { // unknown
		int curr = INF;
		for (int v: adj[u]) {
			curr = min(curr, s[v] - s[p]);
		}
		if (curr == INF) {
			curr = 0;
		} 
		if (curr < 0) {
			valid = false;
			return;
		}
		a[u] = curr;
		s[u] = s[p] + a[u];
	} else {
		a[u] = s[u] - s[p];
	}
	for (int v: adj[u]) dfs(v, u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int p; cin >> p; p--;
		adj[p].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	dfs(0, -1);

	LL ans = 0;
	for (int i = 0; i < n; i++) ans += a[i];
	if (!valid) ans = -1;
	cout << ans << endl;

	return 0;
}
