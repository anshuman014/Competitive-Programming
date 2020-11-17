#include<bits/stdc++.h>

using namespace std;

string s;
int n;
string res;

int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		if(res.size() % 2 == 0 || res.back() != s[i])
			res.push_back(s[i]);
	}
	if(res.size() % 2 == 1) res.pop_back();
	cout << n - int(res.size()) << endl << res << endl;
	return 0;
}