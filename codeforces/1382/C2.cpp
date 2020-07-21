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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b ;
		vector<int> ans;
		int r = n - 1;
		//bool yes = true;
		int idx = 0;
		int cnt = 0;
		int left = 0;
		int right = n - 1;
		while (r >= 0) {
			cnt++;
			if (a[idx] == b[r]) {
				ans.push_back(1);
				if (a[idx] == '1')
					a[idx] = '0';
				else
					a[idx] = '1';
			}


			if (cnt % 2 ) {
				idx = right;

				left++;
			}
			else {
				idx = left;
				right--;
			}
			if (cnt % 2 ) {
				if (a[idx] == '1')
					a[idx] = '0';
				else
					a[idx] = '1';
			}
			ans.push_back(r + 1);



			r--;



		}
		cout << ans.size() << " ";
		int sz = ans.size();
		if (sz) {
			for (int x : ans)
				cout << x << " ";
			cout << endl;
		}
	}
}
