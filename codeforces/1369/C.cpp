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
		int n, k;
		cin >> n >> k;
		int a[n];
		for0(i, n) cin >> a[i];
		int w[k];
		//int cnt=0;
		for0(i, k) cin >> w[i];
		ll ans = 0;
		sort(a, a + n);
		sort(w, w + k);
		int l = 0, r = n - 1;
		//int i = 0;
		//for0(i, k) ans += a[i];
		int idx = 0;
		//cout << ans << endl;
		while (idx < k && w[idx] == 1) {
			ans += 2 * a[r];
			r--;
			idx++;
		}
		//cout << ans << endl;
		if (idx < k) {
			for (int i = k - 1; i >= idx; i--) {
				ans += a[r] + a[l];
				r--;
				l += w[i] - 1;
			}
		}


		cout << ans << endl;
	}
}