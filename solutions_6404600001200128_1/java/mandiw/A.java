package codejam1A;

import java.util.Scanner;

public class A {

	public static void main(String args[]){

		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for(int i = 0; i < n; i++){

			int p = scan.nextInt();
			int plates[] = new int[p];

			for(int j = 0; j < p; j++){
				plates[j] = scan.nextInt();

			}
			int result1 = 0;
			int temp = plates[0];

			int maxdiff = 0;
			for(int k = 1; k < p; k++){
				if(plates[k] < temp)
					result1 += temp -plates[k];
				if(temp -plates[k] > maxdiff){
					maxdiff = temp -plates[k];
				}
				temp = plates[k];

			}
			int result2 = 0;
			for(int q = 0; q < p-1; q++){
				if(plates[q] < maxdiff)
					result2 += plates[q];
				else
					result2 +=maxdiff;
			}
			System.out.println("Case #"+ (i+1) +": " + result1 + " "+ result2);
		}

	}
}
