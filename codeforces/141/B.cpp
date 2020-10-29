#include <iostream>
using namespace std;

int main()
{
	int a, x, y;
	cin >> a >> x >> y;
	if(y % a == 0)cout << "-1\n";
	else
	{
		int lvl = y / a;
		if(lvl == 0)
		{
			if(x*2 > -a && x*2 < a)
				cout << "1\n";
			else cout << "-1\n";
		}
		else
		{
			lvl--;
			int st = 2 + (lvl/2) * 3;
			if(lvl % 2 == 0)
			{
				if(x*2 > -a && x*2 < a)
					cout << st << "\n";
				else cout << "-1\n";
			}
			else
			{
				if(x > -a && x < 0)
					cout << st + 1 << "\n";
				else if(x > 0 && x < a)
					cout << st + 2 << "\n";
				else cout << "-1\n";
			}
		}
	}
	return 0;
}
