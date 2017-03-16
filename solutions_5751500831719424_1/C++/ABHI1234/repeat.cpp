#include<iostream>
#include<cmath>
using namespace std;
  int t,i,l=1,current[100],offset[100],m[100],x[101];
  int ans,n;
  string a[100];
bool cond(){
bool var = false;
for(i=0;i<n;i++)
  var = var | (current[i] < m[i]);
return var;
}
bool cond2(){
  for(i =1 ;i<n;i++)
    if(a[i][current[i]]!=a[0][current[0]])
      return true;
  return false;
}
int mode(){
  for(i=0;i<101;i++){
    x[i] = 0;
  }
  for(i=0;i<n;i++){
    x[offset[i]]++;
  }
  int mod = 0;
  for(i=0;i<n;i++){
    if(x[offset[i]] > x[offset[mod]])
      mod = i;
  }
  return mod;
}
int main(){
  cin>>t;
  int y,min,temp,j;
  while(l<=t){
    cin>>n;
    for(i=0;i<n;i++){
      cin>>a[i];
      current[i] = 0;
      m[i] = a[i].length();
    }
    ans = 0;
    while(cond() && ans != -1){
      for(i=0;i<n;i++){
        offset[i] = 1;
      while(current[i]+offset[i]<m[i] && a[i][current[i]] == a[i][current[i]+offset[i]] ){
	offset[i]++;
      }
     }
 //   for(i=0;i<n;i++)
 //   cout<<offset[i]<<" ";
 //   cout<<endl;

    if(cond2()){
    	cout<<"Case #"<<l<<": Fegla Won\n";
	 ans = -1;
    }
     else{
      for(i=0;i<101;i++){
 	   x[i] = 0;
  	}
  	for(i=0;i<n;i++){
   	 x[offset[i]]++;
 	 }
min = 1000000000;
for(i=0;i<n;i++){
temp =0;
//cout<<y<<" ";
     for(j=0;j<n;j++)
        temp = temp + abs(offset[j]-offset[i]);
   //  cout<<temp<<" ";
     if(temp < min)
     min = temp;
 current[i] += offset[i];
}
//cout<<endl;
ans = ans + min;
       //handle multiple modes
     }
    
}
   
    if (ans != -1)
    cout<<"Case #"<<l<<": "<<ans<<endl;
    l++;
  }
  return 0;
}
