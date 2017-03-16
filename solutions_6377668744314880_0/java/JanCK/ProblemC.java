package nickname.jck.googlecodejam.cj2015.r1a.problemC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProblemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

//		String filenameInput = "C-sample.in";
//		String filenameOutput = "C-sample.out";

//		 String filenameInput = "C-small-attempt0.in";
//		 String filenameOutput = "C-small-attempt0.out";

		 String filenameInput = "C-small-attempt1.in";
		 String filenameOutput = "C-small-attempt1.out";
		 
		// String filenameInput = "C-large.in";
		// String filenameOutput = "C-large.out";

		Class currentClass = ProblemC.class;
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
				String[] inputStringArray = input.readLine().split(" ");
				int numOfPoints = Integer.parseInt(inputStringArray[0]);
				int[] coorX = new int[numOfPoints];
				int[] coorY = new int[numOfPoints];
				for (int j = 0; j < numOfPoints; j++) {
					String[] currInputStringArray = input.readLine().split(" ");
					coorX[j] = Integer.parseInt(currInputStringArray[0]);
					coorY[j] = Integer.parseInt(currInputStringArray[1]);

				}
				int[] numOfTreesToCut = new int[numOfPoints];
				for (int j = 0; j < numOfPoints; j++) {
					numOfTreesToCut[j] = numOfPoints;
				}
				int currDistanceToStart = numOfPoints;
				int currDistanceToEnd = numOfPoints;

				if (numOfPoints > 2) {
					int numOfDirections = numOfPoints * (numOfPoints-1) / 2;
					int[] directionX = new int[numOfDirections];
					int[] directionY = new int[numOfDirections];
					int indexOfDirections = 0;
					for (int j = 0; j < numOfPoints; j++) {
						for (int k = 0; k < j; k++) {
							//directionX[indexOfDirections] = coorX[j] - coorX[k];
							//directionY[indexOfDirections] = coorY[j] - coorY[k];
							directionX[indexOfDirections] = coorY[j] - coorY[k];
							directionY[indexOfDirections] = - coorX[j] + coorX[k];
							//System.out.println("point " + j + " and point " + k + " give direction (" +directionX[indexOfDirections] +";"+directionY[indexOfDirections]+")");
							if(directionX[indexOfDirections] == 0 &&
									directionY[indexOfDirections] == 0
									){
								//in case two trees have the same position.
								directionX[indexOfDirections] = 1;
							}
							
							indexOfDirections++;
						}
					}

					long[] currentProjections = new long[numOfPoints];
					long[] sortedProjections = new long[numOfPoints];

					for (int j = 0; j < numOfDirections; j++) {
//						System.out.println("current direction x " +  directionX[j] + " y " +  directionY[j]);
						for (int k = 0; k < numOfPoints; k++) {
//							System.out.println("numbernumOfPoints" + numOfPoints + "j"+j+  "k"+k + "currentProjections[k]" + currentProjections[k] + 
//									"directionX[j] * coorX[k] + directionY[j] * coorY[k]" + directionX[j] +"*"+ coorX[k]
//											+"+"+ directionY[j] +"*"+ coorY[k] + "as long " +  (long)directionX[j] * (long)coorX[k]
//													+ (long)directionY[j] * (long)coorY[k] + " as int " +  directionX[j] * coorX[k]
//															+ directionY[j] * coorY[k]);
							currentProjections[k] = (long)directionX[j] * (long)coorX[k]
									+ (long)directionY[j] * (long)coorY[k];
						}
						
						sortedProjections  = Arrays.copyOf(currentProjections, numOfPoints);
						Arrays.sort(sortedProjections);
//						System.out.println(Arrays.toString(sortedProjections));
//						System.out.println(Arrays.toString(currentProjections));
						for (int k = 0; k < numOfPoints; k++) {
							currDistanceToStart = numOfPoints;
							currDistanceToEnd = numOfPoints;
							boolean foundDistances = false;
							int indexThroughProjections = 0;
							boolean foundFirstIndex = false;
							while(!foundDistances ){
								if(!foundFirstIndex ){
								   if(sortedProjections[indexThroughProjections] == currentProjections[k]){
								     	foundFirstIndex = true;
								    	currDistanceToStart = indexThroughProjections;
								    	currDistanceToEnd = numOfPoints-indexThroughProjections-1;
							    	}
								}else{
									if(sortedProjections[indexThroughProjections] == currentProjections[k]){
								    	currDistanceToEnd = numOfPoints-1 -indexThroughProjections;
									}else{
										foundDistances = true;
									}
								}
								indexThroughProjections++; 
								if(indexThroughProjections>=numOfPoints){
									foundDistances = true;
								}
								
							}
//							System.out.println("Point " + k + " has currDistanceToStart" + currDistanceToStart +  " currDistanceToEnd " +currDistanceToEnd + " for direction ("
//							+ directionX[j]+";" +directionY[j]+ "), the jth (" + j + ") direction.");
							int minForKForThisDirection = Math.min(currDistanceToStart, currDistanceToEnd);
							if(numOfTreesToCut[k]>minForKForThisDirection){
//						     	System.out.println("decreasing from " + numOfTreesToCut[k] + " for tree " +k + "("+coorX[k]+";"+coorY[k]+") to " + minForKForThisDirection);
						     	numOfTreesToCut[k] = minForKForThisDirection;
							}
							
						}

					}

				} else {
					numOfTreesToCut[0] = 0;
					if(numOfPoints == 2){
						numOfTreesToCut[1] = 0;
						
					}
				}

				String outputString = "Case #" + (i + 1) + ": " + "\n";

				for (int j : numOfTreesToCut) {
					outputString += j + "\n";
				}
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
}
