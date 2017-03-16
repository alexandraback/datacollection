import java.util.Scanner;
public class Mushroom {
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		answ(S);
	}
	public static int case1;
	public static int case2;
	public static int maxDiff;
 
	public static void answ(Scanner input){
		int numCases = input.nextInt();
		
		for(int i=1; i<=numCases; i++)
		{
			case1 = 0;
			case2 = 0;
			maxDiff = 0;
			eat(input);
			System.out.printf("Case #%d: %d %d", i, case1, case2);
			if(i!=numCases)
				
				System.out.println();
		}
	}
 
	public static void eat(Scanner input){
		int n = input.nextInt();
		int[] arr = new int[n];
		for(int i=0; i<n; i++){
			arr[i] = input.nextInt();
		}
		
		for(int k=0; k<(n-1); k++){
			int current = arr[k];
			int next = arr[k+1];
			maxDiff = Math.max(maxDiff,  current - next);
			if(current > next){
				case1 += current - next;
			}
		}
	
		for(int k=0; k<(n-1); k++){
			int current = arr[k];
			if(current >= maxDiff){
				case2 += maxDiff;
			}
			else{
				case2 += current;
			}
		}
	}
 
 
}