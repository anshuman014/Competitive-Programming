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
vector < vector<pair<int, int>> >g;
vector<int> vis;
vector<int> par;
vector<ll> dist;

int n, m;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}

int c(int n, int k) {
	if (n < 0 || n < k || k < 0)
		return 0;
	int ans = 1;
	if (k > n - k)
		k = n - k;
	for (int i = 1; i <= k; i++) {
		ans = (ans * (n - i + 1));
		if (ans > mod)
			ans %= mod;
		ans = ans / i;
	}
	return ans % mod;
}

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n][m];
	set<int> s;
	for0(i, n) {
		for0(j, m) {
			cin >> a[i][j];
			if (j == 0)
				s.insert(a[i][j]);
		}
	}

	int b[m][n];
	int row = -1;
	bool yes = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
			if (s.find(b[i][j]) != s.end()) {
				if (!yes) {
					row = i;
					yes = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int num = b[row][i];
		//int req = -1;
		for0(j, n) {
			if (a[j][0] == num) {
				for (int k = 0; k < m; k++) {
					cout << a[j][k] << " ";
				}
				cout << endl;
			}
		}
	}
	//cout << row << endl;
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