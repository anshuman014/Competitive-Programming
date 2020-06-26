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

ll subarray(vector<int> v) {
	//int n = v.size();
	ll ans = 0, curr = 0;
	for (int x : v) {
		curr += x;
		ans = max(ans, curr);
		if (curr < 0)
			curr = 0;
	}
	return ans;
}

ll msubarray(vector<int> v) {
	//int n = v.size();
	ll ans = 0, curr = 0;
	for (int x : v) {
		curr += x;
		ans = min(ans, curr);
		if (curr > 0)
			curr = 0;
	}
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
		int n;
		cin >> n;
		int a[n];
		ll ans = 0;
		for0(i, n) {
			cin >> a[i];
			if (i % 2 == 0)
				ans += a[i];
		}
		vector<int> v1;
		for (int i = 1; i < n; i += 2) {
			v1.pb(a[i] - a[i - 1]);
		}
		vector<int> v2;
		for (int i = 2; i < n; i += 2) {
			v2.pb(a[i] - a[i - 1]);
		}
		ll ans1 = subarray(v1);
		ll ans2 = msubarray(v2);
		ans1 = max(ans1, abs(ans2));
		ans += ans1;
		cout << ans << endl;

	}
}