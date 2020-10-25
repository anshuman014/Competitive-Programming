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
	int n, x, pos;
	cin >> n >> x >> pos;
	int more = n - x;
	int less = x - 1;
	//int hasmore = 0, hasless = 0;
	int l = 0, r = n;
	vector<int> fact(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int ans = 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (m > pos) {
			r = m;
			//hasmore++;
			ans = (ans * more) % mod;
			more--;
		}
		else {
			l = m + 1;
			if (m < pos) {
				ans = (ans * less) % mod;
				less--;
				//hasless++;
			}
		}
	}
	/*int op1 = (c(more, hasmore) * fact[hasmore]) % mod;
	int op2 = (c(less, hasless) * fact[hasless]) % mod;
	int ans = (op1 * op2) % mod;*/
	ans = (ans * fact[more + less]) % mod;

	cout << ans << endl;
	/*cout << more << " " << hasmore <<  endl;
	cout << less << " " << hasless ;*/
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