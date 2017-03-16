import java.io.*;
import java.util.*;


public class ProblemA {
	final static String PROBLEM_NAME = "/Users/autobee/work/gcm/problem_a";
	final static String FILE_NAME_IN =  "A-small-attempt0.in";
	final static String FILE_NAME_OUT =  "output.txt";
	
	/**
	 * @param args
	 */
	
	void solve(Scanner sc, PrintWriter pw) {
		int selRowFirst = sc.nextInt();
		
		HashSet<Integer> selectedFrist = new HashSet<Integer>();
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				int cell = sc.nextInt();
				if (i == selRowFirst) selectedFrist.add(cell);
			}
		}
		
		int selRowSecond = sc.nextInt();
		ArrayList<Integer> result = new ArrayList<Integer>();
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				int cell = sc.nextInt();
				if (i == selRowSecond && selectedFrist.contains(cell)) result.add(cell);
			}
		}
		
		if (result.isEmpty()) pw.println("Volunteer cheated!");
		else if (result.size() == 1) pw.println(result.get(0));
		else pw.println("Bad magician!");
		
	}
	
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(PROBLEM_NAME + "/" + FILE_NAME_IN));
        PrintWriter pw = new PrintWriter(new FileWriter(PROBLEM_NAME + "/" + FILE_NAME_OUT));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new ProblemA().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();

	}

}
