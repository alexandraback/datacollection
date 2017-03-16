
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#define maxv 100000

using namespace std;




void input(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
}

void init(){

}

int rev(int u) {

}

void solve(){
    int T;
    int n,R,C,res,subres,subn;
    int temp;
    int pos1,pos2,pos3,pos4;
    cin>>T;
    for (int t=0; t<T; t++) {
        pos1=0;
        pos2=0;
        pos3=0;
        pos4=0;
        res =-1;
        cin>>R>>C>>n;
        if (C%2==1) {
            temp = R;
            R=C;
            C=temp;
        }

        if (n<=R*C/2-1) {
            res=0;
        }
        if (res==-1) {
            res=0;
            if (R==1 || C==1) {
                if (R>C) {
                    temp = R;
                    R=C;
                    C=temp;
                }
                if (R*C==1) {
                    res=0;
                } else {
                    if (C%2==0) {
                        pos1=1;
                        pos2=C/2-1;
                        n=n-C/2;
                        if (n>0) {
                            res+=min(pos1,n);
                            n-=pos1;
                        }
                        if (n>0) {
                            res+=min(pos2,n)*2;
                            n-=pos2;
                        }
                    } else {
                        subn=n;
                        pos1=0;
                        pos2=C/2;
                        n=n-C/2-1;
                        if (n>0) {
                            res+=min(pos1,n);
                            n-=pos1;
                        }
                        if (n>0) {
                            res+=min(pos2,n)*2;
                            n-=pos2;
                        }
                        //way 2
                        n=subn;
                        subres=0;
                        pos1=2;
                        pos2=C/2-1;
                        n=n-C/2;
                        if (n>0) {
                            subres+=min(pos1,n);
                            n-=pos1;
                        }
                        if (n>0) {
                            subres+=min(pos2,n)*2;
                            n-=pos2;
                        }
                        res=min(res,subres);
                    }

                }
            } else {

                if (R%2==0 && C%2==0) {
                    pos2=2;
                    pos3=max(R+C-4,0);
                    pos4=R*C/2-pos2-pos3;
                    n=n-R*C/2;
                    if (n>0) {
                        res+=min(pos2,n)*2;
                        n-=pos2;
                    }
                    if (n>0) {
                        res+=min(pos3,n)*3;
                        n-=pos3;
                    }
                    if (n>0) {
                        res+=min(pos4,n)*4;
                        n-=pos4;
                    }
                } else if (R%2==1 && C%2==0) {
                    pos2=2;
                    pos3=max(R+C-4,0);
                    pos4=R*C/2-pos2-pos3;
                    n=n-R*C/2;
                    if (n>0) {
                        res+=min(pos2,n)*2;
                        n-=pos2;
                    }
                    if (n>0) {
                        res+=min(pos3,n)*3;
                        n-=pos3;
                    }
                    if (n>0) {
                        res+=min(pos4,n)*4;
                        n-=pos4;
                    }
                } else if (R%2==1 && C%2==1) {
                    subn=n;
                    pos2=0;
                    pos3=max(R+C-2,0);
                    pos4=R*C/2-1-pos2-pos3;
                    n=n-R*C/2-1;
                    if (n>0) {
                        res+=min(pos2,n)*2;
                        n-=pos2;
                    }
                    if (n>0) {
                        res+=min(pos3,n)*3;
                        n-=pos3;
                    }
                    if (n>0) {
                        res+=min(pos4,n)*4;
                        n-=pos4;
                    }
                    //way2
                    n=subn;
                    subres=0;
                    pos2=4;
                    pos3=max(R+C-6,0);
                    pos4=R*C/2+1-pos2-pos3;
                    n=n-R*C/2;

                    if (n>0) {
                        subres+=min(pos2,n)*2;
                        n-=pos2;
                    }
                    if (n>0) {
                        subres+=min(pos3,n)*3;
                        n-=pos3;
                    }
                    if (n>0) {
                        subres+=min(pos4,n)*4;
                        n-=pos4;
                    }
                    res=min(res,subres);
                }
            }
        }

        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
}

void output(){

}

void process(){
    input();
    solve();
    output();
}

int main() {
    process();
    return 0;
}

