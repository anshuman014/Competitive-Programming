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

const int MAX = 200001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e15;
const ll infinity = 1e18;
vector < vector<int> >g;
vector<int> vis;
vector<int> par;
vector<ll> dist;


void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}
vector<int> a, b;
int dp[2005][1005];
int n, k, p;



void solve() {

	cin >> n >> k >> p;
	a.resize(n);
	b.resize(k);
	for0(i, n) cin >> a[i];
	for0(i, k) cin >> b[i];
	sort(all(a));
	sort(all(b));
	for (int i = 0; i < k + 4; i++) {
		for (int j = 0; j < n + 4; j++) {
			dp[i][j] = inf;
		}
	}

	dp[0][0] = 0;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (j < n)
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[j] - b[i]) + abs(p - b[i])));
		}
	}
	int ans = dp[k][n];
	cout << ans;

}



int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}