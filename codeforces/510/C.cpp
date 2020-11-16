#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <complex>
#include <sstream>
#include <utility>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define OO (int) 1e9

using namespace std;

int gcd(int u, int v) {return (v != 0)?gcd(v, u%v):u;}

vector <int> adj[50];
bool vis[50];
int n;
string names[110];
int inDegree[50];
vector <int> topo;

bool bfs()
{
    queue <int> q;
    for(int i=0;i<26;i++)
        if(!inDegree[i]) q.push(i);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        topo.push_back(cur);

        for(int i=0;i<adj[cur].size();i++)
        {
            inDegree[adj[cur][i]]--;
            if(inDegree[adj[cur][i]]==0)
                q.push(adj[cur][i]);
        }
    }
    if(topo.size()!=26) return 0;
    return 1;
}

int main()
{
    //  ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>names[i];

    for(int i=0;i<n-1;i++)
    {
        int L=min(names[i].size(),names[i+1].size());
        bool flag=0;
        for(int j=0;j<L;j++)
        {
            if(names[i][j] == names[i+1][j]) continue;
            adj[names[i][j]-'a'].push_back(names[i+1][j]-'a');
            inDegree[names[i+1][j]-'a']++;
            flag=1;
            break;
        }
        if(!flag && names[i].length() > names[i+1].length())
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }

    if(!bfs())cout<<"Impossible"<<endl;
    else
    {
        for(int i=0;i<topo.size();i++) cout<<char(topo[i]+'a') ;
        cout<<endl;
    }
}
