#include <bits/stdc++.h>

using namespace std;

int diff(char ch1, char ch2) {
    return min((int)abs(ch2-ch1), 26-(int)abs(ch2-ch1));
}


int n, p, sol, lo, hi, a, b, ops;
string s;


int sym(int i) {
    return n-i-1;
}

int main() {
    cin >> n >> p;
    cin >> s;
    
    p--;
    
    lo = n+1;
    hi = -1;
    if (p < n/2) {
        a = 0;
        b = n/2;
    }
    else {
        a = n/2;
        b = n;
    }
    for (int i = a; i < b; i++)
        if (s[i] != s[sym(i)]) {
            lo = min(lo, i);
            hi = max(hi, i);
        }
    if (hi == -1) {
        cout << 0 << endl;
        return 0;
    }
    
    //cout << lo << " " << hi << endl;
    ops = hi-lo;
    for (int i = lo; i <= hi; i++) {
        ops += diff(s[i], s[sym(i)]);
    }
    sol = min(abs(p-lo), abs(p-hi));
    sol += ops;
    
    cout << sol << endl;
}
