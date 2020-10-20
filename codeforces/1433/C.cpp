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
vector<vector<int>> g;
vector<int> vis;
vector<int> par;
vector<int> dist;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> s;
	int mx = 0;
	for0(i, n) {
		cin >> a[i];
		s.insert(a[i]);
		mx = max(mx, a[i]);
	}

	if (sz(s) == 1) {
		cout << -1 << endl;
		return;
	}
	int ans = -1;
	for0(i, n) {
		if (a[i] == mx) {
			if (i + 1 < n && a[i] > a[i + 1]) {
				ans = i + 1;
				break;
			}
			if (i - 1 >= 0 && a[i] > a[i - 1]) {
				ans = i + 1;
				break;
			}
		}
	}
	cout << ans << endl;
}



int main() {

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



