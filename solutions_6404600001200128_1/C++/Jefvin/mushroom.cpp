//
//  mushroom.cpp
//  
//
//  Created by Jefvin Viriya on 18/4/15.
//
//

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
    int t,n;
    long long int m[10000];
    int i,j,k;
    long long int y,z,diffMax;
    scanf("%d",&t);
    
    for(int c=1;c<=t;c++){
        scanf("%d",&n);
        y = 0;
        diffMax = 0;
        for(i=0;i<n;i++){
            scanf("%lld",&m[i]);
            if(i>=1){
                //printf(" a %d %d\n",m[i-1],m[i]);
                if(m[i-1]>m[i]){
                    y += (m[i-1]-m[i]);
                    //printf("dasa %d\n",y);
                    diffMax = max(diffMax,(m[i-1]-m[i]));
                }
            }
        }
        z=0;
        for(i=0;i<n-1;i++){
            if(m[i]<diffMax){
                z+=m[i];
            }else{
                z+=diffMax;
            }
        }
        printf("Case #%d: %lld %lld\n",c,y,z);
        
    }
    
    return 0;
}
