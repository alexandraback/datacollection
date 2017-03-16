#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define fori(i,n)   for( int i=0 ; i< n ; i++ )


int R,C,N;

int countunh( int ary[18][18], int cc, int pos, int cunh ){

//  cout<<" N "<<cc<<" pos "<<pos<<" cunh "<< cunh<<endl;

  if( cc == N )
     return cunh;


  if ( (pos == R*C ) && cc < N)
     return -1;

  int r = pos/C;
  int c = pos%C;

  ary[r][c]=1;

  int ncunh=cunh;
  if( ((c-1)>=0) && ary[r][c-1] == 1 ){
     ncunh++;
  }
  if( ((r-1)>=0) && ary[r-1][c] == 1 ){
     ncunh++;
  }

  int y = countunh(ary,cc+1,pos+1,ncunh);
 
  ary[r][c]=0;
 
  int x = countunh(ary,cc,pos+1,cunh); 

    

//  cout<<" cunh "<<cunh<<" x "<<x<<" y "<<y<<endl; 
  
  if( (x == -1) && (y == -1) )
    cunh = -1;
  if( (x == -1) && (y != -1) )
    cunh =y;
  else if( (y==-1) && ( x != -1)) 
    cunh =x;
  else
    cunh=min(x,y);
  
  return cunh;

}

int main( int argc, char** argv){


ofstream output;
ifstream input;
cout<< " start "<<endl;
input.open(argv[1]);
output.open("ans.txt");


if(input.fail()){
  cout<<" error opening file"<<endl;
  return -1;
}

int ary[18][18];

int cases;
input >> cases;

int unh;

for(int k=0; k<cases ; k++){
input >> R;
input >> C;
input >> N;
unh=0;
cout<<"case "<<k<<" R "<<R<<" C "<<C<<" N "<<N<<endl;
for( int j=0; j < R ; j++){
  for( int i=0; i < C ; i++){
    ary[j][i]=0;
  }
}
unh = countunh( ary, 0 , 0 , 0 ); 

output<<"Case #"<<k+1<<": "<<unh<<endl;  
cout<<"Case #"<<k+1<<": "<<unh<<endl;  

}

input.close();
output.close();
return 0;
}

