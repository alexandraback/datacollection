#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int casos,i,j, noBarberos, puesto,solActual,rta,resta, resta2;
    bool mcm,flag,mc2;
    vector<int> soluciones;
    cin >> casos;
    for(i=1;i<=casos;i++){
    	cin >> noBarberos >> puesto;
    	int b1[noBarberos];
    	int b2[noBarberos];
    	soluciones.clear();
    	soluciones.push_back(0);
    	for(j=0;j<noBarberos;j++){
    		cin >> b1[j];
    		b2[j] = b1[j];
    		soluciones.push_back(j+1);
    	}
    	resta = 1;
    	solActual = noBarberos;
    	flag = false;
    	while(true){
    		if(solActual >= puesto){
    			rta = puesto;
    			break;
    		}
    		resta2 = 10000000;
    		mcm = true;
    		mc2 = false;
    		for(j=0;j<noBarberos;j++){
    			b2[j] -= resta;
    			if(b2[j]!=0){
    				mcm = false;
    			}else{
    				b2[j] = b1[j];
    				solActual++;
    				soluciones.push_back(j+1);
    				if(solActual==puesto){
    					rta = j+1;
    					flag = true;
    					break;
    				}
    			}
    			if(b2[j]<resta2){
    				resta2 = b2[j];
    			}
    			if(j+1==noBarberos){
    				mc2 = mcm;
    			}
    		}
    		resta = resta2;
    		if(mc2){
    			if(puesto % (solActual - noBarberos)!=0){
    				puesto = puesto % (solActual - noBarberos);
    			}else{
    				puesto = solActual - noBarberos;
    			}

    			rta = soluciones[puesto];
    			break;
    		}
    		if(flag){
    			break;
    		}
    	}
    	cout << "Case #"<<i<<": "<<rta<< "\n";
    }
    return 0;
}