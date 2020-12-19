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
#define int long long
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
//#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9 + 5;
const ll infinity = 1e18;

/*const int N = 2e5 + 5;
vector<int> g[N];
int vis[N];
int groups[N];
pair<int, int> e[N];*/



void solve(int tt = 0) {
	int n;
	cin >> n;
	string red, blue;
	cin >> red >> blue;

	//cout << red << " " << blue << endl;
	int r = 0, b = 0;
	for0(i, n) {
		if (red[i] > blue[i])
			r++;
		else if (red[i] < blue[i])
			b++;
	}

	if (r > b)
		cout << "RED";
	else if (r < b)
		cout << "BLUE";
	else{
		cout << "EQUAL";
	}
	cout << endl;

	/*if (red > blue)
		cout << "RED";
	else if (red < blue)
		cout << "BLUE";
	else
		cout << "EQUAL";
	cout << endl;*/

}

int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}
}