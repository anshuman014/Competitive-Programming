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
#define int long long
#define pb push_back
#define endl "\n"
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<n;i++)
#define ps(x,y) fixed << setprecision(y) << x

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

using pi = pair<int, int>;
//#define f first
//#define s second
//#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9 + 5;
const ll infinity = 1e18;

const int N = 2e5 + 5;
vector<int> g[N];
int vis[N];
pair<int, int> e[N];

int n, m;
vector<int> a(N);
int ans = 0;

void dfs(int v, int par, int curr) {
	vis[v] = 1;
	if (a[v] == 1)
		curr++;
	else
		curr = 0;
	if (curr > m)
		return;

	for (int u : g[v]) {
		if (!vis[u]) {
			dfs(u, v, curr);
		}
	}
	if (sz(g[v]) == 1 && v != 1) {
		ans++;
	}


}


void solve() {
	cin >> n >> m;
	int edge = n - 1;
	for1(i, n + 1) {
		cin >> a[i];
	}

	while (edge--) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int curr = 0;
	dfs(1, 0, curr);
	cout << ans << endl;

}




int32_t main() {

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

