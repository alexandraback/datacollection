import java.io.*;
import java.util.*;

public class CodeJamA {
	
	static final String path = "C:/gcj2014/Qual/A/";
	static final String problem = "A-small";
	
	Scanner in;
	static PrintWriter out;
	
	
	static class Move {
		
		int answerRow;
		
		int field[][] = new int[4][4];
		
		Move(Scanner in) {
			answerRow = in.nextInt() - 1;
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col++) {
					field[row][col] = in.nextInt();
				}
			}
		}
		
		NavigableSet<Integer> getBest() {
			NavigableSet<Integer> answer = new TreeSet<Integer>();
			for (int i = 0; i < 4; i++) {
				answer.add(field[answerRow][i]);
			}
			return answer;
		}
	}
	
	String solveOne() {
		NavigableSet<Integer> first = new Move(in).getBest();
		NavigableSet<Integer> second = new Move(in).getBest();
		first.retainAll(second);
		if (first.size() == 1) {
			return first.first().toString();
		} else if (first.size() > 1) {
			return "Bad magician!";
		} else {
			return "Volunteer cheated!";
		}
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.println("Case #" + i + ": " + solveOne());
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			System.out.println("Guten Tag>");
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new CodeJamA().run();
	}
}