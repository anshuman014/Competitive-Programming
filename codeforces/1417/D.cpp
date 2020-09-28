#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


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

const int MAX = 200001;
const int mod = 1e9 + 7;
vector<int> g[MAX];
int par[MAX];
int dist[MAX];
bool vis[MAX];
int rank[MAX];


int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int sum = 0;
		for0(i, n) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum % n) {
			cout << -1 << endl;
		}
		else {
			cout << 3 * n - 3 << endl;
			for1(i, n) {
				int nm = ((i + 1) - (a[i] % (i + 1))) % (i + 1);

				cout << 1 << " " << i + 1 << " " << nm << endl;
				a[i] += nm;
				int x = a[i] / (i + 1);
				cout << i + 1 << " " << 1 << " " << x << endl;
			}
			int num = sum / n;
			for1(i, n) {
				cout << 1 << " " << i + 1 << " " << num << endl;
			}
		}
	}
}