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
		int n, m;
		cin >> n >> m;

		bool yes = false;
		while (n--) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if ( b == c) {
				yes = true;
				//break;
			}
		}
		if (m % 2 || !yes)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}

/*

4
4
1 -5 3 2
5
4 -2 3 -9 2
9
-1 1 -1 1 -1 1 1 -1 -1
8
16 -5 -11 -15 10 5 4 -4


*/