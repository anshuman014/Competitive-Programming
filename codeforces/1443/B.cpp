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
#define mp make_pair

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200001;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9;
const ll infinity = 1e18;
vector < vector<int> >g;
vector<int> vis;
vector<int> par;
vector<ll> dist;

vector<int> p;
vector<int> pr;

void initgraph(int n) {
	g.resize(n + 1);
	vis.resize(n + 1);
	par.resize(n + 1);
	dist.resize(n + 1);
}


void solve() {


	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	ll dp[s.length() + 1] = {0};
	dp[0] = INT_MAX;
	int sum = 0;
	int cnt = 0;
	if (s[0] == '1')
	{
		dp[0] = a;
	}
	for (int i = 1; i < sz(s); i++)
	{
		if (s[i] == '0' && dp[i - 1] == INT_MAX)
		{
			dp[i] = dp[i - 1];
		}
		else if (s[i] == '0')
		{
			sum++;
			dp[i] = dp[i - 1];
		}
		else if (s[i] == '1' && dp[i - 1] == INT_MAX)
		{
			dp[i] = a;
		}
		else if (s[i] == '1' && s[i - 1] != '1')
		{
			dp[i] = min(dp[i - 1] + (sum * b), dp[i - 1] + a);
			sum = 0;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	if (dp[s.length() - 1] != INT_MAX)
		cout << dp[s.length() - 1] << "\n";
	else
		cout << "0\n";

}



int32_t main() {

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