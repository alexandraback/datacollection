import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;

public class A {

	/**
	 * Fetch the entire contents of a text file, and return it in a String.
	 *
	 * @param aFile is a file which already exists and can be read.
	 */
	static public ArrayList<String> getContents(File aFile) {
		ArrayList<String> inputLines = new ArrayList<String>();
		try {
			BufferedReader input =  new BufferedReader(new FileReader(aFile));
			try {
				String line = null; 

				while (( line = input.readLine()) != null){
					inputLines.add(line);	         
				}
			}
			finally {
				input.close();
			}
		}
		catch (IOException ex){
			ex.printStackTrace();
		}

		return inputLines ; 
	}

	/**
	 * Change the contents of text file in its entirety, overwriting any
	 * existing text.
	 *
	 * @param aFile is an existing file which can be written to.
	 * @throws IllegalArgumentException if param does not comply.
	 * @throws FileNotFoundException if the file does not exist.
	 * @throws IOException if problem encountered during write.
	 */
	static public void setContents(File aFile, String aContents)
			throws FileNotFoundException, IOException {
		if (aFile == null) {
			throw new IllegalArgumentException("File should not be null.");
		}
		if (!aFile.exists()) {
			throw new FileNotFoundException ("File does not exist: " + aFile);
		}
		if (!aFile.isFile()) {
			throw new IllegalArgumentException("Should not be a directory: " + aFile);
		}
		if (!aFile.canWrite()) {
			throw new IllegalArgumentException("File cannot be written: " + aFile);
		}

		//use buffering
		Writer output = new BufferedWriter(new FileWriter(aFile));
		try {
			output.write( aContents );
		}
		finally {
			output.close();
		}
	}


	public static void solve(String fileName, String outputFileName){
		File testFile = new File(fileName); 
		String output = "";

		ArrayList<String> inputLines = getContents(testFile);

		int numOfTests = Integer.parseInt(inputLines.get(0));
		int lineIdx = 1;
		for(int testIdx = 0; testIdx < numOfTests; testIdx++){

			int row1 = Integer.parseInt(inputLines.get(lineIdx++));
			String[] rowStr;
			int[] rowInt = new int[4];
			for(int i = 0; i < 4; i++){
				String row = inputLines.get(lineIdx++);
				if(i == row1-1){
					rowStr = row.split(" ");
					for(int k = 0; k < rowStr.length; k++){
						rowInt[k] = Integer.parseInt(rowStr[k]);
					}
				}
			}
			
			int row2 = Integer.parseInt(inputLines.get(lineIdx++));
			int[] row2Int = new int[4];
			for(int i = 0; i < 4; i++){
				String row = inputLines.get(lineIdx++);
				if(i == row2-1){
					rowStr = row.split(" ");
					for(int k = 0; k < rowStr.length; k++){
						row2Int[k] = Integer.parseInt(rowStr[k]);
					}
				}
			}
			
			output +=  "Case #" + (testIdx + 1) + ": ";				 

			ArrayList<Integer> common = findCommon(rowInt, row2Int);
			if(common.size() == 1){
				output += common.get(0) + System.getProperty("line.separator");
			}
			else{
				if(common.size() == 0){
					output += "Volunteer cheated!" + System.getProperty("line.separator");

				}
				else{
					output += "Bad magician!" + System.getProperty("line.separator");
				}
			}
			
		}
		File outputFile = new File(outputFileName);
		if(!outputFile.exists()) {
			try {
				outputFile.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		} 
		try {
			setContents(outputFile, output);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static ArrayList<Integer> findCommon(int[] x, int[] y){
		ArrayList<Integer> common = new ArrayList<Integer>();
		Arrays.sort(x);
		Arrays.sort(y);
		int yIdx = 0;
		for(int i = 0; i < x.length; i++){
			for(yIdx = 0; yIdx < y.length && y[yIdx] <= x[i]; yIdx++){
				if(y[yIdx] == x[i]){
					common.add(x[i]);
				}
			}
		}
		return common;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	//	solve("test.in", "out-small.txt");

		solve("A-small-attempt0.in", "A-out-small.txt");

	}

}
