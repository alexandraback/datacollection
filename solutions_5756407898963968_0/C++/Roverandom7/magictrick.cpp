#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main(){
    ifstream ulazniTok("A-small-attempt3.in");

    int T;
    int Ans1;
    int Ans2;
    int Cards1[16];
    int Cards2[16];
    int i;
    int j;
    int Hit[16];
    int fin;

    FILE *f;
    f = fopen("out.txt", "w");


    ulazniTok >> T;
for( i = 0; i < T ; i++ ){
    int a,b;
    Ans1 = Ans2 = 0;

    fin = 0;

    ulazniTok >> Ans1;

    for( j = 0; j < 16; j++ )
        ulazniTok >> Cards1[j];

    ulazniTok >> Ans2;

    for( j = 0; j < 16; j++ )
        ulazniTok >> Cards2[j];


    for( j = 0; j < 16; j++ )
        Hit[j] = 0;



    a = (Ans1-1)*4;
    b = Ans1*4;


    for( j = a; j < b; j++ )
        {Hit[Cards1[j]-1]++; }



    a = (Ans2-1)*4;
    b = Ans2*4;


    for( j = a; j < b; j++ )
        {Hit[Cards2[j]-1]++; }

    for( j = 0; j < 16; j++ )
        if( Hit[j] == 2 ) fin++;



    if( fin == 0 )    fprintf(f, "Case #%d: Volunteer cheated!\n", i+1);

    else if( fin > 1 ) fprintf(f, "Case #%d: Bad magician!\n", i+1);
    else{
    for( j = 0; j < 16; j++ )
        if( Hit[j] == 2 ) fin = j;

     fprintf(f, "Case #%d: %d\n",i+1,fin+1);

    }

}
    fclose(f);

return 0;

}
