package gcj2015.round1B.problemB;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public abstract class Main1B_B {

	public static void main(String[] args) throws Exception {
		// Open input and output files. (stdin and stdout are not used because
		// of the lack of support for using a file as stdin in Eclipse.)
		InputStream inStream = new FileInputStream(
			"input/B-large.in");
		OutputStream outStream = new FileOutputStream(
			"output/B-large-out.txt");
		
		Scanner in = new Scanner(new BufferedInputStream(inStream));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(outStream));
		
		int numCases = in.nextInt();
		for (int caseIdx = 1; caseIdx <= numCases; caseIdx++) {
			
			// Read the test case.
			int numRows = in.nextInt();
			int numCols = in.nextInt();
			int numTenants = in.nextInt();
			
			// Solve this test case;
			long result = solve(numRows, numCols, numTenants);
			
			// Print the result.
			String resultStr = String.format("%s", result);
			String fullResultStr = String.format("Case #%s: %s", caseIdx,
				resultStr);
			out.println(fullResultStr);
			System.out.println(fullResultStr);
		}
		
		in.close();
		out.close();
	}
	
	private static long solve(int numRows, int numCols, int numTenants) {
		// To simplify the logic, transform the problem so the width is never
		// greater than the height.
		int width = Math.min(numRows, numCols);
		int height = Math.max(numRows, numCols);
		
		int numEmpty = width * height - numTenants;
		
		// Check if there are enough empty spaces for a perfect score.
		if (numEmpty >= getNumEmptyForPerfect(width, height)) {
			return 0;
		}
		
		long score = 0;
		
		if (width == 1) {
			score = 2 * numEmpty;
		}
		
		else if (width == 2) {
			int numThreePoints = Math.min(numEmpty, Math.max(0, height - 2));
			int numTwoPoints = numEmpty - numThreePoints;
			score = 3 * numThreePoints + 2 * numTwoPoints;
		}
		
		else {
			int numFourPointsWay1 = Math.min(numEmpty,
				getNumFourPointsWay1(width, height));
			int numThreePointsWay1 = Math.min(numEmpty - numFourPointsWay1,
				getNumThreePointsWay1(width, height));
			if (numFourPointsWay1 + numThreePointsWay1 == numEmpty) {
				score = 4 * numFourPointsWay1 + 3 * numThreePointsWay1;
			}
			else {
				int numTwoPointsWay1 = Math.min(
					numEmpty - (numFourPointsWay1 + numThreePointsWay1),
					getNumTwoPointsWay1(width, height));
				
				int numFourPointsWay2 = Math.min(numEmpty,
					getNumFourPointsWay2(width, height));
				int numThreePointsWay2 = Math.min(numEmpty - numFourPointsWay2,
					getNumThreePointsWay2(width, height));
				int numTwoPointsWay2 = Math.min(
					numEmpty - (numFourPointsWay2 + numThreePointsWay2),
					getNumTwoPointsWay2(width, height));
				
				score = Math.max(
					4 * numFourPointsWay1 + 3 * numThreePointsWay1
					+ 2 * numTwoPointsWay1,
					4 * numFourPointsWay2 + 3 * numThreePointsWay2
					+ 2 * numTwoPointsWay2);
			}
		}
		
		return getNumBoundaries(width, height) - score;
	}
	
	private static long getNumBoundaries(int width, int height) {
		assert(width <= height);
		
		return 2 * (width - 1) * (height - 1) + (width + height - 2);
	}
	
	private static int getNumEmptyForPerfect(int width, int height) {
		assert(width <= height);
		
		if (width == 1) {
			return height / 2;
		}
		
		else if (width % 2 == 0) {
			return width * height / 2;
		}
		
		else {
			int numSmallRows = (height + 1) / 2;
			int numLargeRows = height / 2;
			
			return numSmallRows * (width / 2)
				+ numLargeRows * ((width + 1) / 2);
		}
	}
	
	private static int getNumFourPointsWay1(int width, int height) {
		assert(3 <= width && width <= height);
		
		return (width - 2) * (height - 2)
			- getNumEmptyForPerfect(width - 2, height - 2);
	}
	
	private static int getNumThreePointsWay1(int width, int height) {
		assert(3 <= width && width <= height);
		
		int numOuterCells = 2 * width + 2 * (height - 2);
		
		return (numOuterCells / 2) - getNumTwoPointsWay1(width, height);
	}
	
	private static int getNumTwoPointsWay1(int width, int height) {
		assert(3 <= width && width <= height);
		
		return (width % 2 == 0 || height % 2 == 0) ? 2 : 4;
	}
	
	private static int getNumFourPointsWay2(int width, int height) {
		assert(3 <= width && width <= height);
		
		return getNumEmptyForPerfect(width - 2, height - 2);
	}
	
	private static int getNumThreePointsWay2(int width, int height) {
		assert(3 <= width && width <= height);
		
		int numOuterCells = 2 * width + 2 * (height - 2);
		
		return (numOuterCells / 2) - getNumTwoPointsWay2(width, height);
	}
	
	private static int getNumTwoPointsWay2(int width, int height) {
		assert(3 <= width && width <= height);
		
		boolean widthEven = (width % 2 == 0);
		boolean heightEven = (height % 2 == 0);
		
		return (widthEven || heightEven) ? 2 : 0;
	}
}
