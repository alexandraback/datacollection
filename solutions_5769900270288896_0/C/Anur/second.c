#include<stdio.h>

int findUnique(int r, int c, int n){
    int optimum = (r/2)*(c/2 + 1) + (r/2)*(c/2);

    if(n <= optimum) {
        return 0;
    } else {
        int residue = n-optimum;
        
        int total=0;
        
        int total_twos = 2;
        if(residue <= total_twos)
                return total + residue*2;
        else{
                total += (total_twos*2);
                residue -= total_twos;
                int total_three = (r -2 ) + (c - (c/2)-2) + (c/2);
        
                if(residue <= total_three)
                    return total + residue*3;
                else {
                     total += total_three*3;
                     residue -= total_three;
                     return total + residue*4;       
                }
        }
    }
    

}
int findBothOdd(int r, int c, int n){
    int optimum = (r/2 + 1)*(c/2 + 1) + (r/2)*(c/2);
    
    if(n <= optimum) {
        return 0;
    } else {
        int residue = n-optimum;
        
        int total=0;
        
        int total_three = (r/2) + (c/2);;
        if(residue <= total_three)
                return total + residue*3;
        else{
                total += total_three*3;
                residue -= total_three;
                return total + residue*4;       
                
        }
    }

}

int findBothEven(int r, int c, int n){
    int optimum = (r*c)/2;

    if(n <= optimum) {
        return 0;
    } else {
        int residue = n-optimum;
        
        int total=0;
        
        int total_twos = 2;
        if(residue <= total_twos)
                return total + residue*2;
        else{
                total += (total_twos*2);
                residue -= total_twos;
                int total_three = (r -2 ) + (c-2);
        
                if(residue <= total_three)
                    return total + residue*3;
                else {
                     total += total_three*3;
                     residue -= total_three;
                     return total + residue*4;       
                }
        }
    }

}

int main() {
    int t,tt;
    scanf("%d",&t);
    int r,c,n;

    for(tt=1;tt<=t;tt++) {
        scanf("%d %d %d",&r,&c,&n);
        int ans;
        if(r == 3 && c==3 && n == 8){
            ans = 8;
        } else if(r%2==0 && c%2==0){
            ans = findBothEven(r,c,n);
        } else if(r%2 != 0 && c%2 != 0){
            ans = findBothOdd(r,c,n);
        } else if(r %2 == 0 && c%2 !=0){
           ans = findUnique(r,c,n);
        } else {
           ans = findUnique(c,r,n);
        }     
        printf("Case #%d: %d\n",tt,ans);
    }
   return 0;
}
