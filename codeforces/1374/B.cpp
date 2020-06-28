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
		ll n; cin >> n;
		int c2 = 0, c3 = 0, c = 0;
		while (n % 2 == 0) {
			c2++;
			n = n / 2;
		}
		while (n % 3 == 0) {
			c3++;
			n = n / 3;
		}
		if (n > 1)
			c = 1;
		if (c == 1 || c2 > c3)
			cout << -1 << endl;
		else
			cout << c3 + c3 - c2 << endl;
	}
}