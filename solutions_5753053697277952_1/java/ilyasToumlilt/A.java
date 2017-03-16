import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class A {

	private static Scanner in;
	
	static boolean validArr(int[] arr){
		for(int i=0 ; i<25; i++)
			if(arr[i] != 0)
				return true;
		return false;
	}
	
	static String solve(int[] arr, int N){
		String ret = "";
		
		while(validArr(arr)){

			// counting senators
			int count = 0;
			for(int i=0; i<N; i++){
				if(arr[i] > 0 )
					count++;
			}
				
			// processing
			int max_i = 0;
			int max_i2 = -1;
			int max = 0;
			for(int i=0; i<N; i++){
				if(arr[i] > max){
					max = arr[i];
					max_i = i;
					//max_i2 = -1;
				} //else if(arr[i] == max && max_i2 == -1){
					//max_i2 = i;
				//}
			}
			arr[max_i]--;
			max = 0;
			for(int i=0; i<N; i++){
				if(arr[i] > max){
					max = arr[i];
					max_i2 = i;
				}
			}
			
			// remaing 1
			boolean t1remaining = false;
			if(count == 3){
				boolean tmp = true;
				for(int i=0; i<N; i++){
					
				}
			}
				
			if(max == 0 )
				max_i2 = -1;
			else if(count == 3){
				boolean tmp = true;
				for(int i=0; i<N; i++)
					if(arr[i] > 1)
						tmp = false;
				if(tmp)
					max_i2=-1;
			}
			
			ret+= " " + (char)(65 + max_i);
			if(max_i2 != -1){
				ret += (char)(65 + max_i2);
				arr[max_i2]--;
			}
		}
		
		return ret;
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		String filename = args[0];
		int T;
		
		FileReader fr = new FileReader(filename);
		BufferedReader br = new BufferedReader(fr);
		in = new Scanner(br);
		
		T = in.nextInt();
		
		int Ti;
		String res;
		for(Ti=0; Ti < T; Ti++){
			/* init & parse */
			int[] arr = new int[26];
			int N = in.nextInt();
			for(int i=0; i<26; i++)
				arr[i] = 0;
			for(int i=0; i<N; i++)
				arr[i] = in.nextInt();
			
			/* traitement */
			res = solve(arr, N);
			
			/* résultat */
			System.out.print("Case #" + (Ti+1) + ": " + res + "\n");
		}

	}
}

