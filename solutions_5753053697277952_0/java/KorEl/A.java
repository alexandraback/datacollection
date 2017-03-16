package Round1C2016;

import java.util.*;
import java.io.*;


public class A {
	
	
	
	public static void main(String [] args) throws IOException{
		
		//System.out.println((char)65->A);
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i=0;i<t;i++){
			
			int top = i+1;
			int n=sc.nextInt();
			
			int [] sena = new int[n];
			
			for(int j=0;j<n;j++){
				sena[j]=sc.nextInt();
			}
			String sol="";	
			while(sum(sena)>0){
				sol+=" ";
				if(sum(sena)==3){
					int max=max(sena,0);
					sol+=Character.toString((char)(max+65));
					sena[max]-=1;
				}
				else{
					int max1=max(sena,0);
					int max2=-1;
					if(max1<sena.length)
						max2=max(sena,max1+1);
					
					if (sena[max1] == sena[max2]){
						sol+=Character.toString((char)(max1+65))+Character.toString((char)(max2+65));
						
						sena[max1]-=1;
						sena[max2]-=1;
					}
					else{
						sol+=Character.toString((char)(max1+65))+Character.toString((char)(max1+65));
						sena[max1]-=2;
					}
				}
			}

			System.out.println("Case #"+top+":"+sol);
			
		}
		
	}

	public static int sum(int [] test){
		int sol=0;
		for(int i=0; i<test.length;i++){
			sol+=test[i];
		}
		return sol;
	}
	public static int max(int [] test,int index){
		int max=0;
		int indexm=0;
		for(int i=index; i<test.length;i++){
			if(test[i]>max){
				max=test[i];
				indexm=i;
			}
		}
		return indexm;
	}
	
}
