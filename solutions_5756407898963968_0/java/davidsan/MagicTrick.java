package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class MagicTrick {

	int nbGrid;
	List<int[][]> gridBefore;
	List<int[][]> gridAfter;
	List<Integer> rowNumbers;
	List<Integer> rowAgainNumbers;
	StringBuilder result;

	public MagicTrick(String filename) {
		super();
		gridBefore = new ArrayList<int[][]>();
		gridAfter = new ArrayList<int[][]>();
		rowNumbers = new ArrayList<Integer>();
		rowAgainNumbers = new ArrayList<Integer>();
		try {
			readFile(filename);
		} catch (IOException e) {
			e.printStackTrace();
		}

		result = new StringBuilder();
		computeResult();
	}

	public void readFile(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = br.readLine();
		nbGrid = Integer.parseInt(line);
		try {
			for (int cpt = 0; cpt < nbGrid; cpt++) {
				line = br.readLine();
				rowNumbers.add(Integer.parseInt(line));

				gridBefore.add(new int[4][4]);
				for (int i = 0; i < 4; i++) {
					line = br.readLine();
					String[] cartes = line.split(" ");
					int[] cartesInt = new int[cartes.length];
					for (int j = 0; j < cartes.length; j++) {
						cartesInt[j] = Integer.parseInt(cartes[j]);
					}
					gridBefore.get(cpt)[i] = cartesInt;
				}
				rowAgainNumbers.add(Integer.parseInt(br.readLine()));
				gridAfter.add(new int[4][4]);
				for (int i = 0; i < 4; i++) {
					line = br.readLine();
					String[] cartes = line.split(" ");
					int[] cartesInt = new int[cartes.length];
					for (int j = 0; j < cartes.length; j++) {
						cartesInt[j] = Integer.parseInt(cartes[j]);
					}
					gridAfter.get(cpt)[i] = cartesInt;
				}
			}
		} finally {
			br.close();
		}

	}

	public void computeResult() {
		for (int caseNumber = 0; caseNumber < nbGrid; caseNumber++) {
			Set<Integer> candidatsR = new HashSet<Integer>();
			Set<Integer> candidatsC = new HashSet<Integer>();
			int volunteerRow = rowNumbers.get(caseNumber) - 1;
			for (int i = 0; i < 4; i++) {
				candidatsR.add(gridBefore.get(caseNumber)[volunteerRow][i]);
			}
			int volunteerCol = rowAgainNumbers.get(caseNumber) - 1;
			for (int i = 0; i < 4; i++) {
				candidatsC.add(gridAfter.get(caseNumber)[volunteerCol][i]);
			}

			Set<Integer> intersection = new HashSet<Integer>(candidatsR);
			intersection.retainAll(candidatsC);

			result.append("Case #");
			result.append(caseNumber + 1);
			result.append(": ");
			if (intersection.size() == 1) {
				result.append((int) (intersection.toArray()[0]));
			} else if (intersection.size() == 0) {
				result.append("Volunteer cheated!");
			} else {
				result.append("Bad magician!");
			}
			result.append("\n");
		}
	}

	public static void main(String[] args) {
		MagicTrick mt = new MagicTrick(args[0]);
		// Gson g = new Gson();
		// System.err.println(g.toJson(mt.rowNumbers));
		// System.err.println(g.toJson(mt.rowAgainNumbers));
		// System.err.println(g.toJson(mt.gridBefore));
		// System.err.println(g.toJson(mt.gridAfter));
		// System.out.println(mt.result.toString());
		PrintWriter writer;
		try {
			writer = new PrintWriter(args[0].substring(0,
					args[0].lastIndexOf('.'))
					+ ".out", "UTF-8");
			writer.println(mt.result.toString());
			writer.close();
		} catch (FileNotFoundException | UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}
}
