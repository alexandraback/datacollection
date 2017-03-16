#include<cstdio>
#include<algorithm>

typedef unsigned long long ull;

int main(){
    int T,ile,nr,r,r2,tab[16],tab2[16];
    FILE* od,*zap;
    od=fopen("input","r");
    zap=fopen("output","w");
    fscanf(od,"%i",&T);
    for(int licznik=1;licznik<=T;++licznik){
        ile=0;
        fscanf(od,"%i",&r); --r;
        for(int i=0;i<16;++i) fscanf(od,"%i",tab+i);
        fscanf(od,"%i",&r2); --r2;
        for(int i=0;i<16;++i) fscanf(od,"%i",tab2+i);
        for(int i=0;i<4;++i)
        for(int j=0;j<4;++j){
            if(tab[r*4+i]==tab2[r2*4+j]){++ile; nr=tab[r*4+i];}
        }
        if(ile>1) fprintf(zap,"Case #%i: Bad magician!\n",licznik);
        else if(!ile) fprintf(zap,"Case #%i: Volunteer cheated!\n",licznik);
        else fprintf(zap,"Case #%i: %i\n",licznik,nr);
    }
    fclose(od); fclose(zap);


}
