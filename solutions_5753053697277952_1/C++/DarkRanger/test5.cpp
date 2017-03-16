#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &l, const pair<int, int> &r)
{
    return l.second>r.second;
}

int main()
{
    freopen("a2.in","r",stdin);
    freopen("out2.out","w",stdout);

    int i,j,k,n;
    int t;
    int x,y;
    int sum;
    int cases;

    cin>>cases;

    t=1;
    while(t<=cases)
    {
        cin>>n;
        vector<pair<int, int> > a(n);

        sum=0;
        for(i=0;i<n;i++)
        {
            a[i].first=i;
            cin>>a[i].second;
            sum+=a[i].second;
        }
        
        cout<<"Case #"<<t<<": ";

        sort(a.begin(),a.end(),compare);
        
        //loop until top element is 0
        j=(sum+2)/2;
        
        while(a[0].second>0)
        {
            //take an element
            x=a[0].first;
            a[0].second--;
            sum--;
            j=(sum+2)/2;
            sort(a.begin(),a.end(),compare);
            cout<<(char)('A'+x);

            while(a[0].second>0 && a[0].second>=j)
            {
                x=a[0].first;
                a[0].second--;
                sum--;
                j=(sum+2)/2;
                sort(a.begin(),a.end(),compare);
            
                cout<<(char)('A'+x);
            }

            cout<<" ";

        }
       
        cout<<endl;

        t++;
    }

    return 0;
}
