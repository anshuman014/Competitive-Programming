#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


typedef long long ll;
#define pb push_back
#define endl "\n"
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<n;i++)
#define ps(x,y) fixed << setprecision(y) << x

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
//vector<int> par(MAX);
int dist[MAX];
bool vis[MAX];
vector<int> rank(MAX);
int subtree[MAX];
int ans = 0;

void dfs(int v, int par) {
	subtree[v] = 1;
	for (int u : g[v]) {
		if (u == par)
			continue;
		dfs(u, v);
		subtree[v] += subtree[u];
	}
}


void solve() {
	int n;
	cin >> n;
	int m = n - 1;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	bool yes = false;
	for (int i = 1; i <= n; i++) {
		if (subtree[i] > 0 && subtree[i] % 2 == 0) {
			yes = true;
			ans++;
		}
	}
	if (!yes || n%2){
		cout << -1 << endl;
		return;
	}

	cout << ans - 1;
}




int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}