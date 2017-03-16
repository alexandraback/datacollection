#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    freopen("Alarge.in","r+",stdin);
    freopen("A_out1.txt","w+",stdout);
    int T;
    cin>>T;
    for(int e=1;e<=T;++e)
    {
        cout<<"Case #"<<e<<": ";
        LL N , i ;
        cin>>N;
        vector < LL > A(N);
        LL sum = 0;
        for(i=0;i<N;++i)
        {
            cin>>A[i];
            sum+=A[i];
        }

        for(;sum;)
        {
            LL max_ele = 0,f=0;
            for(i=0;i<N;++i)
                max_ele = max(A[i],max_ele);
            vector < int > ele;
            for(i=0;i<N;++i)
                if(A[i]==max_ele)
                    ele.push_back(i);


            if(ele.size()&1)
            {
                sum--;
                for(i=0;i<N;++i)
                    if(A[i]==max_ele)
                    {
                        cout<<char('A'+i)<<" ";
                        A[i]--;
                        break;
                    }
            }
            else
            {
                sum-=2;
                int x= *ele.rbegin();
                ele.pop_back();
                int y = *ele.rbegin();
                ele.pop_back();
                A[x]--;
                A[y]--;
                cout<<char('A'+x)<<""<<char('A'+y)<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}
