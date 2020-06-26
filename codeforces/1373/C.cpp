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

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		unordered_map<int, int> m;
		int cnt = 0, neg = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '-')
				cnt--;
			else
				cnt++;
			if (m.find(cnt) == m.end() && cnt < 0)
				m[cnt] = i;
			neg = min(neg, cnt);
		}
		ll ans = 0;
		//int x = m.size();
		int idx = 1;
		for (int i = -1; i >= (neg); i--) {
			ans += (m[i] + 1) ;//idx;
			idx++;
		}
		//cout << neg << endl;
		ans += n;
		cout << ans << endl;
	}
}