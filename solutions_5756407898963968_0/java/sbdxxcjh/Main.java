import java.util.Scanner;


public class Main {
	static Scanner in = new Scanner(System.in);
	public static void main(String[] arg){
		int T = in.nextInt();
		for(int i = 1; i <= T; i++){
			solve(i);
		}
	}
	static void solve(int n){
		int []data1 = new int[4];
		int []data2 = new int[4];
		int row1 = in.nextInt();
		for(int r = 0; r < 4; r ++){
			for(int c = 0 ; c < 4; c++){
				if(r != row1 - 1)
					in.nextInt();
				else{
					data1[c] = in.nextInt();
				}
			}
		}
		
		int row2 = in.nextInt();
		
		for(int r = 0; r < 4; r ++){
			for(int c = 0 ; c < 4; c++){
				if(r != row2 - 1){
					in.nextInt();
				}
				else
					data2[c] = in.nextInt();
			}
		}
		int result = 0;
		int count = 0;
		for(int i : data1){
			for(int j : data2){
				if(i == j){
					result = i;
					count++;
				}
			}
		}
		
		if(count > 1)
			System.out.println("Case #" + n + ": Bad magician!");
		else if(count == 0)
			System.out.println("Case #" + n + ": Volunteer cheated!");
		else{
			System.out.println("Case #" + n + ": " + result);
		}
	}
}
