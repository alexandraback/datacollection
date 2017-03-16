import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

import javax.swing.JFileChooser;

public class Main {

	private static int nbCase;
	private static ArrayList<Case> listCase;
	private static String output = "";

	public static void main(String[] args) {
		listCase = new ArrayList<Case>();
		getInput(getFilePath());
		test();
		setClipboardContents(output);
		System.out.println("FIN");
	}
	
	private static void test() {
		for(int i = 0; i < nbCase; i++) {
			int cpt = 0;
			int card = 0;
			Case c = listCase.get(i);
			for(int j = 0; j < 4; j++) {
				for(int k = 0; k < 4; k++) {
					if (c.firstArrangement[c.firstAnswer][j] == c.secondArrangement[c.secondAnswer][k]) {
						cpt ++;
						card = c.firstArrangement[c.firstAnswer][j];
					}
				}
			}
			output += "Case #" + (i+1) + ": ";
			if (cpt == 0) {
				output += "Volunteer cheated!";
			}
			else if (cpt == 1) {
				output += card;
			}
			else {
				output += "Bad magician!";
			}
			if (i != nbCase) {
				output += "\n";
			}
		}
	}

	private static String getFilePath() {
		JFileChooser fc = new JFileChooser(
				"C:\\Users\\Maxime\\Desktop\\Codejam");
		if (fc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION)
			return null;
		return fc.getSelectedFile().getPath();
	}

	private static void getInput(String path) {
		String s = "";
		try {
			FileInputStream fis = new FileInputStream(path);
			BufferedReader br = new BufferedReader(new InputStreamReader(fis));
			s = br.readLine();
			nbCase = Integer.parseInt(s);
			for (int i = 0; i < nbCase; i++) {
				String[] row;
				Case c = new Case();
				
				s = br.readLine();
				c.firstAnswer = Integer.parseInt(s) - 1;
				
				for (int j = 0; j < 4; j++) {
					row = br.readLine().split(" ");
					for (int k = 0; k < 4; k++) {
						c.firstArrangement[j][k] = Integer.parseInt(row[k]);
					}
				}

				s = br.readLine();
				c.secondAnswer = Integer.parseInt(s) - 1;
				
				for (int j = 0; j < 4; j++) {
					row = br.readLine().split(" ");
					for (int k = 0; k < 4; k++) {
						c.secondArrangement[j][k] = Integer.parseInt(row[k]);
					}
				}
				listCase.add(c);
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void setClipboardContents(String s) {
		StringSelection ss = new StringSelection(s);
		Clipboard cb = Toolkit.getDefaultToolkit().getSystemClipboard();
		cb.setContents(ss, null);
	}

}

class Case {
	public int firstAnswer, secondAnswer;
	public int[][] firstArrangement, secondArrangement;

	public Case() {
		firstArrangement = new int[4][4];
		secondArrangement = new int[4][4];
	}
}
