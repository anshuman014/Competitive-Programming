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

const int MAX = 300001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
vector<int> g[MAX];
int par[MAX];
int col[MAX];
int dist[MAX];
bool vis[MAX];

int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int n = s.size();
	ll ans = 0;
	vector<int> gen(n + 1, 1);
	gen[0] = 0;
	gen[1] = 1;
	ll num = 10;
	for (int i = 2; i <= n; i++) {
		gen[i] = (i * num + gen[i - 1]) % mod;
		num = (num * 10) % mod;
	}

	vector<int> gen1(n + 1, 1);
	gen1[0] = 1;
	gen1[1] = 10;
	num = 10;
	for (int i = 2; i <= n; i++) {
		gen1[i] = (num * gen1[i - 1]) % mod;
		//num = (num * 10) % mod;
	}




	for (int i = n - 1; i >= 0; i--) {
		ll left = i;
		ll tot = (left * (left + 1)) / 2;
		ll num = s[i] - '0';
		ll right = n - i - 1;
		ll sum = (tot % mod * (num * gen1[right]) % mod) % mod;
		//cout << sum << " ";
		ans = (ans + sum) % mod;

		sum = (num * gen[right]) % mod;
		ans = (ans + sum) % mod;
		//cout << sum << endl;
	}
	cout << ans;
}