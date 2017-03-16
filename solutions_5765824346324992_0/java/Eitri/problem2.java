//Author Jon Keenan
import java.util.Scanner;
public class problem2{
     
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int numTestCases = sc.nextInt();
		
		//Variable declarations
		int B,N,a,n;
		int[] arr;
		int[] tleft;
		for (int i = 0; i < numTestCases; i++) {
			//Main working area//		  
			B = sc.nextInt();
			N = sc.nextInt();
			a=0;
			arr = new int[B];
			tleft = new int[B];
			
			//Input//
			for(int j = 0; j < B; j++) {
				arr[j] = sc.nextInt();
			}
		  	for(int j = 0; j < B; j++) {
				tleft[j] = 0;
			}
			int mult = 1;
			int[] multiple = new int[B];
			int total = 0;
			
			for(int j = 0; j < B; j++) {
				mult *= arr[j];
			}
			for(int j = 0; j < B; j++) {
				multiple[j] = mult/arr[j];
				total += multiple[j];
			}


		
			n=0;
			int NN = N;
			while(NN > total){
				NN -= total;
			}
			A: while(n < NN){
				for(int j = 0; j < B; j++) {
					if(tleft[j] == 0){
						n++;
						if(n==NN){
							a=j+1;
							break A;
						}
						tleft[j] = arr[j];
						
					}
					tleft[j]--;									
				}
				
			}
			




			//Output//
			System.out.println("Case #"+ (i+1) +": " + a);


		}
	}
}
