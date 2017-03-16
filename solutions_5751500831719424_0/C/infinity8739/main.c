#include <stdio.h>
#include <stdlib.h>

int pos[105];
char s[105][105];
long jumlah,dist,dist_total,dist_min;
int max,min;
int hitung[105];
int keluar;
char karakter;

int main()
{
     int tcasenum;
     
     int tcaseloop;
     
     int i,j;
     int N;
     
     
     FILE *fin,*fout;
  fin=fopen("data.in","r");
  fout=fopen("data.out","w");

  fscanf(fin,"%d",&tcasenum);
  
  for(tcaseloop=0;tcaseloop<tcasenum;tcaseloop++)
  {
                                                 
     keluar=0;
     fscanf(fin,"%d",&N);
     
     dist_total=0;
     
     for (i=0;i<N;i++)
     {
      fscanf(fin,"%s",&s[i]);
      pos[i]=0;
     }
          
     while(pos[0]<strlen(s[0]))
     {
        karakter=s[0][pos[0]];
        hitung[0]=0;
        while(s[0][pos[0]]==karakter)
        {
        hitung[0]++;
        pos[0]++;
        }
        
        for (i=1;i<N;i++)
            hitung[i]=0;
        
        
        for (i=1;i<N;i++)
        {
           if (s[i][pos[i]]==karakter)
           {
               while (s[i][pos[i]]==karakter)
               {
                     hitung[i]++;
                     pos[i]++;
               }
           }
           else
           {
               fprintf(fout,"Case #%d: Fegla Won\n",tcaseloop+1);
               keluar=1;
               break;                
           }                           
        }
        
        if (keluar) break;
        
        
        
        
        

        dist_min=10000000;
        
        for (j=1;j<=100;j++)
        {
        jumlah=j;
        dist=0;
        for (i=0;i<N;i++)
        {
            if (hitung[i]>jumlah)
            dist+=(hitung[i]-jumlah);
            else
            dist+=(jumlah-hitung[i]);
        }
            if (dist<dist_min)dist_min=dist;
        }   
                                  
        
        dist_total+=dist_min;                          
     }
     
     
     
     if (!keluar)
     {
                 
     fprintf(fout,"Case #%d: %ld\n",tcaseloop+1,dist_total);                   
     }
  }

  
  
  fclose(fin);
  fclose(fout);
   
  return 0;
}
