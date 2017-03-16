#include<bits/stdc++.h>
using namespace std;
int arr[1<<16];
int main(){
    int t,j;
    FILE *fp,*fp1;
    fp=fopen("input.txt","r");
    fp1=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    for(j=0;j<t;j++){
        int r,c,n,test;
        fscanf(fp,"%d %d %d",&r,&c,&n);
		int res = r * c * n * 100;
		for (int i = 1; i < (1 << (r * c)); i++){
            test=i - (i & -i);
			arr[i] = arr[test] + 1;
			if (arr[i] == n){
            int temp = 0;
        for (int temp1 = 0; temp1 < r; temp1++){
            for (int temp2 = 0; temp2 < c; temp2++){
                if (temp2 > 0 && (i & (1 << (temp1 * c + temp2))) && (i & (1 << (temp1 * c+ temp2- 1))))
                    temp++;
                if (temp1 > 0 && (i & (1 << (temp1 * c + temp2))) && (i & (1 << (temp1 * c + temp2 - c))))
                    temp++;
		}
	}
			res = min(res,temp);
    }
		}
		fprintf(fp1,"Case #%d: %d\n",j+1, res);
	}
	return 0;
}
