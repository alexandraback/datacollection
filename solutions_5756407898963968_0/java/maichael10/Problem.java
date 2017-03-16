/**
 * 
 */
package problem;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

import general.IO;

/**
 * @author michael
 *
 */
public class Problem {

	/**
	 * Metodo main que corre el programa.
	 * @param args Argumentos con los que es llamado el programa.
	 * @throws Exception Si hubo excepcion.
	 */
	public static void main(String args[]) throws Exception {

		String file = "A-small-attempt0";

		Object[] pairIO = IO.openIO(file);
		BufferedReader red = (BufferedReader) pairIO[0];
		PrintWriter wr = (PrintWriter) pairIO[1];
		
		
		int problemas = Integer.parseInt(red.readLine());
		outer: for (int w = 0 ; w < problemas ; w++) {
			int firstChoice = Integer.parseInt(red.readLine());
			int fCol[] = new int[4];
			for (int i = 1 ; i <= 4 ; i++) {
				String linea = red.readLine();
				if (i == firstChoice) {
					String[] lo = linea.split(" ");
					for (int j = 0 ; j < 4 ; j++) {
						fCol[j] = Integer.parseInt(lo[j]);
					}
				}
			}
			
			int secondChoice = Integer.parseInt(red.readLine());
			int sCol[] = new int[4];
			for (int i = 1 ; i <= 4 ; i++) {
				String linea = red.readLine();
				if (i == secondChoice) {
					String[] lo = linea.split(" ");
					for (int j = 0 ; j < 4 ; j++) {
						sCol[j] = Integer.parseInt(lo[j]);
					}
				}
			}
			
			int in = 0;
			for (int i = 0 ; i < 4 ; i++) {
				for (int j = 0 ; j < 4 ; j++) {
					if (fCol[i] == sCol[j]) {
						if (in == 0)
							in = fCol[i];
						else {
							wr.println("Case #" + (w+1) + ": " + "Bad magician!");
							continue outer;
						}
					}
				}
			}
			if (in == 0) {
				wr.println("Case #" + (w+1) + ": " + "Volunteer cheated!");
			} else {
				wr.println("Case #" + (w+1) + ": " + in);
			}
			
		}
	}
}
