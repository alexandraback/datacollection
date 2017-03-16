package codejams;

import java.io.BufferedReader;
import java.io.PrintWriter;

public class Magic {
	
	public Magic() {
		
	}
	
	public void testCase(BufferedReader br, PrintWriter pw) {
		try {
			int firstRow = Integer.parseInt(br.readLine()) - 1;
			String[][] firstGrid = new String[4][4];
			firstGrid[0] = br.readLine().split(" ");
			firstGrid[1] = br.readLine().split(" ");
			firstGrid[2] = br.readLine().split(" ");
			firstGrid[3] = br.readLine().split(" ");
			int secondRow = Integer.parseInt(br.readLine()) - 1;
			String[][] secondGrid = new String[4][4];
			secondGrid[0] = br.readLine().split(" ");
			secondGrid[1] = br.readLine().split(" ");
			secondGrid[2] = br.readLine().split(" ");
			secondGrid[3] = br.readLine().split(" ");		
			
			String r = null;
			for (String i : firstGrid[firstRow]) {
				for (String j : secondGrid[secondRow]) {
					if (Main.debug) System.out.println("." + i + "." + j + ".");
					if (i.equals(j)) {
						if (Main.debug) System.out.println("match!");
						if (r != null) {
							pw.print("Bad magician!");
							return;
						}
						r = j;
					}
				}
			}
			if (r == null) {
				pw.print("Volunteer cheated!");
				return;
			}
			pw.print(r);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}