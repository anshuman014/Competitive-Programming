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
//#define int long long
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
const ll modulo = 998244353;
//const int inf = 1e15;
const ll infinity = 1e18;
//vector < pair<int, int>> g;
vector<int> vis;
vector<int> par;
vector<ll> dist;


/*void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}
*/

const int N = int(1e6) + 55;

int n, m;
vector <pair<int, int> > g[N];
int col[5005], res[5005];
bool cyc = false;

void dfs(int v) {
	col[v] = 1;
	for (auto x : g[v]) {
		int a = x.f, b = x.s;
		if (col[a] == 0) {
			dfs(a);
			res[b] = 1;
		}
		else if (col[a] == 2) {
			res[b] = 1;
		}
		else {
			res[b] = 2;
			cyc = true;
		}
	}
	col[v] = 2;
}

void solve() {

	cin >> n >> m;
	//initgraph(n);
	for0(i, m) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].pb({y, i});
	}
	for0(i, n ) {
		if (col[i] == 0) {
			dfs(i);
		}
	}
	cout << (cyc ? 2 : 1) << endl;
	for0(i, m) cout << res[i] << " ";

}



int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	///cin >> T;

	while (T--) {
		solve();
	}
}