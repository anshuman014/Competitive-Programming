#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, f[1000001], A, B;
char str[1000011];
bool b[1000001];

int main(){
    // freopen("c.in", "r", stdin);
    // freopen("c.out", "w", stdout);
     scanf("%s", str + 1);
     n = strlen(str + 1);
     if (str[1] == '0')
     {
          printf("NO\n");
          return 0;
     }
     scanf("%d%d", &A, &B); 
     memset(b, false, sizeof(b));
     for (int i = 1, j = 0; i <= n; i++)
     {
          j = (j * 10 + str[i] - '0') % A;
          if (!j) b[i] = true;
     }
     f[0] = 1;
     for (int i = 1; i <= n; i++) f[i] = f[i - 1] * 10 % B;
     for (int i = n, j = 0; i > 1; --i)
     {
          j += f[n - i] * (str[i] - '0') % B;
          j %= B;
          if (!j && str[i] != '0' && b[i - 1])
          {
               printf("YES\n");
               for (int k = 1; k < i; k++) printf("%c", str[k]);
               printf("\n");
               for (int k = i; k <= n; k++) printf("%c", str[k]);
               printf("\n");
               return 0;
          }
     }
     printf("NO\n");
     return 0;
}
