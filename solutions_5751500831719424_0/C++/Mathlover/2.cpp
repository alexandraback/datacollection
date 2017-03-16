#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstdio>

using namespace std;

bool _max(double a, double b){
     return a>b;     
}
bool _min(double a, double b){
     return a<b;     
}

int num[102][102];
string str[102];
string make_short(string s){
       string t = "";
       t += s[0];
       for(int i = 1; i < s.size(); i++){
            if(s[i]==s[i-1]) continue;
            else t+=s[i];       
       }
       return t;       
}
int maxn[102];
int main(int argc, char *argv[])
{
    //ifstream fcin("C:\\Users\\zdb\\Downloads\\B-large.in");
    ifstream fcin("C:\\Users\\zdb\\Downloads\\A-small-attempt3.in");
    //ifstream fcin("C:\\Users\\zdb\\Downloads\\test.txt");
    //ifstream fcin("file.txt");
    ofstream fcout("ans2.txt");
    int T; fcin >> T;
    for(int i = 1; i <= T; i++){
         int N; fcin >> N;
         for(int j = 0; j < N; j++) fcin >> str[j];
         memset(num, -1, sizeof(num));
         string com = make_short(str[0]);
         bool lose = false;
         for(int j = 1; j < N; j++){
                 string tmp = make_short(str[j]); 
                 if(com != tmp){
                        lose = true;
                        break;
                 }       
         }
         if( lose) {
              fcout << "Case #" << i << ": Fegla Won\n";
              continue;      
         }
         for(int j = 0; j < N; j++){
                 int cnt = 0;
                 num[j][cnt] = 1;
                 for(int k = 1; k < str[j].size(); k++){
                      if(str[j][k]==str[j][k-1]){
                          num[j][cnt]++;                           
                      } else {
                          cnt ++;
                          num[j][cnt] = 1;
                      }   
                 }        
         }
         memset(maxn,-1,sizeof(maxn));
         for(int j = 0;; j++){
             if(num[0][j]<0) break;
             for(int k = 0; k < N; k++){
                     if(maxn[j] < num[k][j]) maxn[j]=num[k][j];        
             }
         }
         
         int ans = 0;
         for(int j = 0;; j++){
             if(num[0][j]<0) break;
             int min_tmp = 100000000;
             int tmp;
             for(int t = 1; t <= maxn[j]; t++){
                 tmp = 0;
                 for(int k = 0; k < N; k++){
                         if(num[k][j] < t) tmp +=t-num[k][j];
                         else if(num[k][j]>t) tmp+= num[k][j]-t;        
                 }
                 if(min_tmp > tmp)
                 min_tmp = tmp;
             }
             ans += min_tmp;
         }
         
         fcout << "Case #" << i << ": ";   
         fcout << ans << endl; 
    }    
    system("PAUSE");
    return EXIT_SUCCESS;
}
