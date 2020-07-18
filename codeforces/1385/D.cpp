#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define endl "\n"
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<n;i++)
#define ps(x,y) fixed << setprecision(y) << x
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int MAX = 100001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
int par[MAX];
bool vis[MAX];
string s;
int n;


int getdiff(int l, int r, char c) {
	int ans = 0;
	for (int i = l; i <= r; i++)
		if (s[i] != c)
			ans++;
	return ans;
}

int getmin(int l, int r, char c) {
	if (l == r) {
		if (s[l] == c)
			return 0;
		return 1;
	}
	int m = (l + r) / 2;
	int ans1 = getdiff(l, m, c) + getmin(m + 1, r, c + 1);
	int ans2 = getdiff(m + 1, r, c) + getmin(l, m, c + 1);
	int ans = min(ans1, ans2);
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		//int n;
		cin >> n;
		//string s;
		cin >> s;
		int ans = getmin(0, n - 1, 'a');
		cout << ans << endl;
	}
}