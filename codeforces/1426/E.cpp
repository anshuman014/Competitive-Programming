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

const int MAX = 200001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
int par[MAX];
int dist[MAX];
bool vis[MAX];
int rank[MAX];


int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	//cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int a, b, c, x, y, z;
		int arr[6];
		cin >> a >> b >> c;
		cin >> x >> y >> z;
		arr[0] = a, arr[1] = b, arr[2] = c, arr[3] = x;
		arr[4] = y, arr[5] = z;
		ll ans = 0;
		ll mn = min(a, y);
		a -= mn;
		y -= mn;
		ans += mn;
		mn = min(b, z);
		b -= mn;
		z -= mn;
		ans += mn;
		mn = min(c, x);
		c -= mn;
		x -= mn;
		ans += mn;
		//cout << ans << " ";

		a = arr[0], b = arr[1], c = arr[2], x = arr[3];
		y = arr[4], z = arr[5];

		ll ans1 = 0;
		mn = min(a, x);
		a -= mn;
		x -= mn;
		mn = min(a, z);
		a -= mn;
		z -= mn;
		mn = min(b, x);
		b -= mn;
		x -= mn;
		mn = (min(b, y));
		b -= mn;
		y -= mn;
		mn = min(c, y);
		c -= mn;
		y -= mn;
		mn = min(c, z);
		c -= mn;
		z -= mn;
		ans1 = min(a + b + c, x + y + z);

		a = arr[0], b = arr[1], c = arr[2], x = arr[3];
		y = arr[4], z = arr[5];
		mn = min(c, z);
		c -= mn;
		z -= mn;
		mn = min(c, y);
		c -= mn;
		y -= mn;
		mn = (min(b, y));
		b -= mn;
		y -= mn;
		mn = min(b, x);
		b -= mn;
		x -= mn;
		mn = min(a, z);
		a -= mn;
		z -= mn;
		mn = min(a, x);
		a -= mn;
		x -= mn;




		ans1 = min((int)ans1, a + b + c);

		cout << ans1 << " " << ans ;
	}
}
