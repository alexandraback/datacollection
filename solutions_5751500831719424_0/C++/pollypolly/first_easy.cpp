#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s1[109], s2[109];
int T, N, K;

int myabs (int a){
    if (a < 0) return -a;
    return a;
}

int main (){
    scanf ("%d",&T);

    for (int t=0; t<T; t++){

        scanf ("%d",&K);
        scanf ("%s %s",s1, s2);

        int n = strlen (s1);
        int m = strlen (s2);
        int b = 0;

        int i=0, j=0;
        int ans = 0;

        while (1){
            if (i == n) break;
            if (j == m) break;

            if (s1[i] == s2[j]){i++;j++; continue;}

            if (i!=0) if (s1[i] == s1[i-1]){ans++; i++; continue;}
            if (j!=0) if (s2[j] == s2[j-1]){ans++; j++; continue;}

            b = 1; break;
        }

        for (;i<n; i++)
            if (i!=0){ if (s1[i] != s1[i-1]) b = 1;
                else ans++;}
        for (;j<m; j++)
            if (j!=0){ if (s2[j] != s2[j-1]) b = 1;
                else ans++;}

        if (b == 1) printf ("Case #%d: Fegla Won\n",t+1);
        else printf ("Case #%d: %d\n",t+1,ans);
    }
    return 0;
}
