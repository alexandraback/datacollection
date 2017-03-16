#include<bits/stdc++.h>
using namespace std;
struct node
{
    char x;
    int f;
}e;

struct comp
{
    bool operator()(const node &a,const node &b)
    {
        if(a.f == b.f)
            return a.x>b.x;
        return a.f<b.f;
    }
};

int main()
{
    int i,sum, n,t,r,a[30];
    bool flag;
    cin>>t;

    for(r = 1; r <= t; r++){
        cin>>n;
        priority_queue<node,vector<node>,comp> q;
        sum = 0;
        for(i = 0; i < n; i++){
            cin>>a[i];
            e.f = a[i];
            e.x = 'A' + i;
            q.push(e);
            sum+=a[i];
        }
        printf("Case #%d: ", r);
        while(!q.empty()){
            e = q.top();
            q.pop();
            printf("%c", e.x);
            e.f = e.f - 1;
            sum--;
            a[e.x - 'A']--;
            if(e.f > 0)
            {
                q.push(e);
            }
            flag = false;
            for(i = 0; i < n; i++){
                if(a[i] > (sum/2)){
                    flag = true;
                    break;
                }
            }

            if(flag){
                e = q.top();
                q.pop();
                printf("%c", e.x);
                e.f = e.f - 1;
                a[e.x - 'A']--;
                sum--;
                if(e.f > 0)
                {
                    q.push(e);
                }
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
