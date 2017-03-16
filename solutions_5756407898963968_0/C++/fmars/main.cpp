#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k1,k2,k,i,j,c,r;
    FILE*file=fopen("out.txt","w+");
    FILE*filein=fopen("in.txt","r");
    fscanf(filein,"%d",&n);
    for( i=0;i<n;i++){
            vector<vector<int> > v1,v2;
    fscanf(filein,"%d",&k1);
     for(r=0;r<4;r++){
        vector<int>t;
        for(c=0;c<4;c++){
    fscanf(filein,"%d",&k);
            t.push_back(k);
        }
        v1.push_back(t);
     }
    fscanf(filein,"%d",&k2);
     for(r=0;r<4;r++){
        vector<int>t;
        for(c=0;c<4;c++){
    fscanf(filein,"%d",&k);
            t.push_back(k);
        }
        v2.push_back(t);
     }
     int number=0,result=0;
     for(j=0;j<4;j++)
        for(k=0;k<4;k++)
            if(v1[k1-1][j]==v2[k2-1][k]){
                    number++;
                    result=v1[k1-1][j];
            }
    fprintf(file,"Case #%d: ",i+1);
    if(number==0)
        fprintf(file,"Volunteer cheated!\n");
    else if(number==1)
        fprintf(file,"%d\n",result);
    else
        fprintf(file,"Bad magician!\n");
     }
     fclose(file);
    return 0;
}
