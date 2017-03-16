#include <stdio.h>
struct grid{
    int square[34];
//r1
//16
//r2
//16
};
int guess(grid tp){
//-2cheat
//-1 can't
//1 to 16 guess
int r1[4];
int r2[4];
for(int i=0;i<4;i++){
    r1[i]=tp.square[(tp.square[0]-1)*4+i+1];
    r2[i]=tp.square[(tp.square[17]-1)*4+i+18];
}

int answer=-2;
for(int i1=0;i1<4;i1++){
    for(int i2=0;i2<4;i2++){
        if(r1[i1]==r2[i2]){
            if(answer==-2){
                answer=r1[i1];
            }else{
                answer=-1;
            }
        }
    }
}
return(answer);
}
int main (){
    int length=0;
    int pos=0;
    grid data[120];
    int state[120];
    int maxl=0;
    int temp=0;
    //read data
        FILE * source;
        source = fopen ("A-small-attempt0.in","r");//enter file name
        fscanf(source,"%i",&maxl);
        while(length<maxl){
            fscanf(source,"%i",&temp);
            if(pos==34){
                length++;
                (data[length]).square[0]=temp;
                pos=1;
            }else{
                (data[length]).square[pos]=temp;
                pos++;
            }
        }

        fclose(source);

    //do magic
        for(int a=0;a<maxl;a++){
            state[a]=guess(data[a]);
        }
    //write output
        source = fopen ("output.in","w");
        for(int a=0;a<maxl;a++){
            if(state[a]==-1){
                fprintf(source,"Case #%d: Bad magician!\n",(a+1));
            }
            if(state[a]==-2){
                fprintf(source,"Case #%d: Volunteer cheated!\n",(a+1));
            }
            if(state[a]>0){
                fprintf(source,"Case #%d: %d\n",(a+1),state[a]);
            }

        }
        fclose(source);

    return 0;
}

