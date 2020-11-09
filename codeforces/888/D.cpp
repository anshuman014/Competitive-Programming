
// In the name of God

#include<bits/stdc++.h>
using namespace std;
#define Size(x) ((int)(x).size())
#define pb push_back
typedef long long ll;
typedef pair<int ,int>pii;
typedef long double ld;

int p[5] = {1 , 0 , 1 , 2 , 9};
ll C[10][1100];
int n , k;

int main(){
	ios_base :: sync_with_stdio(false) , cout.tie(0) , cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<=4;++i)
		for(int j=0;j<=1000;++j){
			if(i == 0) C[i][j] = 1;
			else if(i > j) C[i][j] = 0;
			else C[i][j] = C[i-1][j-1] + C[i][j-1];
		}	
	ll ans = 0;
	for(int i=0;i<=k;++i)
		ans += C[i][n] * p[i];
	cout << ans << '\n';
	return 0;
}

