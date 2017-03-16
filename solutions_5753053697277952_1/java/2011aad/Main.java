import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		File input = new File("A-large.in");
		File output = new File("A-large.out");
		
		//comparator des order
		Comparator<Senate> comparator = new Comparator<Senate>() {
			@Override
			public int compare(Senate o1, Senate o2) {
				int num1 = o1.num;
				int num2 = o2.num;
				if (num1 < num2) return 1;
				else if (num1 > num2) return -1;
				return 0;
			}
		};
		//main
		Scanner in;
		PrintWriter out;
		try {
			in = new Scanner(input);
			out = new PrintWriter(output);
	
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				int N = in.nextInt();
				Senate[] senators = new Senate[N];
				int sum = 0; //total number of senators
				for (int j = 0; j < N; j++) {
					char tmp1 = (char) ('A' + j);
					int tmp2 = in.nextInt();
					sum += tmp2;
					senators[j] = new Senate(tmp1, tmp2);
				}
				Queue<Senate> priorityQueue = new PriorityQueue<Senate>(comparator);
				for (int j = 0; j < N; j++) priorityQueue.add(senators[j]);
				
				out.print("Case #" + i +": ");
				while (sum > 0) {
					//take one from the largest, this is certain
					Senate senate = priorityQueue.remove();
					sum--;
					senate.num -= 1;
					out.print(senate.symbol);
					priorityQueue.add(senate);
					//take two from the largest and the second largest
					if (priorityQueue.peek().num > sum / 2 || sum == 1) {
						senate = priorityQueue.remove();
						sum--;
						senate.num -= 1;
						out.print(senate.symbol);
						priorityQueue.add(senate);
					}	
					if (sum == 0) {
						out.println();
						break;
					}
					out.print(" ");
				}
			}
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static class Senate {
		public char symbol;
		public int num;
		public Senate(char symbol, int num) {
			this.symbol = symbol;
			this.num = num;
		}
	}
}
