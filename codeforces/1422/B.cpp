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

	int T = 1;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<ll>> v(105, vector<ll>(105));
		ll sum = 0;
		for0(i, n) {
			for0(j, m) {
				cin >> v[i][j];
				sum += v[i][j];
			}
		}
		//sum /= 2;

		ll ans = 0;
		/*for0(i, n) {
			for0(j, m) {
				ans += abs(sum1 - v[i][j]);
				v[i][j] = sum1;
			}
		}*/
		for0(i, n) {
			for0(j, m) {
				ll a = v[i][j];
				ll b = v[n - i - 1][j];
				ll c = v[i][m - j - 1];
				ll d = v[n - i - 1][m - j - 1];
				//ll avg = (a + b + c + d) / 4;
				//if ((a + b + c + d) % 4 >= 2)
				//	avg++;
				//cout << avg << " ";
				/*ll op1 = ((abs(avg - a) + abs(avg - b) + abs(avg - c) + abs(avg - d)));
				avg++;
				ll op2 = ((abs(avg - a) + abs(avg - b) + abs(avg - c) + abs(avg - d)));
				ans += min(op1, op2);*/
				ll op1 = (abs(b - a) + abs(c - a) + abs(d - a));
				ll op2 = abs(a - b) + abs(c - b) + abs(d - b);
				ll op3 = abs(a - c) + abs(b - c) + abs(d - c);
				ll op4 = abs(a - d) + abs(b - d) + abs(c - d);
				ans += min({op1, op2, op3, op4});
			}
			//cout << endl;
		}


		cout << ans / 4 << endl;
	}
}