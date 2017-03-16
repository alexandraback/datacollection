#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}


int main( int argc, char** argv){


ofstream output;
ifstream input;
//cout<< " start "<<endl;
input.open(argv[1]);
output.open("ans.txt");


if(input.fail()){
  cout<<" error opening file"<<endl;
  return -1;
}


int cases;
input >> cases;

int nb;
long long bar[1000];
long long bartime[1000];
int N;
long long time;
int ans;
long long common;
long long lcm;
long long round;
for(int i=0; i< cases ; i++){
 input >> nb;
 input >> N;
 ans=0;
cout<<"case " << i <<" nb "<<nb<<" N "<<N<<endl;

for( int j=0; j < nb ; j++){
  input >> bar[j];
  bartime[j]=0;
}

if( nb >=2 ){
  common = gcd( bar[0] , bar[1] );
  lcm = (bar[0]*bar[1]/common);
  for( int j=2; j < nb ; j++){
    common = gcd(common,bar[j]);
    lcm = ((bar[j]*lcm)/common);
  } 
}else{
  common = bar[0];
  lcm = bar[0];
}

cout<<" gcd is "<<common<<" lcm is "<<lcm<<endl;


round =0;
for( int j=0; j < nb ; j++){
  round += (lcm/bar[j]);
  
}

cout<<" gcd is "<<common<<" lcm is "<<lcm<<" round "<<round<<endl;

if(N%round)
  N=N%round;
else
  N=round;

cout<<" new N is "<<N<<endl;

time=0;
while(N!=0){
  for( int k=0; k < nb ; k++){
     if (  bartime[k] <= time ){
         bartime[k] = time + bar[k];
         N--;
         if( N== 0 ){
            ans = (k+1);
            break;
         }
     }   
  }
  time+=common;
}

output<<"Case #"<<i+1<<": "<<ans<<endl;  
cout<<"Case #"<<i+1<<": "<<ans<<endl;  

}

input.close();
output.close();
return 0;
}

