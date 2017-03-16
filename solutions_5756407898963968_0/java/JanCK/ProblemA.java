package jck.codejam.cj2014.qualification;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		//String filenameInput = "A-sample.in";
		//String filenameOutput = "A-sample.out";
		
		String filenameInput = "A-small-attempt0.in";
		String filenameOutput = "A-small-attempt0.out";

		Class currentClass = ProblemA.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			// System.out.println("Number of Testcases: " + numOfTestcases);
			for (int i = 0; i < numOfTestcases; i++) {
				System.out.println("Testnumber : " + i);
				boolean possible = true;
				int[] list1 = readSpecifiedLine(input);
				int[] list2 = readSpecifiedLine(input);
				System.out.println(Arrays.toString(list1));
				System.out.println(Arrays.toString(list2));
				Arrays.sort(list1);
				Arrays.sort(list2);
				System.out.println(Arrays.toString(list1));
				System.out.println(Arrays.toString(list2));
				int result = -1;
				int j = 0, k = 0;
				while (j < 4 && k < 4) {
					System.out.println("run for : [j,k] = [" + j + "," + k + "]");
					if (list1[j] < list2[k]) {
						System.out.println("found out " + list1[j] + " = list[" + j + "] < list2[" + k + "] = " + list2[k]);
						j++;
						continue;
					}
					if (list1[j] > list2[k]) {
						System.out.println("found out " + list1[j] + " = list[" + j + "] > list2[" + k + "] = " + list2[k]);
						k++;
						continue;
					}
					System.out.println("found out " + list1[j] + " = list[" + j + "] = list2[" + k + "] = " + list2[k]);
					if (result == -1) {
						result = list1[j];
						j++;
						k++;
						System.out.println("set result to : " + result);
					} else {
						result = -2;
						System.out.println("set result to : " + result);
						break;
					}
				}

				String outputString = "Case #"
						+ (i + 1)
						+ ": "
						+ ((result == -1) ? "Volunteer cheated!"
								: result == -2 ? "Bad magician!" : result);
				System.out.println(outputString);

				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);

			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static int[] readSpecifiedLine(BufferedReader input) throws IOException {
		int desiredLineNumber = Integer.parseInt(input.readLine()) - 1;
		int[] result = new int[4];
		String desiredLine = "";
		for (int i = 0; i <= 3; i++) {
			if (i == desiredLineNumber) {
				desiredLine = input.readLine();
			} else {
				input.readLine();
			}
		}
		String[] numbersAsStrings = desiredLine.split(" ");
		for (int i = 0; i <= 3; i++) {
			result[i] = Integer.parseInt(numbersAsStrings[i]);
		}
		return result;
	}

}
