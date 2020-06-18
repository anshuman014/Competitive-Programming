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

bool cmp(pair<int, int> p, pair<int, int> q) {
	return p.second < q.second;
}

bool isvalid(vector<int> v, ll k) {
	ll res = 1;
	for (int x : v)
		res = res * x;
	if (res >= k)
		return true;
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	cin >> k;
	int idx = 1;
	vector<int> v(10, 1);
	while (!isvalid(v, k)) {
		v[idx]++;
		bool yes = isvalid(v, k);
		if (yes)
			break;
		idx = (idx + 1) % 10;
	}
	string s = "codeforces";
	string ans = "";
	for0(i, 10) {
		for (int j = 0; j < v[i]; j++)
			ans += s[i];
	}
	cout << ans;
}