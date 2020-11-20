#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[200010],s1[200010];
int main()
{
    int tot=0,i,j;
    scanf("%s",s);
    int ls=strlen(s);
    for (i=0;i<ls;i++)
    {
        for (j=0;j<ls-i;j++)
            if (s[i]!=s[i+j])
                break;
        if (j==1)
        {
            s1[tot++]=s[i];
            continue;
        }
        if (j>1)
        {
            s1[tot++]=s[i];
            s1[tot++]=s[i];
            i=i+j-1;
            continue;
        }
    }
    for (i=0;i<tot;i++)
    {
        if (s1[i]==s1[i+1] && s1[i+2]==s1[i+3] && i+3<tot)
        {
            printf("%c%c%c",s1[i],s1[i+1],s1[i+2]);
            i+=3;
        }
        else printf("%c",s1[i]);
    }
    return 0;
}