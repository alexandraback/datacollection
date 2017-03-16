import java.util.HashSet;
import java.util.Scanner;

public class A {
	static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for(int j = 0; j < t; ++j) {
			HashSet<Integer> set1 = read();
			HashSet<Integer> set2 = read();
			
			set1.retainAll(set2);
			
			System.out.print("Case #"+(j+1)+": ");
			if(set1.size() == 0)
				System.out.println("Volunteer cheated!");
			else if(set1.size() > 1)
				System.out.println("Bad magician!");
			else
				System.out.println(set1.toArray()[0]);
		}
	}

	
	static HashSet<Integer> read() {
		int a = sc.nextInt();
		sc.nextLine();
		for(int i = 1; i < a; ++i)
			sc.nextLine();
		HashSet<Integer> set = new HashSet();
		for(int i = 0; i < 4; ++i)
			set.add(sc.nextInt());
		for(int i = a; i < 5; ++i)
			sc.nextLine();
		return set;
	}
}
