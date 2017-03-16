#include<bits/stdc++.h>

using namespace std;

int main()
{
    int te;
    ios::sync_with_stdio(false);
    cin>>te;
    for(int t=1;t<=te;t++)
    {
        cout<<"Case #"<<t<<": ";
        int n,m;
        cin>>n;
        pair<int,int> v[30];
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v[i].first=-a;
            v[i].second=i;
        }
        while(true)
        {
            bool achou=false;
            sort(v,v+n);
            if(v[0].first==0) break;
            if(v[0].first==v[1].first)
            {
                if(v[0].first!=-1)
                {
                    char aux = v[0].second+'A';
                    cout<<aux;
                    aux = v[1].second+'A';
                    cout<<aux;
                    v[1].first++;
                    v[0].first++;
                    cout<<" ";
                }
                else
                {
                    if(n>=3)
                    {
                        if(v[2].first==-1)
                        {
                            char aux = v[2].second+'A';
                            cout<<aux<<" ";
                            v[2].first++;
                        }
                        else
                        {
                            char aux = v[0].second+'A';
                            cout<<aux;
                            aux = v[1].second+'A';
                            cout<<aux;
                            v[1].first++;
                            v[0].first++;
                            cout<<" ";
                        }
                    }
                    else
                    {
                        char aux = v[0].second+'A';
                        cout<<aux;
                        aux = v[1].second+'A';
                        cout<<aux;
                        v[1].first++;
                        v[0].first++;
                        cout<<" ";
                    }
                }
            }
            else if(v[0].first==-2)
            {
                if(v[1].first==-1)
                {
                    if(n>=3)
                    {
                        if(v[2].first==0)
                        {
                            char aux = v[1].second+'A';
                            v[1].first++;
                            cout<<aux<<" ";
                        }
                        else
                        {
                            v[0].first+=2;
                            char aux=v[0].second+'A';
                            cout<<aux<<aux<<" ";
                        }
                    }
                    else
                    {
                        char aux = v[1].second+'A';
                        v[1].first++;
                        cout<<aux<<" ";
                    }
                }
                else
                {
                    v[0].first+=2;
                    char aux=v[0].second+'A';
                    cout<<aux<<aux<<" ";
                }
            }
            else if(v[0].first<-2)
            {
                v[0].first+=2;
                char aux=v[0].second+'A';
                cout<<aux<<aux<<" ";
            }
            else
            {
                char aux=v[0].second+'A';
                v[0].first++;
                cout<<aux;
            }
        }
        cout<<endl;
    }
    return 0;
}
