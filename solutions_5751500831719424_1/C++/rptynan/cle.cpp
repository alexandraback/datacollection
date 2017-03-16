#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define LEN 110

int N;
struct str{
    char s[LEN];
    int sl, n[LEN];
};


int main(){

    int TC;
    scanf("%d",&TC);
    for(int tc=1; tc<=TC; ++tc){

        scanf("%d",&N);
        str strs[LEN];
        bool fail = 0;
        for(int n=0; n<N; ++n){

            strs[n].sl=0; 
            char os[LEN]; int osl;
            scanf("%s",os);
            if( fail ) continue;
            osl = strlen(os);

            for(int i=0; i<osl; ++i){
                if( i>0 && os[i]==os[i-1] ){
                    ++strs[n].n[ strs[n].sl-1 ];
                    continue;
                }
                strs[n].s[ strs[n].sl ] = os[i];
                strs[n].n[ strs[n].sl++ ] = 1;
            }
            strs[n].s[ strs[n].sl ] = '\0';

            /*
            for(int i=0; i<strs[n].sl; ++i){
                cout<<strs[n].s[i]<<strs[n].n[i]<<' ';
            } cout<<endl;
            */

            if( n>0 && (strs[n].sl!=strs[n-1].sl || strcmp(strs[n].s,strs[n-1].s)) ){
                fail = 1;
            }

        }

        if( fail ){
            printf("Case #%d: Fegla Won\n",tc );
            continue;
        }

        int ovres=0;
        for(int c=0; c<strs[0].sl; ++c){
            int best = 1<<20;
            int maxo = 1;
            for(int o=1; o<=maxo; ++o){
                int res = 0;
                for(int i=0; i<N; ++i){
                    if( strs[i].n[c] > maxo ) maxo = strs[i].n[c];
                    res += max(o,strs[i].n[c]) - min(o,strs[i].n[c]);
                }
                //cout<<' '<<res<<endl;
                best = min(best,res);
            }
            ovres += best;
            //cout<<best<<endl;
        }

        printf("Case #%d: %d\n",tc, ovres );

    }
    return 0;
}
