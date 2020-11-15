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
#define s second
#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
vector<int> par(MAX);
vector<int> mx(MAX);
vector<int> mn(MAX);
int dist[MAX];
bool vis[MAX];
vector<int> ran(MAX);

int parent(int x) {
	if (par[x] == x)
		return x;
	return par[x] = parent(par[x]);
}

void sunion(int x, int y) {
	if (ran[x] > ran[y])
		swap(x, y);
	par[x] = y;
	mx[y] = max(mx[x], mx[y]);
	mn[y] = min(mn[x], mn[y]);
	ran[y] += ran[x];
}


void solve(int idx = 0) {
	int n, w;
	cin >> n >> w;
	vector<pi> a;
	for0(i, n) {
		int x;
		cin >> x;
		a.pb({x, i + 1});
	}
	sort(all(a));
	int l = 0;
	int sum = 0;
	for0(i, n) {
		sum += a[i].f;
		//cout << sum << " ";
		if (sum >= (w + 1) / 2 && sum <= w) {
			cout << i - l + 1 << endl;
			for (int j = l; j <= i; j++) {
				cout << a[j].s << " ";
			}
			cout << endl;
			return;
		}
		if (sum > w) {
			while (l <= i && sum > w) {
				sum -= a[l].f;
				l++;
				if (sum >= (w + 1) / 2 && sum <= w) {
					cout << i - l + 1 << endl;
					for (int j = l; j <= i; j++) {
						cout << a[j].s << " ";
					}
					cout << endl;
					return;
				}
			}
		}
	}
	cout << -1 << endl;
}




int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}