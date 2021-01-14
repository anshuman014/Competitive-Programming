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
//#define s second
//#define mp make_pair
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX = 200005;
const int mod = 1e9 + 7;
const ll modulo = 998244353;
const int inf = 1e9 + 5;
const ll infinity = 1e18;

const int N = 2e5 + 5;
vector<int> g[N];
int vis[N];
pair<int, int> e[N];


class NumArray {
public:
	int b;
	vector<int> tree;

	NumArray(vector<int>& nums) {
		int n = nums.size();
		b = 1;
		while (b < n) {
			b = b * 2;
		}
		tree.resize(2 * b);
		for (int i = 0; i < n; i++) {
			tree[b + i] = nums[i];
		}
		for (int i = b - 1; i >= 1; i--) {
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}

	}

	void update(int i, int val) {
		tree[b + i] = val;
		for (int j = (b + i) / 2; j >= 1; j /= 2) {
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}

	int sumRange(int i, int j) {
		int l = i, r = j;
		l += b;
		r += b;
		int sum = tree[l];
		if (l != r)
			sum = max(sum, tree[r]);
		while (l + 1 < r) {
			if (l % 2 == 0) {
				sum = max(sum, tree[l + 1]);
			}
			if (r % 2 == 1) {
				sum = max(sum, tree[r - 1]);
			}
			l = l / 2;
			r = r / 2;
		}
		return sum;
	}
};



class NumArray1 {
public:
	int b;
	vector<int> tree;

	NumArray1(vector<int>& nums) {
		int n = nums.size();
		b = 1;
		while (b < n) {
			b = b * 2;
		}
		tree.resize(2 * b);
		for (int i = 0; i < n; i++) {
			tree[b + i] = nums[i];
		}
		for (int i = b - 1; i >= 1; i--) {
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}

	}

	void update(int i, int val) {
		tree[b + i] = val;
		for (int j = (b + i) / 2; j >= 1; j /= 2) {
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}

	int sumRange(int i, int j) {
		int l = i, r = j;
		l += b;
		r += b;
		int sum = tree[l];
		if (l != r)
			sum = min(sum, tree[r]);
		while (l + 1 < r) {
			if (l % 2 == 0) {
				sum = min(sum, tree[l + 1]);
			}
			if (r % 2 == 1) {
				sum = min(sum, tree[r - 1]);
			}
			l = l / 2;
			r = r / 2;
		}
		return sum;
	}
};











void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> a(n + 2, 0);
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		char c = s[i - 1];
		if (c == '+') {
			a[i] = 1 + a[i - 1];
		}
		else
			a[i] = a[i - 1] - 1;
	}

	/*for0(i, n + 1) {
		cout << a[i] << " ";
	}
	cout << endl;*/

	NumArray mx(a);

	NumArray1 mn(a);

	while (m--) {
		int l, r;
		cin >> l >> r;
		int p = mx.sumRange(0, l - 1);
		int q = mn.sumRange(0, l - 1);
		/*if (m == 8) {
			cout << p << " " << q << endl;
		}*/
		int t = a[r], u = a[r];
		if (r < n) {
			t = mx.sumRange(r + 1, max(r + 1, n));
			u = mn.sumRange(r + 1, max(r + 1, n));
		}
		/*int d = 0;
		if (t != 0 || u != 0) {
			d = t - u + 1;
		}*/
		int d1 = t - a[r] ;
		int d2 = a[r] - u;
		/*if (m == 8) {
			cout << t << " " << u << " " << a[r] << endl;
			cout << d1 << " " << d2 << endl;
		}*/

		/*if (m == 8) {
			cout << "l-1 " << " " << l - 1 << endl;
			cout << a[l - 1] << endl;
		}*/
		a[l - 1] += d1;
		p = max(p, a[l - 1]);
		q = min(q, a[l - 1]);
		a[l - 1] -= d1;
		a[l - 1] -= d2;
		p = max(p, a[l - 1]);
		q = min(q, a[l - 1]);
		a[l - 1] += d2;
		int tot = p - q + 1;
		//cout << p << " " << q << endl;
		cout << tot << endl;


	}

}



int32_t main() {

	setIO();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}