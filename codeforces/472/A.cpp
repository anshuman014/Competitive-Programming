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

set<int> st;

/*void recurse(int start, int last, vector<int> &a, vector<int> &pre) {
	if (start >= last)
		return;
	int small = a[start], big = a[last];
	int poss = pre[last] - pre[start];
	s.insert(poss);
	int mid = (small + big) / 2;
	int split = upper_bound(all(a), mid) - a.begin();
	recurse(start, split - 1, a, pre);
	recurse(split, last, a, pre);
}*/


void recurse(int s, int e, vector<int> &a) {
	if (s > e)
		return;
	int sum = 0;
	for (int i = s; i <= e; i++)
		sum += a[i];
	int pos = -1;
	st.insert(sum);
	int mid = (a[s] + a[e]) / 2;
	for (int i = s; i <= e; i++) {
		if (a[i] <= mid)
			pos = i;
		else
			break;
	}
	if (pos == -1 || pos == e)
		return;
	recurse(s, pos, a);
	recurse(pos + 1, e, a);
}

void solve() {
	int n;
	cin >> n;
	if (n % 2)
		cout << 9 << " " << n - 9;
	else
		cout << 4 << " " << n-4;

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