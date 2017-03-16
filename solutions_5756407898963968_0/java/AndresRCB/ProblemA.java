package andresrcb.codejam14.qual.solutions;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {

		try {
			String fileName;
			String outputName;
			int runType = 1;
			switch(runType) {
			case 0:
				fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/1/A-sample.in";
				outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/1/A-sample.out";
				break;
			case 1:
				fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/1/A-small-attempt0.in";
				outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/1/A-small-attempt0.out";
				break;
			default:
				fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/1/A-big.in";
				outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/1/A-big.out";
			}


			BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName));
			Scanner s = new Scanner(bufferedReader);
			final int T = s.nextInt();
			String[] results = new String[T];
			int firstRowNumber;
			int[] firstRow = new int[4];
			int secondRowNumber;
			int[] secondRow = new int[4];
			int possibleCard;
			int count;
			for (int i = 0; i<T ; ++i) {
				firstRowNumber = s.nextInt();
				for (int r = 1; r<=4 ; ++r) {
					if(r == firstRowNumber) {
						firstRow[0] = s.nextInt();
						firstRow[1] = s.nextInt();
						firstRow[2] = s.nextInt();
						firstRow[3] = s.nextInt();
					}
					else {
						s.nextInt();s.nextInt();s.nextInt();s.nextInt();
					}
				}

				secondRowNumber = s.nextInt();
				for (int r = 1; r<=4 ; ++r) {
					if(r == secondRowNumber) {
						secondRow[0] = s.nextInt();
						secondRow[1] = s.nextInt();
						secondRow[2] = s.nextInt();
						secondRow[3] = s.nextInt();
					}
					else {
						s.nextInt();s.nextInt();s.nextInt();s.nextInt();
					}
				}
				possibleCard = 0;
				count = 0;
				for(int j = 0; j<4;++j) {
					for (int k = 0; k<4;++k) {
						if(firstRow[j]==secondRow[k]) {
							count++;
							possibleCard = firstRow[j];
						}
					}
				}
				if(count == 1) {
					results[i] ="Case #" + (i+1) + ": " + possibleCard;
				}
				else if (count == 0) {
					results[i] ="Case #" + (i+1) + ": Volunteer cheated!";
				}
				else {
					results[i] ="Case #" + (i+1) + ": Bad magician!";
				}

			}
			s.close();
			bufferedReader.close();



			
			File outputFile = new File(outputName);

			if (!outputFile.exists()) {
				System.out.println(outputFile.getName());
				outputFile.createNewFile();
			}

			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			for (int i = 0; i<T;++i) {
				bw.write(results[i] + "\n");				
			}
			
			bw.close();

		} catch (Exception e) {
			e.printStackTrace();

		}

	}

}