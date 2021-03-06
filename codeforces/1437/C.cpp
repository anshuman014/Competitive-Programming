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

const int MAX = 100001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9;
const ll infinity = 1e18;
vector < vector<pair<int, int>> >g;
vector<int> vis;
vector<int> par;
vector<ll> dist;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}


char c[55][55]; int H, W;

void solve() {
	int n;
	cin >> n;
	vector<int> t(n + 1, 0);
	for1(i, n + 1) cin >> t[i];
	int dp[n + 1][2 * n + 1];
	sort(all(t));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2 * n + 1; j++) {
			//dp[i][j] = inf;
			if (i == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (j == 0) {
				dp[i][j] = inf;
				continue;
			}
			dp[i][j] =  dp[i - 1][j - 1] + abs(t[i] - j);
			dp[i][j] = min(dp[i][j - 1], dp[i][j]);
		}
	}
	int ans = inf;
	for (int i = n; i <= 2 * n; i++) {
		ans = min(dp[n][i], ans);
	}
	cout << ans << endl;

}



int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}