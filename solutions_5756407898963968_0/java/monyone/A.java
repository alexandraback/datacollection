import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class A {
	
	public static final int SIZE = 4;
	
	public static Set<Integer> get_input(final int size, Scanner sc){
		final int row = sc.nextInt();
		
		Set<Integer> set = new HashSet<Integer>();
		for(int i = 0; i < SIZE; i++){
			final int row_index = i + 1;
			
			for(int j = 0; j < SIZE; j++){
				final int input = sc.nextInt();
				
				if(row_index == row){
					set.add(input);
				}
			}
		}
		
		return set;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tc = 0; tc < T; tc++){
			final int tc_index = tc + 1;
			
			Set<Integer> set_1 = get_input(SIZE, sc);
			
			Set<Integer> set_2 = get_input(SIZE, sc);
			
			Set<Integer> both = new HashSet<Integer>(set_1);
			both.retainAll(set_2);
			
			final boolean none = both.size() == 0;
			final boolean over = both.size() > 1;
			int ans = -1;
			for(int i : both){
				ans = i;
			}
			
			
			System.out.printf("Case #%d: %s\n", tc_index, none ? "Volunteer cheated!" : over ? "Bad magician!" : ans + "");
		}
	}
	
}
