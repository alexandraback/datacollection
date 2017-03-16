#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int p[100];
int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        int n, sum = 0;
        cin>>n;
        
        for(int i = 0; i< n; i++) {
           cin>>p[i];
           sum = sum + p[i];
        }   
		printf("Case #%d: ",c++);     
		while(sum > 0) {
			int maxNo = p[0], row1 = 0, row2=-1;
			
			for(int j = 0; j < n; j++) {
				if(p[j] >= maxNo) {
					maxNo = p[j];
					row1 = j;
				}	 	
	        }	 
	        if(sum == 3  && maxNo == 1) {
	        	cout<<(char) (row1+65)<<" ";
	        	sum--;
	        	p[row1]--;
	        	continue;
	        	
			}	
	        for(int j = 0; j < n; j++) {
	        	if(j != row1 && p[j] == maxNo)
	        	   row2 = j;
	        }
			if(row2 == -1 && p[row1] >= 2)	 
			   row2=row1;
			   
	        p[row1]--;
	        cout<<(char) (row1+65);
	        sum--;
	        
	        if(row2 >= 0) {
	        	p[row2]--;
	            cout<<(char) (row2+65);
	            sum--;
	        }	
	        cout<<" ";
	        
	        for(int j = 0; j < n; j++) {
	        	if(2 * p[j] > sum)
	                cout<<"error\n";
	        }	 	
	    }	 
		printf("\n");     
        
	}
	return 0;
}
