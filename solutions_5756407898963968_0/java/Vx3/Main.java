import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		FileReader f = new FileReader("E://workspace//store credit//resource//in");
		BufferedReader br = new BufferedReader(f);
		// number of input
		int N = Integer.parseInt(br.readLine());
		// row1 & row2
		String[] row1 = new String[N];
		String[] row2 = new String[N];
		// nbre d'items
		String[] grid1 = new String[4 * N];
		String[] grid2 = new String[4 * N];
		String sCurrentLine;
		int i = 0;
		while ((sCurrentLine = br.readLine()) != null) {
			row1[i] = sCurrentLine;
			grid1[4 * i] = br.readLine();
			grid1[4 * i + 1] = br.readLine();
			grid1[4 * i + 2] = br.readLine();
			grid1[4 * i + 3] = br.readLine();
			row2[i] = br.readLine();
			grid2[4 * i] = br.readLine();
			grid2[4 * i + 1] = br.readLine();
			grid2[4 * i + 2] = br.readLine();
			grid2[4 * i + 3] = br.readLine();
			i++;
		}
		
		for (i = 0; i < N ; i++) {
			Jeu jeu = new Jeu(row1[i],
								row2[i],
								grid1[4 * i],
								grid1[4 * i + 1],
								grid1[4 * i + 2],
								grid1[4 * i + 3],
								grid2[4 * i],
								grid2[4 * i + 1],
								grid2[4 * i + 2],
								grid2[4 * i + 3]);
			String result = jeu.compute();
			
			System.out.println("Case #" + (i + 1) + ": " + result);
			
		}
		

	}

}
