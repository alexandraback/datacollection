#include<stdio.h>
#include<stdlib.h>
#include<cmath>

using namespace std;
#include<vector>
#include<string>

vector<string> strs;
int len_str[100];

int ptr_e[100];
int len_ch[100];
int signal;

int main(int argc, char* argv[]){
    FILE *fin;
    fin = fopen(argv[1], "r");

    int T, N;
    fscanf(fin, " %d ", &T);
    for(int tc=0; tc<T; ++tc){
	signal = 0;
	strs.clear();
	fscanf(fin, " %d ", &N);
	for(int i=0; i<N; ++i)	ptr_e[i] = 0;

	char str[100];
	for(int i=0; i<N; ++i){
	    fscanf(fin, "%s", str);
	    strs.push_back(string(str));
	    len_str[i] = string(str).length();
//	    printf("%s %d\n", str, string(str).length());
	}

	int moves = 0;
	char nowch;
	while(ptr_e[0] < len_str[0]){
	    nowch = strs[0][ptr_e[0]];
	    int minl = 10000;
	    int maxl = 0;
	    for(int i=0; i<N; ++i){
		len_ch[i] = 0;
		for(; ptr_e[i] < len_str[i]; ++ptr_e[i]){
		    if(strs[i][ptr_e[i]] == nowch){
			++len_ch[i];
		    }else{
			break;
		    }
		}
		if(len_ch[i] == 0){
		    printf("Case #%d: Fegla Won\n", tc+1);
		    signal = 1;
		    break;
		}
		if(len_ch[i] > maxl)	maxl = len_ch[i];
		if(len_ch[i] < minl)	minl = len_ch[i];
	    }
	    if(signal == 1) break;
	    // moves
	    int minmoves = 2147483646;
	    for(int m=minl; m<=maxl; ++m){
		int tmpmoves = 0;
		for(int i=0; i<N; ++i){
		    tmpmoves += abs(len_ch[i] - m);
		}
		if(tmpmoves < minmoves)	minmoves = tmpmoves;
	    }
	    moves += minmoves;
	}
	if(signal == 1)	continue;
	for(int i=0; i<N; ++i){
	    if(ptr_e[i] < len_str[i]){
		printf("Case #%d: Fegla Won\n", tc+1);
		signal = 1;
		break;
	    }
	}
	if(signal == 1)	continue;
	printf("Case #%d: %d\n", tc+1, moves);
    }
    fclose(fin);

    return 0;
}
