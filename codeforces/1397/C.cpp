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
vector<int> g[MAX];
int par[MAX];
bool vis[MAX];
ll dp[1001][1001];

int n;
int maxd = 0, node = 0;

void dfs(int x, int d) {
	vis[x] = 1;
	if (d > maxd) {
		maxd = d;
		node = x;
	}
	for (int u : g[x]) {
		if (!vis[u]) {
			dfs(u, d + 1);
		}
	}
}

const int m = 1e6 ;
int f[m + 1];

ll get(int n) {
	ll ans = 1;
	ll l = 1, r = n;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (m * m == n)
			return m;
		else if (m * m < n) {
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return ans;
}

int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll a[n];
		for0(i, n) cin >> a[i];
		cout << 1 << " " << 1 << endl;
		cout << -1 * a[0] << endl;
		a[0] = 0;
		if (n == 1) {
			cout << 1 << " " << 1 << endl;
			cout << 0 << endl;
			cout << 1 << " " << 1 << endl;
			cout << 0 << endl;
		}
		else {

			cout << 2 << " " << n << endl;
			for1(i, n) {
				ll x = (ll)(a[i] * (n - 1));
				cout << x << " ";
				a[i] += x;
			}
			cout << endl;

			cout << 1 << " " << n << endl;
			for0(i, n) {
				ll x = -1 * a[i];
				cout << x << " ";
			}
		}
		//cout << endl;

		/*else{
			cout << 2 << " " << n << endl;
			for1(i,n){
				if(a[i]%2){
					cout << n-1 << " ";
					a[i]+=(n-1);
				}
				else
					cout << 0 << " ";
			}
			cout << endl;
		}*/

	}

}

