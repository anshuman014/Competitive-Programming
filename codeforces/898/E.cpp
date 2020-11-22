#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

using namespace std;

const int N = (3e5), mod = (1e9) + 7;

pair <ll,ll> p[N];

int n;

int main(){
	scanf("%d", &n);
	for(int i = 1,x; i <= n; i++){
		scanf("%d", &x);
		int v = (int)sqrt(x);
		ll cnt = mod;
		for(int j = v - 2; j <= v + 2; j++){
			if(j >= 0 && 1ll * j * j >= x){
				cnt = min(cnt, 1ll * j * j - x);
			}
		}
		for(int j = v - 2; j <= v + 2; j++){
			if(j >= 0 && 1ll * j * j <= x){
				cnt = min(cnt, x - 1ll * j * j);
			}
		}
		p[i] = mp(cnt, x);
	}
	sort(p + 1, p + n + 1);
	ll ans = 0;
	for(int i = 1; i <= n / 2; i++){
		ans += p[i].f;
	}
	for(int i = n / 2 + 1; i <= n; i++){
		if(p[i].f == 0){
			if(p[i].s == 0) ans += 2;
			else ans++;
		}
	}
	printf("%lld", ans);
	
 	return 0;
}             