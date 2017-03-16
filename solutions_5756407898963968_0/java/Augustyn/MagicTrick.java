import java.util.HashSet;
import java.util.Scanner;


public class MagicTrick {

	public static void main(String[] args){
		
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		scanner.nextLine();
		int t1[][]= new int[4][4];
		int t2[][]= new int[4][4];
		int a,b;
		for(int t =0; t < T; t ++){
			a = scanner.nextInt();

			scanner.nextLine();
			readArray(scanner, t1);
			
			b = scanner.nextInt();
			scanner.nextLine();
			readArray(scanner,t2);
			
			int k = getAnswer(t1,a,t2,b);
			if(k==-1){
				System.out.println("Case #"+(t+1)+": Bad magician!");
			} else if(k == -2){
				System.out.println("Case #"+(t+1)+": Volunteer cheated!");
			} else {
				System.out.println("Case #"+(t+1)+": "+k);
			}
		//	Case #1: 7
		//	Case #2: Bad magician!
		//	Case #3: Volunteer cheated!
		}
		
	}

	private static int getAnswer(int[][] t1, int a, int[][] t2, int b) {
		HashSet<Integer> set = new HashSet<Integer>();
		for(int i = 0; i <4; i++)
			set.add(t1[a-1][i]);
		
		int c = 0;
		int p = 0;
		for(int i = 0; i <4; i++){
			int w = t2[b-1][i];
			
			if(set.contains(w)){
				c++;
				p = w;
			}
		}
		//System.out.println("REs "+c +" "+p);
		if(c==1)
			return p;
		if(c>0)
			return -1;
		return -2;
	}

	private static void readArray(Scanner scanner, int[][] t1) {
		for(int i = 0; i <4; i ++){
			String s = scanner.nextLine();
			String[] tab = s.split(" ");
			//System.out.println(s);
			for(int j = 0; j < 4; j ++)
				t1[i][j]=Integer.parseInt(tab[j]);
		}
	}
}
