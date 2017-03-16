#include <cstdio>
#include <fstream>
#include <iostream>
#define debug
#define _max 4
using namespace std;
FILE *fin,*fout = NULL;

int cards[_max][_max][2];                                             
             
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("A-small.in","r");
    int t,n,m;
    fscanf(fin,"%d",&t);

    for(int k=1;k<=t;k++){
       fscanf(fin,"%d",&n); 

       for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
         fscanf(fin,"%d",&cards[i][j][0]);
         }

        fscanf(fin,"%d",&m); 

       for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
         fscanf(fin,"%d",&cards[i][j][1]);
         }
        
        int count = 0,output=0;
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
         if(cards[n-1][i][0] == cards[m-1][j][1]){
           count++; 
           if(count == 1) output = cards[n-1][i][0];
         }
        }

        if(count==0)
         fprintf(fout,"Case #%d: Volunteer cheated!\n",k);
        else if(count==1)
          fprintf(fout,"Case #%d: %d\n",k,output);
        else
          fprintf(fout,"Case #%d: Bad magician!\n",k);
     
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}
