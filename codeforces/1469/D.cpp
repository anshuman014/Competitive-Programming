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
//#define mp make_pair
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9 + 5;
const ll infinity = 1e18;

/*const int N = 2e5 + 5;
vector<int> g[N];
int vis[N];
int groups[N];
pair<int, int> e[N];*/

const int N = 5 * 1e6 + 5;
vector<int> spf(N);
vector<bool> prime(N);
vector<int> cnt(N);
vector<int> ans(N);


void preprocess() {
	for1(i, N + 1) {
		spf[i] = i;
		prime[i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		if (prime[i]) {
			for (int d = i * i; d <= N; d += i) {
				prime[d] = false;
				spf[d] = i;
			}
		}
	}


	for (int i = 2; i <= N; i++) {
		int c = 0;
		int j = i;
		while (j != 1) {
			c++;
			j = j / spf[j];
		}
		cnt[i] = c;
	}

	for (int i = 2; i <= N; i++) {
		ans[i] = ans[i - 1] + cnt[i];
	}

}


void solve() {
	int n;
	cin >> n;
	if (n <= 32) {
		if (n < 3) {
			cout << 0 << endl;
			return;
		}
		if (n == 3) {
			cout << 2 << endl;
			cout << 3 << " " << 2 << endl;
			cout << 3 << " " << 2 << endl;
			return;
		}
		cout << n + 2 << endl;
		for (int i = 3; i < n; i++) {
			cout << i << " " << n << endl;
		}
		int c = 5;
		while (c--) {
			cout << n << " " << 2 << endl;
		}
		return;
	}
	cout << n + 5 << endl;
	for (int i = 3; i < 32; i++) {
		cout << i << " " << 32 << endl;
	}

	for (int i = 33; i < n; i++) {
		cout << i << " " << n << endl;
	}
	int c = 4;
	while (c--) {
		cout << n << " " << 32 << endl;
	}

	c = 5;
	while (c--) {
		cout << 32 << " " << 2 << endl;
	}





}



int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//preprocess();
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}