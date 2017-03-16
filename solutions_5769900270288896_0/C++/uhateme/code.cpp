#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;



int main(){



    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int TC;
    cin>>TC;
    for(int ZZ=1;ZZ<=TC;ZZ++){
        int r,c,n;
        cin>>r>>c>>n;
        int ans=0;
        int p = r*c;
        if((r*c)/2 <n){
            if(r == 1 || c == 1){
                int  y = ((r*c)+1)/2;
                ans = (n-y)*2;
            }
            else if(r == 2 || c == 2){
                int  y = (r*c)/2;
                int z = n-y;
                if(z>2)
                {
                    ans +=4;
                    ans+=(z-2)*3;
                }else{

                ans+=z*2;
                }
            }

            else if(r==3 || c==3){
                if(p == 9){
                    if(n<=5){
                        ans = 0;
                    }
                    else if(n<=7){
                        ans+=(n-5)*3;
                    }
                    else if(n == 8)
                        ans = 8;
                    else
                        ans = 12;
                }
                else if(p == 12){
                        if(n<=8){
                            ans = (n-6)*2;
                        }
                    else if(n == 9)
                        ans = 7;
                    else if(n == 10 )
                        ans = 10;
                    else if(n == 11)
                        ans = 13;
                    else if(n == 12)
                        ans = 17;
                    }
                else if(p == 15){
                    if(n <=14)
                        ans = (n-8)*3;
                    else
                        ans = 22;
                }
            }
            else if(r==4 && c==4){
                if(n <=10)
                    ans = (n-8)*2;
                if(n<=14)
                    ans = 4 + (n-10)*3;
                else
                    ans = 16 + (n-14)*4;
            }


        }
        cout<<"Case #"<<ZZ<<": "<<ans<<endl;
    }

    return 0;
}
