package com.greggc.codejam;

import java.io.File;

import com.greggc.codejam.utils.FileUtils;

public class Problem1 {

	
	public void solve() {
		StringBuilder builder = new StringBuilder();
		File input = new File("A-small-attempt0.in");
		if (input.exists()) {
			String[] strings = FileUtils.getFileAsString(input);
			int nbTestCases = Integer.parseInt(strings[0]);
			
			for (int i = 0; i < nbTestCases; i++) {
				int firstAnswer = Integer.parseInt(strings[(i * 10) + 1]);
				int secondAnswer = Integer.parseInt(strings[(i * 10) + 6]);
				String[] lines = new String[4];
				
				lines[0] = strings[(i * 10) + 2];
				lines[1] = strings[(i * 10) + 3];
				lines[2] = strings[(i * 10) + 4];
				lines[3] = strings[(i * 10) + 5];
				int[][] firstSquare = this.squareStringToIntTable(lines);

				lines[0] = strings[(i * 10) + 7];
				lines[1] = strings[(i * 10) + 8];
				lines[2] = strings[(i * 10) + 9];
				lines[3] = strings[(i * 10) + 10];
				int[][] secondSquare = this.squareStringToIntTable(lines);
				
				System.out.println("Case #" + (i + 1) + ": " + this.solveTestCase(firstAnswer, secondAnswer, firstSquare, secondSquare));
				builder.append("Case #" + (i + 1) + ": " + this.solveTestCase(firstAnswer, secondAnswer, firstSquare, secondSquare));
				builder.append('\n');
			}
			
			FileUtils.stringToFile(builder.toString(), "A-small-attempt0.out");
			
		} else {
			System.out.println("Can't find " + input.getAbsolutePath());
		}
	}
	
	private String solveTestCase(int firstAnswer, int secondAnswer, int[][] firstSquare, int[][] secondSquare) {
		String result = "Bad magician!";
		
		int[] possibles = firstSquare[firstAnswer - 1];
		
		int[] possibles2 = secondSquare[secondAnswer - 1];
		
		Integer solution = null;
		boolean moreThanOne = false;
		for (int i = 0; i < 4; i ++) {
			for (int j = 0; j < 4; j ++) {
				if (possibles[i] == possibles2[j]) {
					if (solution != null) {
						moreThanOne = true;
					} else {
						solution = possibles[i];
					}
				}
			}
		}
		
		if (!moreThanOne) {
			if (solution == null) {
				result = "Volunteer cheated!";
			} else {
				result = solution.toString();
			}
		}
		return result;
	}
	
	private int[][] squareStringToIntTable(String[] lines) {
		int[][] result = new int[4][4];
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result[i][j] = Integer.parseInt(lines[i].split(" ")[j]);
			}
		}
		
		
		return result;
	}
}
