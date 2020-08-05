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

int n, x;
ll dp[1001][1001];


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
		int a[n];
		unordered_map<int, int> m;
		unordered_map<int, int> mp;
		for0(i, n) {
			cin >> a[i];
			m[a[i]]++;
		}
		mp = m;
		int size = 100;
		int ans = 0, cnt = 0;
		while (size > 1) {
			for0(i, n) {
				//int num = a[i];
				int req = size - a[i];
				if ((req == a[i] && mp[req] > 1) || (req != a[i] && mp[req] > 0 && mp[a[i]] > 0)) {
					cnt++;
					mp[a[i]]--;
					mp[req]--;
				}
			}

			ans = max(ans, cnt);
			cnt = 0;
			mp = m;
			size--;
		}
		cout << ans << endl;

	}


}
