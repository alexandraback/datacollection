#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;




int main(){

    int TC;
    scanf("%d",&TC);
    for(int tc=1; tc<=TC; ++tc){

        int N, res=0, i1=0, i2=0;
        char str1[110], str2[110];
        int len1, len2;
        bool fail=0;

        scanf("%d",&N);
        scanf("%s",&str1); len1=strlen(str1);
        scanf("%s",&str2); len2=strlen(str2);

        while( i1 < len1 || i2 < len2 ){

            if( str1[i1] == str2[i2] ){
                ++i1; ++i2; 
                continue;
            }

            else{
                if( i1<len1 && i1>0 && str1[i1] == str1[i1-1] ){
                    ++res; ++i1;
                    continue;
                }
                if( i2<len2 && i2>0 && str2[i2] == str2[i2-1] ){
                    ++res; ++i2;
                    continue;
                }
            }

            fail = 1;
            break;

        }

        if( !fail ){
            printf("Case #%d: %d\n",tc, res );
        }
        else{
            printf("Case #%d: Fegla Won\n",tc );
        }

    }
    return 0;
}
