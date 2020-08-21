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

const int MAX = 100001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
int par[MAX];
bool vis[MAX];
ll dp[1001][1001];

void dfs(int x) {
	vis[x] = 1;
	for (int u : g[x]) {
		if (!vis[u])
			dfs(u);
	}
}

int a[100001];
int n;

bool bs(int k) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] >= k) {
			if (a[m] == k)
				return true;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return false;
}





int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		int mn = INT_MAX;
		for0(i, n) {
			cin >> a[i];
			b[i] = a[i];
			mn = min(mn, a[i]);
		}
		sort(b, b + n);
		if (n == 1)
			cout << "YES" << endl;
		else {
			bool yes = true;
			for0(i, n) {
				if (a[i] == b[i])
					continue;
				if (__gcd(a[i], mn) != mn) {
					yes = false;
					break;
				}
			}
			if (yes)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}