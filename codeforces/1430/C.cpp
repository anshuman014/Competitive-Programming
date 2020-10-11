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

const int MAX = 300001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
vector<int> g[MAX];
int par[MAX];
int col[MAX];
int dist[MAX];
bool vis[MAX];



void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for0(i, n) {
		v[i] = i + 1;
	}
	vector<int> ans;

	int m = n - 1;

	cout << 2 << endl;
	while (m--) {
		n = v.size();
		int a = v[n - 1];
		int b = v[n - 2];
		int sum = (a + b) / 2;
		if ((a + b) % 2)
			sum++;
		v.pop_back();
		v.pop_back();
		v.pb(sum);
		cout << a << " " << b << endl;

	}

}


int main() {

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



