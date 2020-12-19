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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	ll gcall = 0, gcdiff = 0;
	for0(i, n) {
		cin >> a[i];
		gcall = __gcd(gcall, a[i]);
	}
	sort(all(a));

	for0(i, n) {
		if (i > 0) {
			ll d = a[i] - a[i - 1];
			gcdiff = __gcd(gcdiff, d);
		}
	}
	for0(i, m) {
		cin >> b[i];
		ll ans = __gcd(gcdiff, a[0] + b[i]);
		cout << abs(ans) << " ";
	}
	cout << endl;
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