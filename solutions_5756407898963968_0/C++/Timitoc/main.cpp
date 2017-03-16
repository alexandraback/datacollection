#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, rez[10], r1, r2, nq, a[10][10], b[10][10];

void citire()
{
    scanf("%d", &r1);
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            scanf("%d", &a[i][j]);
    scanf("%d", &r2);
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            scanf("%d", &b[i][j]);

}

void solve(int x[10], int y[10], int comp[10])
{
    nq=0;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++)
            if(x[i]==y[j]){
                comp[nq++] = x[i];
                break;
            }
    }
}

void afisare(int crt)
{
    printf("Case #%d: ", crt);
    if(nq==0)
        printf("Volunteer cheated!");
    else if(nq > 1)
        printf("Bad magician!");
    else
        printf("%d", rez[0]);
    printf("\n");
}

int main()
{
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);

    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        citire();
        solve(a[r1], b[r2], rez);
        afisare(i);
    }

    return 0;
}
