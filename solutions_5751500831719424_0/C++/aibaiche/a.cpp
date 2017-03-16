#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#define debug
#define lp(i,n) for(int i=0;i<n;i++)
#define lpb(i,n) for(int i=1;i<=n;i++)
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))

#define _max 12
#define inf 0xfffffff
using namespace std;
FILE *fin,*fout = NULL;

vector <string> out;
char iii[110];
char x;
int cou[110];
int t,l,n,sum,sss,tem,tx;
string ns[110];

//int cc[110][27];
vector <int>cc[110];
int main(){

    
    fout= fopen("out.txt","w");
    fin = fopen("a.in","r");
    //fin = fopen("A-large.in","r");
    
    fscanf(fin,"%d",&t);
    lpb(kk,t){
      //memset(cc,0,sizeof(cc));
      out.clear();
      fscanf(fin,"%d",&n);

      lp(i,n){cc[i].clear();
        fscanf(fin,"%s",iii);
        ns[i] = iii; 
        int ii = 1;
        //cc[i][iii[0]-'a'] = 1;
        cc[i].push_back(iii[0]-'a');
        char tem = iii[0];
        sum = 1;
        while(iii[ii]){
          if( tem == iii[ii]){
            //cc[i][iii[ii]-'a']++;
            sum++;
            //sum += cou[i];
          }else{
              cc[i].push_back(sum);
              cc[i].push_back(iii[ii]-'a');  
              sum = 1;
             //cc[i][iii[ii]-'a'] = 1;
            //tt+=iii[ii];
            tem = iii[ii];
          }
          ii++;
        } 
        cc[i].push_back(sum);
        //out.push_back(tt); 
      }
      //cout<<kk<<endl;
      //lp(i,n){ lp(j,cc[i].size()){cout<<cc[i].at(j)<<" ";}cout<<endl;  }
      sum = 0;
      int siz = cc[0].size();
      lp(i,n){
          if(cc[i].size()!=siz){sum=-1;break;}    
      }
      if(sum==-1){fprintf(fout,"Case #%d: Fegla Won\n",kk);continue;}
      
      
      for(int i=0;i<siz;i+=2){
              
            int now = cc[0].at(i);
            
            lp(j,n){
                if(cc[j].at(i) != now){sum=-1;break;} 
                 cou[j] = cc[j].at(i+1);  
            }
            //cout<<sum<<" "<<now<<endl;
            if(sum==-1) break;
            
            sort(cou,cou+n);
                 if(n%2==1){sss = cou[n/2];}
                 else { sss = (cou[n/2] + cou[n/2-1])/2; }
                 tx = 0;
                 lp(j,n){tx+= abs(cou[j]-sss);}
                 
            
            sum+=tx; 
      }
      if(sum==-1 )
        fprintf(fout,"Case #%d: Fegla Won\n",kk);
      else
      fprintf(fout,"Case #%d: %d\n",kk,sum);
      //cout<<sum<<endl;
}
      //fprintf(fout,"Case #%d: %d\n",kk,sum);

    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}





