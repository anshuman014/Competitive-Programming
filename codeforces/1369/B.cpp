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
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		string ans = "";
		int i = 0;
		if (s[0] == '0') {
			while (s[i] == '0') {
				ans += s[i];
				i++;
			}
		}
		if (i < n && s[i] == '1') {
			while (s[i] == '1') {
				i++;
			}
		}
		if (i < n && s[i] == '0' )
			ans += s[i];
		i = n - 1;
		if (s[i] == '1') {
			while (s[i] == '1') {
				ans += s[i];
				i--;
			}
		}
		if (ans == "")
			cout << "0" << endl;
		else
			cout << ans << endl;
	}
}