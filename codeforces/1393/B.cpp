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
	//cin >> t;
	t = 1;
	while (t--) {
		int n;
		cin >> n;
		int two = 0, four = 0, six = 0, eight = 0;
		vector<int> cnt(1000001, 0);
		for0(i, n) {
			int x;
			cin >> x;
			cnt[x]++;
			if (cnt[x] == 2)
				two++;
			else if (cnt[x] == 4) {
				four++;
				two--;
			}
			else if (cnt[x] == 6) {
				six++;
				four--;
			}
			else if (cnt[x] == 8) {
				eight++;
				six--;
			}
		}
		int q;
		cin >> q;
		while (q--) {
			char ch;
			int x;
			cin >> ch >> x;
			if (ch == '+') {
				cnt[x]++;
				if (cnt[x] == 2)
					two++;
				else if (cnt[x] == 4) {
					four++;
					two--;
				}
				else if (cnt[x] == 6) {
					six++;
					four--;
				}
				else if (cnt[x] == 8) {
					eight++;
					six--;
				}
			}
			else {
				cnt[x]--;
				if (cnt[x] == 1)
					two--;
				else if (cnt[x] == 3) {
					four--;
					two++;
				}
				else if (cnt[x] == 5) {
					six--;
					four++;
				}
				else if (cnt[x] == 7) {
					eight--;
					six++;
				}
			}

			if (four >= 2 || six >= 2 || eight)
				cout << "YES" << endl;
			else if (six && two)
				cout << "YES" << endl;
			else if (six && four)
				cout << "YES" << endl;
			else if (four >= 1 && two >= 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			/*if (four == 0 && six == 0)
				cout << "NO" << endl;
			else if (six == 1 && (four == 0 && two == 0))
				cout << "NO" << endl;
			else if (four == 1 && (two < 2))
				cout << "NO" << endl;
			else
				cout << "YES" << endl;*/

		}
	}

}