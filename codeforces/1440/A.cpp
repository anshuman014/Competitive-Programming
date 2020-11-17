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
	int n, c1, c0, h;
	cin >> n >> c0 >> c1 >> h;
	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for (char c : s) {
		if (c == '0')
			cnt0++;
		else
			cnt1++;
	}
	if (c1 == c0) {
		int ans = n * c0;
		cout << ans << endl;
	}
	else if (c1 > c0) {
		if (c0 + h < c1) {
			c1 = c0 + h;
		}
		int ans = c0 * cnt0 + c1 * cnt1;
		cout << ans << endl;
	}
	else {
		if (c1 + h < c0) {
			c0 = c1 + h;
		}
		int ans = c0 * cnt0 + c1 * cnt1;
		cout << ans << endl;
	}

}


int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}