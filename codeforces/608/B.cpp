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
vector < vector<int> >g;
vector<int> vis;
vector<int> par;
vector<ll> dist;

vector<int> p;
vector<int> pr;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}


bool cmp(string s, string t) {
	return s + t < t + s;
}

void solve() {
	string a, b;
	cin >> a >> b;
	int m = a.size();
	int n = b.size();
	if (m > n) {
		cout << 0;
		return;
	}
	int ans = 0;
	vector<int> z(n + 1, 0), ones(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		z[i] = z[i + 1];
		ones[i] = ones[i + 1];
		if (b[i] == '0')
			z[i]++;
		else
			ones[i]++;
	}
	for0(i, m) {
		if (a[i] == '1') {
			ans += z[i] - z[i + n - m + 1];
			//cout << "Z" << " ";
			//cout << z[i] << " " << z[i + n - m + 1] << endl;
		}
		else {
			//cout << "one" << " ";
			//cout << ones[i] << " " << ones[i + n - m + 1] << endl;
			ans += ones[i] - ones[i + n - m + 1];
		}
	}
	cout << ans;

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