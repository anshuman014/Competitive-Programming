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
//#define s second
#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
vector<int> g[MAX];
vector<int> par(MAX);
int dist[MAX];
bool vis[MAX];
vector<int> ran(MAX);

int parent(int x) {
	if (par[x] == x)
		return x;
	return par[x] = parent(par[x]);
}

void sunion(int a, int b) {
	int x = parent(a), y = parent(b);
	if (x == y)
		return;
	if (ran[x] < ran[y])
		swap(x, y);
	par[y] = x;
	ran[x] += ran[y];
}

int lcm(int a, int b) {
	int g = __gcd(a, b);
	int lc = (a * b) / g;
	return lc;
}

void solve() {
	int n;
	cin >> n;
	int m = n;
	int mn = 1;
	vector<int> f;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			//f.pb(i);
			int num = 1;
			while (n % i == 0) {
				n = n / i;
				num = num * i;
			}
			if (num == m)
				num = num / i;
			f.pb(num);
		}
	}

	if (n > 1 && n != m)
		f.pb(n);

	for (int x : f) {
		//cout << x << " ";
		mn = lcm(mn, x);
		//cout << "mn" << " " << mn << endl;
	}

	int ans = m / mn;
	cout << ans;

}



int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}