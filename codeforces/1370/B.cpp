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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first % 2 > b.first % 2;
}


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
		int n;
		cin >> n;
		int a[2 * n];
		vector<int> odd;
		vector<int> even;
		for0(i, 2 * n) {
			cin >> a[i];
			if (a[i] % 2)
				odd.pb(i + 1);
			else
				even.pb(i + 1);
		}
		int o = odd.size();
		int e = even.size();
		int cnt = 0;
		for (int i = 0; i < o; i++) {
			if (i + 1 < o && cnt < n - 1) {
				cout << odd[i] << " " << odd[i + 1] << endl;
				cnt++;
				i++;
				if (cnt == n - 1)
					break;
			}
		}
		if (cnt < n - 1) {
			for (int i = 0; i < e; i++) {
				if (i + 1 < e && cnt < n - 1) {
					cout << even[i] << " " << even[i + 1] << endl;
					cnt++;
					i++;
					if (cnt == n - 1)
						break;
				}
			}
		}

	}
}