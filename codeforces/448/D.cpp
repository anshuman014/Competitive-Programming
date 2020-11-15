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


int count(int val, int m, int n) {
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans += min(n, val / (i + 1));
	}
	return ans;
}

int findKthNumber(int m, int n, int k) {
	int l = 1, r = n * m;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		int c = count(mid, m, n);
		if (c >= k) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}


void solve() {
	int n, m, k;
	cin >> m >> n >> k;
	int ans = findKthNumber(m, n, k);
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