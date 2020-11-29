
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int n,k;
int a[sz];

void solve() {
    cin>>n>>k;
    foru(i,0,n)cin>>a[i];
    int bst=1e9;
    for (int c = 1; c <= 100; c++) {
        int cr=0,until=0;
        foru(i,0,n){
            if(a[i]==c)continue;
            else if (i>=until){
                cr++;
                until=i+k;
            }
        }
        bst=min(bst,cr);
    }
    cout<<bst<<'\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}