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

const int MAX = 200001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
int par[MAX];
bool vis[MAX];
ll dp[1001][1001];

int n;
int maxd = 0, node = 0;

void dfs(int x, int d) {
	vis[x] = 1;
	if (d > maxd) {
		maxd = d;
		node = x;
	}
	for (int u : g[x]) {
		if (!vis[u]) {
			dfs(u, d + 1);
		}
	}
}

const int m = 1e6 ;
int f[m + 1];



int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		//s = "0" + s;
		unordered_map<int, int> dp;
		dp[0] = 1;
		ll ans = 0;
		int sum = 0;
		for (int i = 0; i < sz(s); i++) {
			sum += s[i] - '0';
			//if (sum - i + 1 >= 0) {
			ans += dp[sum - i - 1 ];
			dp[sum - i - 1 ]++;
			//}

		}
		cout << ans << endl;
	}
}

