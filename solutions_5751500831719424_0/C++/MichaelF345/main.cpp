#include <stdio.h>
#include <iostream>
struct id{
    char cd;
    int num;
};


int main (){

    id key[110][110];
    int length=0;
    int outputs[110];
    int average=0;
    int mode[110];

    int maxl=0;
    char temp [110];
    int place=0;
    int hole=0;
    char hold;
    int N=0;
    int changes=0;

    int done=0;
    //read data
        FILE * source;
        source = fopen ("A-small-attempt2.in","r");//enter file name
        fscanf(source,"%i",&maxl);
        while(length<maxl){
            fscanf(source,"%i",&N);
            //get strings
            for(int a=0;a<N;a++){
                fscanf(source,"%s",temp);
                hold=temp[0];
                place=0;
                hole=0;
                key[hole][a].cd=hold;key[hole][a].num=1;
                place++;
                hold=temp[place];
                while(hold!='\0'){
                    if(key[hole][a].cd==hold){key[hole][a].num++;}
                    else{hole++;key[hole][a].cd=hold;key[hole][a].num=1;}
                    place++;
                    hold=temp[place];
                }
                hole++;key[hole][a].cd=hold;key[hole][a].num=1;


            }
            //compare
            done=0;
            changes=0;
            hole=0;

            int temp23=0;
            //std::cout << done<<"\n";
            while(done==0){
                //std::cout << length<<"\n";
                average=0;
                for(int a=0;a<110;a++){mode[a]=0;}

                for(int i=0;i<(N-1);i++){
                    if(key[hole][i].cd=='\0'){done=1;}
                    if(key[hole][i].cd==key[hole][i+1].cd){
                        //trys for all modes
                        for(int a=0;a<110;a++){
                                if(key[hole][i].num>(a+1)){
                                    mode[a]+=key[hole][i].num-a-1;
                                }else{
                                    mode[a]+=-key[hole][i].num+a+1;
                                }
                        }
                    }else{changes=-9000;done=1;i=N-1;}
                }
                for(int a=0;a<110;a++){
                    if(key[hole][N-1].num>(a+1)){
                        mode[a]+=key[hole][N-1].num-a-1;
                    }else{
                        mode[a]+=-key[hole][N-1].num+a+1;
                    }
                }
                hole++;
                temp23=9000;
                 for(int a=0;a<110;a++){
                        if(mode[a]<temp23){temp23=mode[a];}
                 }
                 if(changes>-1){
                    changes+=temp23;

                 }
            }
            outputs[length]=changes;








            length++;
        }

        fclose(source);





    //write output

        source = fopen ("output.in","w");
        for(int a=0;a<maxl;a++){
            //std::cout << outputs[a]<<"\n";
            if(outputs[a]<0){
                fprintf(source,"Case #%d: Fegla Won\n",(a+1));

            }else{
                fprintf(source,"Case #%d: %d\n",(a+1),outputs[a]);
            }


        }
        fclose(source);

    return 0;
}
