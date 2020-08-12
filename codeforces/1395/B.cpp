#include <bits/stdc++.h>
using namespace std;
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

const int MAX = 100001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
int par[MAX];
//bool vis[MAX];
ll dp[1001][1001];

string s, ans;
int n, m;
int a[101][101];
bool vis[101][101];

void dfs(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m)
		return;
	if (vis[x][y])
		return;
	cout << x << " " << y << endl;
	vis[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// freopen("breedflip.in", "r", stdin);
	// freopen("breedflip.out", "w", stdout);
	int t = 1;
	//cin >> t;
	while (t--) {
		int x, y;
		cin >> n >> m >> x >> y;

		/*for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				a[i][j] = 0;
			}
		}*/
		int cnt = 0;
		int num = y;
		while (num > 0) {
			cnt++;
			cout << x << " " << num << endl;
			num--;
		}
		num = y + 1;
		while (num <= m) {
			cnt++;
			cout << x << " " << num << endl;
			num++;
		}

		bool last = true;
		int prev = x - 1;
		x++;
		while (cnt < n * m && x <= n) {
			if (last) {
				num = m;
				while (num > 0) {
					cnt++;
					cout << x << " " << num << endl;
					num--;
				}
			}
			else {
				num = 1;
				while (num <= m) {
					cnt++;
					cout << x << " " << num << endl;
					num++;
				}
			}
			x++;
			last = !last;
		}
		x = prev;
		while (cnt < n * m && x > 0) {
			if (last) {
				num = m;
				while (num > 0) {
					cnt++;
					cout << x << " " << num << endl;
					num--;
				}
			}
			else {
				num = 1;
				while (num <= m) {
					cnt++;
					cout << x << " " << num << endl;
					num++;
				}
			}
			x--;
			last = !last;
		}
	}
}