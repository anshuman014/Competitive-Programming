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

	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		//vector<int> a(n + 1);
		//int ro = 0, re = 0, bo = 0, be = 0;
		string s;
		cin >> s;
		s = "0" + s;
		int odd = 0, even = 0;
		for (int i = 1; i <= n; i++) {
			//cin >> a[i];
			int a = s[i] - '0';
			if (i % 2 && a % 2)
				odd = 1;
			if (i % 2 == 0 && a % 2 == 0)
				even = 1;
		}
		/*if (n % 2) {
			if (odd)
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
		else {
			if (even)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}*/
		if (n % 2 && odd)
			cout << 1 << endl;
		else if (n % 2 == 0 && even)
			cout << 2 << endl;
		else if (n % 2)
			cout << 2 << endl;
		else
			cout << 1 << endl;
		/*else
			cout << 2 << endl;*/
	}
}

