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
//#define f first
//#define s second
//#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9 + 5;
const ll infinity = 1e18;

const int N = 2e5 + 5;
vector<int> g[N];
int vis[N];
pair<int, int> e[N];




void solve(int tt = 0) {
	//cout << "Case #" << tt << ": ";

	int n;
	cin >> n;
	vector<int> a(n);
	set<int> s;
	for0(i, n) {
		cin >> a[i];
		int x = a[i];
		if (s.find(x) != s.end()) {
			x++;
		}
		s.insert(x);
	}
	int ans = s.size();
	cout << ans << endl;



}




int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tt = 1;
	cin >> tt;

	//cout << (1 << 26) << " " << 5e7 << endl;
	for (int i = 1; i <= tt; i++)
	{
		solve(i);
	}
	return 0;
}
