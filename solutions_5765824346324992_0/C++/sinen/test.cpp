#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a, int b){
    if(a==0 or b==0){return a+b;}
    else{return gcd(b,a%b);}
}

int lcm(int a, int b){return (a*b)/gcd(a,b);}

void asd(){
    int b,n,a[1000],k=1,c[1000],v=0;
    cin >> b >> n;
    for(int i=0; i<b; i++){
            cin >> a[i];
            c[i]=a[i];
    }
    for(int i=0; i<b; i++){
            k=lcm(k,a[i]);
    }
    for(int j=0; j<k; j++){
            for(int i=0; i<b; i++){
                    if(c[i]==0){c[i]=a[i];}
                    if(c[i]==a[i]){v++;}
                    c[i]--;
            }
    }
    n%=v; if(n==0){n=v;}
    //reset
    for(int i=0; i<b; i++){c[i]=a[i];}
    while(n>0){
               for(int i=0; i<b; i++){
                       if(c[i]==0){c[i]=a[i];}
                       if(c[i]==a[i]){n--; v=i;}
                       c[i]--;
                       if(n==0){break;}
               }
               if(n==0){break;}
    }
    cout << v+1 << endl;
}

int main(){
    freopen ("B-small-attempt1.in","r",stdin);
    freopen ("B-small-attempt1.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
            cout << "Case #" << i << ": "; asd();
    }
    return 0;
}

