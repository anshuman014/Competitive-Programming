#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 0
#define nmax 111
int m,s;
int a[nmax];
int b[nmax];
int main(){
    cin>>m>>s;
    if (s==0){
        if (m==1) cout<<"0 0"<<endl; else  cout<<"-1 -1"<<endl;
    }else {
        if(m*9<s) cout<<"-1 -1"<<endl; else {
            FOR(i,1,m) a[i]=b[i]=0;
            a[1]=b[1]=1;
            s--;
            int tmp=s;
            //BUG(s);
            DFOR(i,m,1){
                int value=min(9-a[i],s);
                a[i]+=value;
                s-=value;
                if (s==0) break;
            }
            s= tmp;
            FOR(i,1,m){
                int value= min(9-b[i],s);
                b[i]+=value;
                s-=value;
                if (s==0) break;
            }
            FOR(i,1,m) cout<<a[i]; cout<<" "; FOR(i,1,m) cout<<b[i]; cout<<endl;
        }
    }
    return 0;
}
