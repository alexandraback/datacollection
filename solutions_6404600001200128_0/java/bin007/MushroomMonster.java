
import java.util.Scanner;
public class MushroomMonster {
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		process(input);
 
	}
 
 
	public static int case1;
	public static int case2;
	public static int maxDiff;
 
	public static void process(Scanner input){
		int numCases = input.nextInt();
		for(int i=1; i<=numCases; i++){
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
		// Case 1
		for(int k=0; k<(n-1); k++){
			int current = arr[k];
			int next = arr[k+1];
			maxDiff = Math.max(maxDiff,  current - next);
			if(current > next){
				case1 += current - next;
			}
		}
		// Case 2
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