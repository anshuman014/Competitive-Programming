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
const int inf = 1e9;
const ll infinity = 1e18;
vector < vector<int> >g;
vector<int> vis;
vector<int> par;
vector<ll> dist;

vector<int> p;
vector<int> pr;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}


void solve() {


	int n; cin >> n;
	vector<int> a(n);
	for0(i, n) cin >> a[i];
	int dp[n + 1][2];

	/*if (a[0] == 1)
		dp[0][0] = 1;*/
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = 1e6;
		}
	}
	//dp[1][1] = 0;
	dp[0][0] = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < 2; j++) {
			int skips = 0;
			if (j == 0 && a[i] == 1)
				skips++;
			dp[i + 1][j ^ 1] = min(dp[i + 1][j ^ 1], dp[i][j] + skips);
			if (i + 1 < n && j == 0 && a[i + 1] == 1)
				skips++;
			if (i + 2 <= n)
				dp[i + 2][j ^ 1] = min(dp[i + 2][j ^ 1], dp[i][j] + skips);
		}
		//cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	//cout << dp[n][0] << " " << dp[n][1] << endl;
	cout << min(dp[n][0], dp[n][1]) << endl;
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