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
vector<int> g[MAX];
int par[MAX];
int col[MAX];
int d[MAX];
bool vis[MAX];

ll dp[MAX][3];


void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	int zero = r / 3 - l / 3 + (l % 3 == 0);
	int one = (r / 3 + (r % 3 >= 1)) - (l % 3 == 0 ? l / 3 : (l % 3 == 1 ? l / 3 : l / 3 + 1));
	int two = r - l + 1 - (zero + one);
	dp[1][0] = zero;
	dp[1][1] = one;
	dp[1][2] = two;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] * zero + dp[i - 1][1] * two + dp[i - 1][2] * one) % mod;
		dp[i][1] = (dp[i - 1][0] * one + dp[i - 1][1] * zero + dp[i - 1][2] * two) % mod;
		dp[i][2] = (dp[i - 1][0] * two + dp[i - 1][1] * one + dp[i - 1][2] * zero) % mod;
	}
	cout << dp[n][0];

}



int main() {

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



