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
	string s;
	cin >> s;
	int ans=n;
	int i=0;
	int c1=0,c2=0,c3=0;
	for(int i=0;i<n;i++){
		if (s[i] == '>')
			c1++;
		else if(s[i] == '<')
			c2++;
		else
			c3++;
	}

	if(c1==n || c2==n || c3>=n-1){
		cout << n << endl;
		return;
	}

	if(c3==0){
		cout << 0 << endl;
	}

	int i=0;
	int cnt=0;
	while(i<n){
		if (s[i] == '>'){
			while(i+1<=n && )
		}
	}


	cout << ans << endl;

}*/

void solve() {
	string s;
	cin >> s;
	stack<char> st;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			st.push(s[i]);
		}
		else {
			if (s[i] == 'A')
				st.push('A');
			else {
				st.pop();
			}
		}
	}
	int ans = st.size();
	cout << ans << endl;
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



