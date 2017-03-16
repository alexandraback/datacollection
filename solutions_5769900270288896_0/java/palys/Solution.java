package common;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public abstract class Solution {
	
	/**
	 * Used to solve one test case. Reads input from in, solves it and prints output to out.
	 * @param in input file Scanner
	 * @param out output file PrintStream
	 * @throws IOException
	 */
	public abstract void solve(Scanner in, PrintStream out) throws IOException;
	
	/**
	 * Returns folder name in which input and output folder are or are to be made.
	 * @return folder name
	 */
	public String folder() {
		return this.getClass().getSimpleName() + "_cases";
	}
	
	/**
	 * Returns input folder name. All files in input folder should ends with .in.
	 * @return folder name
	 */
	public String inFolder() {
		return folder() + "/in";
	}
	
	/**
	 * Returns output folder name.
	 * @return folder name
	 */
	public String outFolder() {
		return folder() + "/out";
	}
	
	private void ensureDirectoryExists(File f) {
		if (!f.isDirectory()) {
			f.mkdir();
		}
	}
	
	private String filePath(String file, String dir) {
		return dir + "/" + file;
	}
	
	/**
	 * Returns label which will be printed before each test case.
	 * @param n number of test case
	 * @return label
	 */
	protected String caseLabel(int n) {
		return "Case #" + (n+1) + ": ";
	}
	
	public void printCaseLabel(int n, PrintStream out) {
		out.print(caseLabel(n));
	}
	
	/**
	 * Reads all test cases stored in {@link #inFolder()}, solves them and prints output to {@link #outFolder()}.
	 */
	public void solve() {
		
		File folder = new File(folder());
		File inFolder = new File(inFolder());
		File outFolder = new File(outFolder());
		
		ensureDirectoryExists(folder);
		ensureDirectoryExists(outFolder);
		ensureDirectoryExists(inFolder);
		
		for (String in : inFolder.list()) {
			String fileNameCore = in.replace(".in", "");
			String outFileName = fileNameCore + ".out";
			
			
			PrintStream ps = null;
			Scanner s = null;
			try {
				File inFile = new File(filePath(in, inFolder()));
				File outFile = new File(filePath(outFileName, outFolder()));
				
				ps = new PrintStream(outFile);
				s = new Scanner(inFile);
				
				solve(s, ps);
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				if (s != null) {
					s.close();
				}
				
				if (ps != null) {
					ps.close();
				}
			}
				
			
		}
		
		
	}

}
