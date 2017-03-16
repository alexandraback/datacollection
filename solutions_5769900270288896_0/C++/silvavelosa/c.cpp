#include<bits/stdc++.h>
using namespace std;
int r,c,n,ret;
int nCases;
int main (void)
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    cin>>nCases;
    for(int aCase = 1;aCase <= nCases;aCase++)
    {
        ret = 0;
        cin>>r>>c>>n;
        if(r==1 || c ==1)
        {
            if(n*2 <= r*c+1)
               {
                cout<<"Case #"<<aCase<<": "<<0<<endl;
                continue;
               }

            else
            {
                n-= (int)((r*c+1)/2);
                if((r*c)%2 == 0)
                {
                    if(n<=1)
                        {
                        cout<<"Case #"<<aCase<<": "<<n<<endl;
                        continue;

                        }
                    else
                    {
                        cout<<"Case #"<<aCase<<": "<<2*(n-1)+1<<endl;
                        continue;
                    }
                }
                else
                {
                    cout<<"Case #"<<aCase<<": "<<2*n<<endl;
                    continue;
                }
            }
            continue;
        }
        if(n*2 <= r*c+1)
        {
            cout<<"Case #"<<aCase<<": "<<0<<endl;
            continue;

            }
        else
        {
            n-= (int)((r*c+1)/2);
            if((r*c)%2 == 0 && n<=2)
            {
                cout<<"Case #"<<aCase<<": "<<2*n<<endl;
                continue;

                }
            else if((r*c)%2 && 2<=n && n<=3)
            {
                cout<<"Case #"<<aCase<<": "<<2*(n+1)<<endl;
                continue;
            }
            else if((r*c)%2 && 1==n)
            {
                cout<<"Case #"<<aCase<<": "<<3<<endl;
                continue;
            }
            else
            {
                //cout<<"n = " <<n<<" ret = "<<ret<<endl;
                if((r*c)%2 == 0)
                {
                    n-=2;
                    ret+=4;
                }
                else if((r*c)%2 && 2<=n)
                {
                    n-=3;
                    ret+=8;
                }
                //cout<<"n = " <<n<<" ret = "<<ret<<endl;
                if(n <= r-3)
                {
                    cout<<"Case #"<<aCase<<": "<<ret+3*n<<endl;
                    continue;

                }
                else
                {
                    if(r>2)
                    {
                        ret+=3*(r-3);
                        n-=r-3;
                        if((c*r)%2 == 0)
                        {
                            ret+=3;
                            n--;
                        }
                        else if(c%2 == 0)
                        {
                            ret+=3;
                            n--;
                            if(n)
                            {
                                ret+=3;
                                n--;
                            }
                        }
                    }
                    //cout<<"n = " <<n<<" ret = "<<ret<<endl;
                    if(n <= c-3)
                    {
                        cout<<"Case #"<<aCase<<": "<<ret+3*n<<endl;
                        continue;
                    }
                    else
                    {
                        if( c>2 )
                        {
                            ret+=3*(c-3);
                            n-=c-3;
                            if((c*r)%2 == 0)
                            {
                                ret+=3;
                                n--;
                            }
                            else if(r%2 == 0)
                            {
                                ret+=3;
                                n--;
                                if(n)
                                {
                                    ret+=3;
                                    n--;
                                }
                            }
                        }
                        //cout<<"n = " <<n<<" ret = "<<ret<<endl;
                        cout<<"Case #"<<aCase<<": "<<ret+4*n<<endl;
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}

