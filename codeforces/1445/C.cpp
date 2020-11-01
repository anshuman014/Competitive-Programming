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

const int MAX = 100001;
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

vector<int> factors(int x) {
	vector<int> res;
	for (int i = 2; i <= sqrt(x) + 5; i++) {
		if (x % i == 0) {
			res.push_back(i);
		}
		while (x % i == 0) {
			x /= i;
		}
	}
	if (x > 1) {
		res.push_back(x);
	}
	return res;
}


void solve() {
	int p, q;
	cin >> p >> q;
	if (p % q) {
		cout << p << endl;
		return;
	}
	//int gc = __gcd(p, q);
	int ans = 1;
	int l = q;
	vector<int> fact = factors(l);


	for (int i : fact) {
		//cout << i << " ";
		int x = p;
		while (x % q == 0) {
			x /= i;
		}
		ans = max(ans, x);
	}


	cout << ans << endl;
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