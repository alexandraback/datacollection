//
//  Haircut.cpp
//  
//
//  Created by Jefvin Viriya on 18/4/15.
//
//

#include <cstdio>
#include <cstdlib>

long long int gcd(long long int a,long long int b){
    long long int temp;
    while(b!=0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

long long int lcm(long long int a,long long int b){
    return (a*b)/gcd(a,b);
}

int main(){
    int t,n,b;
    int m[10000];
    int timer[10000];
    int i,j,k;
    int max;
    long long int kpk;
    long long int oneLoop;
    int res;
    scanf("%d",&t);
    
    for(int c=1;c<=t;c++){
        scanf("%d %d",&b,&n);
        for(i=0;i<b;i++){
            scanf("%d",&m[i]);
            if(i==1){
                kpk = lcm(m[i-1],m[i]);
            }else if(i>1){
                kpk = lcm(m[i],kpk);
            }
        }
        //printf("%lld\n",kpk);
        oneLoop = 0;
        for(i=0;i<b;i++){
            m[i] = kpk/m[i];
            oneLoop += m[i];
            timer[i] = kpk;
        }
        
        if(n>oneLoop){
            n%=oneLoop;
        }
        //printf("%d\n",n);
        if(n==0){
            n = oneLoop;
        }
        res = 1;
        i=0;
        while(true){
            if(timer[i]==kpk){
                timer[i] = m[i];
                if(n==1){
                    res = (i+1);
                    break;
                }else{
                    n--;
                }
            }else{
                timer[i] += m[i];
            }
            i++;
            i%=b;
        }
        
        printf("Case #%d: %d\n",c,res);
        
    }
    
    return 0;
}