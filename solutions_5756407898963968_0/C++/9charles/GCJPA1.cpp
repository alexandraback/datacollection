#include<cstdio>  
#include<cstring>  
#include<cctype>  
#include<cmath>  
#include<cstdlib>  
#include<ctime>  
#include<iostream>  
#include<iomanip>  
#include<sstream>  
#include<vector>  
#include<string>  
#include<queue>  
#include<stack>  
#include<utility>  
#include<algorithm>  
#include<map>  
#include<set>  
#include<bitset>  
#include<sstream>
using namespace std;
typedef long long int ll;

int main(){
    int T,r1,r2,a;
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++){
        scanf("%d",&r1);
        r1--;
        set<int > s1;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&a);
                if(i==r1){s1.insert(a);}
            }
        }
        scanf("%d",&r2);
        r2--;
        int c=0, y;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&a);
                if(i==r2){
                    if(s1.count(a)){
                        c++;
                        y=a;
                    }    
                }
            }
        }
        printf("Case #%d: ",caso);
        if(c==1){printf("%d",y);}
        else if(c>1){printf("Bad magician!");}
        else{printf("Volunteer cheated!");}
        printf("\n");
    }
    return 0;
}
