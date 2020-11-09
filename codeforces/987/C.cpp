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


bool cmp(string s, string t) {
	return s + t < t + s;
}

void solve() {
	int n;
	cin >> n;
	vector<int> s(n), c(n);
	for0(i, n) cin >> s[i];
	//int ans = 0;
	for0(i, n) {
		cin >> c[i];
	}
	vector<int> nxt(n, -1);

	for (int i = 0; i < n; i++) {
		int mn = INT_MAX;
		for (int j = i + 1; j < n; j++) {
			if (s[j] > s[i]) {
				mn = min(mn, c[j]);
			}
		}
		if (mn != INT_MAX)
			nxt[i] = mn;
	}

	int ans = 1e18 + 10;
	for (int i = 0; i < n; i++) {
		int cost = c[i];
		int mn = 1e18;
		if (nxt[i] == -1)
			continue;
		for (int j = i + 1; j < n; j++) {
			if (nxt[j] == -1 || s[j] <= s[i])
				continue;
			/*if (i == 1) {
				cout << c[j] << " " << nxt[j] << endl;
			}*/
			mn = min(mn, c[j] + nxt[j]);
		}
		/*if (i == 1) {
			cout << cost << " " << mn << endl;
		}*/
		ans = min(ans, cost + mn);
	}
	/*for0(i, 5) {
		cout << nxt[i] << " ";
	}*/
	//cout << endl;
	if (abs(ans) > 1e17 || ans < 0) {
		cout << -1;
		return;
	}
	//if(ans<)
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

	while (T--) {
		solve();
	}
}