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
bool vis[MAX];
ll dp[1001][1001];

string s, ans;
int n;

void dfs(int x) {
	vis[x] = 1;
	for (int u : g[x]) {
		if (!vis[u])
			dfs(u);
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n ;
		int a[n];
		for0(i, n) {
			cin >> a[i];
		}
		int cnt = 0;
		for0(i, n) {
			if (a[i] == a[0])
				cnt++;
		}
		if (cnt == n)
			cout << n << endl;
		else
			cout << 1 << endl;
	}
}