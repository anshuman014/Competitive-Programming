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
	vector<ll> v;
	ll n = 1;
	ll pre = 1;
	ll sum = 0;
	while (sum < (ll)1e18) {
		ll num = (pre * (pre + 1)) / 2;
		v.push_back(num);
		n *= 2;
		pre += n;
		sum += num;
	}
	while (t--) {
		ll x;
		cin >> x;
		n = v.size();
		sum = 0;
		ll ans = 0;
		int i = 0;
		while (sum + v[i] <= x && i < n) {
			sum += v[i];
			i++;
			ans++;
		}
		cout << ans << endl;
	}

}

