#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int mxn=203;

vector<int> indexa;
int mina[3002];
int X[3002], Y[3002];

struct point
{
    long long x,y;
}p[mxn],stk[mxn];
int n,top;

inline bool cmp(point p1,point p2)
{
    return p1.y<p2.y||p1.y==p2.y&&p1.x<p2.x;
}

inline bool ral(point p1,point p2,point p3)
{
    return (p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y)<=0;
}

bool check(vector<int>& a, int j)
{
    n = a.size();
    for(int i=1;i<=n;i++) {p[i].x = X[a[i-1]]; p[i].y = Y[a[i-1]];}
    sort(p+1,p+n+1,cmp);
    stk[1]=p[1];top=1;
    for(int i=2;i<=n;i++)
    {
        while(top!=1&&ral(stk[top-1],stk[top],p[i])) top--;
        stk[++top]=p[i];
    }
    int len=top;
    for(int i=n-1;i>=1;i--)
    {
        while(top!=len&&ral(stk[top-1],stk[top],p[i])) top--;
        stk[++top]=p[i];
    }

    for(int i = 1; i <= top; i++)
        if(stk[i].x == X[j] && stk[i].y == Y[j])
            return true;
    return false;
}

void enumerate(int N, int num, int j){
    if(N == 0){
        if(num < mina[j] && check(indexa, j))
            mina[j] = num;
    }
    else{
        N--;
        indexa.push_back(N);
        enumerate(N, num, j);
        indexa.pop_back();
        enumerate(N, num+1, j);
    }
}

int main(int argc, char *argv[]){
    freopen("c.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int N;
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> X[j] >> Y[j];
            mina[j] = N;
        }
        for(int j = 0; j < N; j++){
            enumerate(N, 0, j);
        }


        cout << "Case #" << i+1 << ":"<< endl;
        for(int j = 0; j < N; j++)
            cout << mina[j] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
