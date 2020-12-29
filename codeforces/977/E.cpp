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
int groups[N];
pair<int, int> e[N];
int deg[N];

void dfs(int v, bool &cycle, int par, bool &yes) {
	vis[v] = 1;
	if (deg[v] != 2)
		yes = false;
	for (int u : g[v]) {
		if (!vis[u]) {
			dfs(u, cycle, v, yes);
		}
		else {
			if (u != par)
				cycle = true;
		}
	}
}



void solve() {
	int n, m;
	cin >> n >> m;
	/*for0(i,n+1){
		vis[i]=0;
		g[i].clear();
	}*/
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	int cnt = 0;
	for1(i, n + 1) {
		if (!vis[i]) {
			bool cyc = false;
			bool yes = true;
			dfs(i, cyc, 0, yes);
			if (cyc && yes) {
				cnt++;
				//cyc = false;
			}
		}
	}
	cout << cnt << endl;


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

