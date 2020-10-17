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

const int MAX = 100001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
vector<int> g[MAX];
int par[MAX];
int col[MAX];
int d[MAX];
bool vis[MAX];



void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll gcd = 0LL;
	for0(i, n) {
		cin >> a[i];
		gcd = __gcd(gcd, a[i]);
	}
	if (gcd > 1) {
		cout << "YES" << endl;
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	for (int i = 0; i + 1 < n; i++) {
		int num = a[i];
		int num2 = a[i + 1];
		if (num % 2 && num2 % 2) {
			ans++;
			a[i] = (a[i] - a[i + 1]);
			a[i + 1] = num + num2;
		}
	}

	for (int i = 0; i + 1 < n; i++) {
		int num = a[i];
		int num2 = a[i + 1];
		if (num % 2 || num2 % 2) {
			ans += 2;
			a[i] = 2 * a[i];
			a[i + 1] = 2 * a[i + 1];
		}
	}

	cout << "YES" << endl;
	cout << ans << endl;

}


int main() {

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



