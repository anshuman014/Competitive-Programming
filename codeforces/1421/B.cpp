#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// if ((int)name.size()) {
	// 	freopen((name + ".in").c_str(), "r", stdin);
	// 	freopen((name + ".out").c_str(), "w", stdout);
	// }
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

const int MAX = 300001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
vector<int> g[MAX];
int par[MAX];
int col[MAX];
int d[MAX];
bool vis[MAX];

/*void solve() {
	int n;
	cin >> n;
	string s[n];
	for0(i, n) cin >> s[i];
	//int cnt = 0;
	char c = s[0][1];
	char d = s[1][0];
	char x = s[n - 1][n - 2];
	char y = s[n - 2][n - 1];
	if (x == '0' && y == '0') {
		int cnt = 0;
		vector<pi> v;
		if (c == '0') {
			cnt++;
			v.pb({0, 1});
		}
		if (d == '0') {
			cnt++;
			v.pb({1, 0});
		}
		int i = 0;
		cout << cnt << endl;
		while (i < cnt) {
			cout << v[i].f + 1 << " " << v[i].s + 1 << endl;
			i++;
		}
	}
	else if (x == '1' && y == '1') {
		int cnt = 0;
		vector<pi> v;
		if (c == '1') {
			cnt++;
			v.pb({0, 1});
		}
		if (d == '1') {
			cnt++;
			v.pb({1, 0});
		}
		int i = 0;
		cout << cnt << endl;
		while (i < cnt) {
			cout << v[i].f + 1 << " " << v[i].s + 1 << endl;
			i++;
		}
	}
	else if ((x == '1' && y == '0') || (x == '0' && y == '1') ) {
		int cnt = 0;
		vector<pi> v;
		int c0 = 1, c1 = 1;
		if (c == '0')
			c0++;
		else
			c1++;
		if (d == '0')
			c0++;
		else
			c1++;
		if (c1 == c0) {
			cnt = 2;
			v.pb({n - 1, n - 2});
			if (c == '1') {
				v.pb({0, 1});
			}
			else
				v.pb({1, 0});
		}
		else if (c1 > c0) {
			cnt = 1;
			v.pb({n - 1, n - 2});
		}
		else if (c1 < c0) {
			cnt = 1;
			v.pb({n - 2, n - 1});
		}




		int i = 0;
		cout << cnt << endl;
		while (i < cnt) {
			cout << v[i].f + 1 << " " << v[i].s + 1 << endl;
			i++;
		}
	}



}*/


void solve() {
	int n;
	cin >> n;
	string s[n];
	for0(i, n) cin >> s[i];
	//int cnt = 0;
	char c = s[0][1];
	char d = s[1][0];
	char x = s[n - 1][n - 2];
	char y = s[n - 2][n - 1];
	int c0 = 0, c1 = 0;
	if (c == '0')
		c0++;
	else
		c1++;
	if (d == '0')
		c0++;
	else
		c1++;
	if (x == '0')
		c0++;
	else
		c1++;
	if (y == '0')
		c0++;
	else
		c1++;

	vector<pi> v;

	int cnt = 0;
	if (c0 == c1) {
		cnt = 0;

		if (c == '0' && d == '1') {
			cnt = 2;
			v.pb({0, 1});
			if (x == '1') {
				v.pb({n - 1, n - 2});
			}
			else if (y == '1') {
				v.pb({n - 2, n - 1});
			}
		}
		if (c == '1' && d == '0') {
			cnt = 2;
			v.pb({0, 1});
			if (x == '0') {
				v.pb({n - 1, n - 2});
			}
			else if (y == '0') {
				v.pb({n - 2, n - 1});
			}
		}
	}
	else if (c0 > c1) {
		//cnt = 1;
		if (c == d) {
			if (x == '0') {
				cnt++;
				v.pb({n - 1, n - 2});
			}
			if (y == '0') {
				cnt++;
				v.pb({n - 2, n - 1});
			}
		}
		else {
			if (c == '0') {
				cnt++;
				v.pb({0, 1});
			}
			if (d == '0') {
				cnt++;
				v.pb({1, 0});
			}
		}
	}
	else if (c1 > c0) {
		cnt = 0;
		if (c == d) {
			if (x == '1') {
				v.pb({n - 1, n - 2});
				cnt++;
			}
			if (y == '1') {
				v.pb({n - 2, n - 1});
				cnt++;
			}
		}
		else {
			if (c == '1') {
				v.pb({0, 1});
				cnt++;
			}
			if (d == '1') {
				v.pb({1, 0});
				cnt++;
			}
		}
	}

	int i = 0;
	cout << cnt << endl;
	while (i < cnt) {
		cout << v[i].f + 1 << " " << v[i].s + 1 << endl;
		i++;
	}

}



int main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}



