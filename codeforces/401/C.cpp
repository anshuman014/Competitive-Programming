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
vector < vector<int> > g;
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

	if (n > m + 1 || 2 * n + 2 < m) {
		cout << -1;
		return;
	}
	string ans = "";
	if (n > m) {
		ans = "0";
		n--;
	}
	while (m > 0 && n > 0) {
		if (m > n) {
			ans += "11";
			ans += '0';
			m -= 2;
			n--;
		}
		else if (m == n) {
			ans += '1';
			ans += '0';
			m--;
			n--;
		}
	}
	if (m == 1)
		ans += '1';
	else if (m == 2)
		ans += "11";
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