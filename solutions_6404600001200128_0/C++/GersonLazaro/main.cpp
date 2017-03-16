#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int casos,i,j,n,tipo1,tipo2,razon;
    cin >> casos;
    for(i=1;i<=casos;i++){
    	cin >> n;
    	int valores[n];
    	tipo1 = 0;
    	tipo2 = 0;
    	razon = 0;
    	for(j=0;j<n;j++){
    		cin >> valores[j];
    		if(j>0){
    			if(valores[j-1]>valores[j]){
    				tipo1+= valores[j-1]-valores[j];
    				if(valores[j-1]-valores[j]>razon){
    					razon = valores[j-1]-valores[j];
    				}
    			}
    		}
    	}
    	for(j=0;j<n;j++){
    		if(j>0){
    			if(valores[j-1]<=razon){
    				tipo2+= valores[j-1];
    			}else if(valores[j-1]>razon){
    				tipo2+= razon;
    			}
    		}
    	}

    	cout << "Case #"<<i<<": "<<tipo1 <<" "<<tipo2<< "\n";
    }
    return 0;
}