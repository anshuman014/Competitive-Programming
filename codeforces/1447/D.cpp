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



void solve() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	int dp[n + 5][m + 5];
	memset(dp, 0, sizeof dp);
	//int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]) - 1);
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
			}
			ans = max(ans, dp[i][j]);
		}
	}
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
	for (int i = 1; i <= T; i++) {
		solve();
	}
}