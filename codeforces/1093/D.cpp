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

const int MAX = 300001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
vector<int> g[MAX];
int par[MAX];
int col[MAX];
int dist[MAX];
bool vis[MAX];

ll zero = 0, ones = 0;

bool yes = true;

void dfs(int v, int c) {
	if (c == 0)
		zero++;
	else
		ones++;
	col[v] = c;
	vis[v] = 1;
	for (int u : g[v]) {
		if (!vis[u])
			dfs(u, 1 - c);
		else if ( col[u] == col[v]) {
			yes = false;
			return;
		}
	}

}


int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	ll p[MAX];
	p[0] = 1;
	for1(i, MAX) {
		p[i] = (2LL * p[i - 1]) % modulo;
	}

	while (T--) {
		int n, m;
		cin >> n >> m;
		for0(i, n + 1) {
			g[i].clear();
			col[i] = -1;
		}
		for0(i, n + 1) {
			vis[i] = 0;
		}
		while (m--) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll ans = 1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				zero = 0;
				ones = 0;
				yes = true;
				dfs(i, 0);
				if (yes) {
					//cout << ones << " " << zero << endl;
					//(ans += powr(2, ones, modulo) + powr(2, zero, modulo)) %= modulo;
					ll curr = (p[ones] + p[zero]) % modulo;
					ans = (ans * curr) % modulo;
					ans %= modulo;
				}
				else
					break;
			}
		}
		if (yes)
			cout << ans % modulo << endl;
		else
			cout << 0 << endl;

	}
}