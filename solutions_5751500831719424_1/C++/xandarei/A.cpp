#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

string pal(string t)
{
    string aux = "";
    char ant = ' ';
    for(int i=0;i<t.size();i++)
    {
        if(ant != t[i])
        {
            aux += t[i];
        }
        ant = t[i];
    }
    return aux;
}

int main()
{
    int i, T, n;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    string s[101], aux;
    int mapa[101][101];
    bool check;
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        cin>>n;
        check = true;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        aux = pal(s[0]);
        for(int i=1;i<n;i++)
        {
            check = check and pal(s[i])==aux;
        }
        cout<<"Case #"<<k<<": ";
        if(check)
        {
            memset(mapa,0,sizeof mapa);
            for(int i=0;i<n;i++)
            {
                char ant = s[i][0];
                int cont = 1;
                int x=0;
                for(int j=1;j<s[i].size();j++)
                {
                    if(s[i][j] != ant)
                    {
                        mapa[i][x] = cont;
                        cont = 1;
                        x++;
                    }
                    else
                    {
                        cont++;
                    }
                    ant = s[i][j];
                }
                mapa[i][x] = cont;
            }
            int mini[aux.size()];
            int conta[aux.size()];

            for(int i=0;i<aux.size();i++)
            {
                mini[i] = 100000;
            }
            for(int m=1; m<101;m++)
            {
                memset(conta,0,sizeof conta);
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<aux.size();j++)
                    {
                        conta[j] += abs(m-mapa[i][j]);
                    }
                }
                for(int i=0;i<aux.size();i++)
                {
                    if(conta[i]< mini[i])
                        mini[i] = conta[i];
                }
            }
            int res = 0;
            for(int i=0;i<aux.size();i++)
                res += mini[i];
            cout<<res<<endl;

        }
        else
        {
            cout<<"Fegla Won"<<endl;
        }
    }
    return 0;
}
