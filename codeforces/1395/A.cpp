#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// freopen("breedflip.in", "r", stdin);
	// freopen("breedflip.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		ll r, g, b, w;
		cin >> r >> g >> b >> w;
		ll mn = min(r, min(g, b));
		/*r -= mn;
		g -= mn;
		b -= mn;
		w += 3 * mn;*/
		bool yes = false;
		int cnt = 0;
		if (r % 2 > 0)
			cnt++;
		if (g % 2 > 0)
			cnt++;
		if (b % 2 > 0)
			cnt++;
		if (w % 2 > 0)
			cnt++;
		if (cnt <= 1)
			yes = true;


		if (!yes && mn > 0) {
			r--;
			g--;
			b--;
			w += 3;
			cnt = 0;
			if (r % 2 > 0)
				cnt++;
			if (g % 2 > 0)
				cnt++;
			if (b % 2 > 0)
				cnt++;
			if (w % 2 > 0)
				cnt++;
			if (cnt <= 1)
				yes = true;
		}
		if (yes)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}