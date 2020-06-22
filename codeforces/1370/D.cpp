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
int a[200001];
int n, k;


bool ispossibleodd(int val) {
	int cnt = 0;
	for0(i, n) {
		if (cnt % 2 == 1)
			cnt++;
		else {
			if (a[i] <= val)
				cnt++;
		}
	}
	return cnt >= k;
}

bool ispossibleeven(int val) {
	int cnt = 0;
	for0(i, n) {
		if (cnt % 2 == 0)
			cnt++;
		else {
			if (a[i] <= val)
				cnt++;
		}
	}
	return cnt >= k;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int n,k;
	cin >> n >> k;
	//int a[n];
	for0(i, n) cin >> a[i];
	int l = 1, r = 1e9;
	int ans = 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (ispossibleodd(m) || ispossibleeven(m)) {
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	cout << ans;
}