#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


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

int num;
int ary[1000];


for(int k=0; k<cases ; k++){

    input >> num;
for(int i=0; i< num ; i++){
    input >> ary[i];
//    cout<<ary[i]<<" ";
}
//cout<<endl;


int m1=0;
int m2m=0;
int m2=0;
for( int j=1; j <  num ; j++){
//   cout<< j <<endl;
   m2m = max(m2m,(ary[j-1]-ary[j]));

   if( ary[j-1] > ary[j] )
     m1 += (ary[j-1]-ary[j]);
}
cout<<"max "<<m2m<<" "<<m1<<endl;
for( int j=0; j < (num-1) ; j++){
   if( ary[j] > m2m )
      m2+=m2m;
   else
      m2+=ary[j];
}
output<<"Case #"<<k+1<<": "<<m1<<" "<<m2<<endl;  
cout<<"Case #"<<k+1<<": "<<m1<<" "<<m2<<endl;  

}

input.close();
output.close();
return 0;
}

