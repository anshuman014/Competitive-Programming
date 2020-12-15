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


void solve(int tt = 0) {
	int n;
	cin >> n;
	//n = tt;
	if (n > 45) {
		cout << -1 << endl;
		return;
	}

	int ans = 0;
	int i = 9;
	while (n - i >= 0 && i > 0) {
		n -= i;
		ans = ans * 10 + i;
		i = i - 1;
	}
	if (n > 0) {
		ans = ans * 10 + n;
	}
	int pr = 0;
	while (ans > 0) {
		int take = ans % 10;
		pr = pr * 10 + take;
		ans = ans / 10;
	}
	cout << pr << endl;
}

int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	//T = 50;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}
}