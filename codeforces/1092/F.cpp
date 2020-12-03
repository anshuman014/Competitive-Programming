#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// if ((int)name.size()) {
	// 	freopen((name + ".in").c_str(), "r", stdin);
	// 	freopen((name + ".out").c_str(), "w", stdout);
	// }
}


typedef long long ll;
#define int long long
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

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9;
const ll infinity = 1e18;
vector < vector<int> > g;
vector<bool> vis(MAX);
vector<int> par;
vector<ll> dist;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}

int n;
vector<int> a(MAX);
vector<int> sum(MAX);
int ans = 0, answer;
int total = 0;

void dfs(int v, int d) {
	vis[v] = 1;
	//cout << v;
	ans += a[v] * d;
	sum[v] = a[v];
	for (int u : g[v]) {
		if (!vis[u]) {
			dfs(u, d + 1);
			sum[v] += sum[u];
		}
	}
}

void go(int v, int p) {
	//vis[v] = 1;
	answer = max(ans, answer);
	for (int u : g[v]) {
		if (u == p)
			continue;
		ans += total - 2 * sum[u];
		go(u, v);
		ans -= total - 2 * sum[u];
	}
}

void solve(int tt = 0) {
	//cout << "Case #" << tt << ": ";
	//int n;
	cin >> n;

	for1(i, n + 1) {
		cin >> a[i];
		total += a[i];
	}
	initgraph(n + 5);
	int m = n - 1;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	//cout << total;
	//cout << ans;
	dfs(1, 0);
	answer = ans;
	//memset(vis, 0, sizeof vis);
	go(1, 0);
	cout << answer ;

}

int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	//cin >> T;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}
}