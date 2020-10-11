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


vector<int> dp[2001];


void solve() {
	int n;
	cin >> n;
	if (n < 3 || n == 4)
		cout << -1 << endl;
	else if (n % 3 == 0)
		cout << n / 3 << " " << 0 << " " << 0 << endl;
	else if (n % 5 == 0)
		cout << 0 << " " << n / 5 << " " << 0 << endl;
	else if (n % 7 == 0)
		cout << 0 << " " << 0 << " " << n / 7 << endl;
	else {
		/*if (dp[n].size() == 0) {
			cout << -1 << endl;
		}
		else {*/
		//int sz = dp[n].size();
		//reverse(all(dp[n]));
		cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;
		//}
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

	/*for (int i = 1; i <= 1000; i++)
		dp[i].clear();*/

	//vector<int> vis(1001, 0);

	for (int i = 0; i <= 334; i++) {
		for (int j = 0; j <= 201; j++) {
			for (int k = 0; k <= 143; k++) {
				ll num = i * 3 + j * 5 + k * 7;
				if (num <= 1001 ) {
					/*if (num == 100)
						cout << i << " " << j << " " << k << endl;*/
					dp[num].pb(i);
					dp[num].pb(j);
					dp[num].pb(k);
					//vis[num]++;
				}
			}
		}
	}



	while (T--) {
		solve();
	}
}



