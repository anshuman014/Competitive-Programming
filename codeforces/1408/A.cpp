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
		for0(i, n) {
			cin >> a[i];
		}
		vector<int> b(n), c(n);
		for0(i, n) {
			cin >> b[i];
		}
		for0(i, n) {
			cin >> c[i];
		}
		vector<int> p;
		int i = 0;
		p.pb(a[0]);
		i = 1;
		while (i < n) {
			if (a[i] == p.back()) {
				p.pb(b[i]);
			}
			else {
				p.pb(a[i]);
			}
			i++;
		}
		if (p[0] == p[n - 1]) {
			int op1 = a[n - 1];
			int op2 = b[n - 1];
			int op3 = c[n - 1];
			if (op1 != p[0] && op1 != p[n - 2]) {
				p[n - 1] = op1;
			}
			else if (op2 != p[0] && op2 != p[n - 2]) {
				p[n - 1] = op2;
			}
			else if (op3 != p[0] && op3 != p[n - 2]) {
				p[n - 1] = op3;
			}
		}
		for0(i, n) {
			cout << p[i] << " ";
		}
		cout << endl;

	}
}