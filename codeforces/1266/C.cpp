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


void solve() {
	int r, c;
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << 0;
		return;
	}

	if (r == 1 || c == 1) {
		int mx = max(r, c);
		for (int i = 1; i <= mx; i++)
			cout << i + 1 << " ";
		return;
	}

	vector<int> row(r);
	vector<int> col(c);
	for (int i = 0; i < r; i++) {
		row[i] = i + 1;
	}
	for (int i = 0; i < c; i++) {
		if (i == 0)
			col[i] = row[r - 1] + 1;
		else
			col[i] = col[i - 1] + 1;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << row[i]*col[j] << " ";
		}
		cout << endl;
	}



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