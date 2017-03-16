package shb.test.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * Generic input reader for CodeJam
 * @author shobo
 *
 */
public class JamInputReader {
	BufferedReader reader;
	public BufferedReader getReader() {
		return reader;
	}

	/**
	 * 
	 * @param file - filename, relative to current working directory.
	 * Put your files in /resources
	 * @throws FileNotFoundException 
	 */
	public JamInputReader(String filename) throws FileNotFoundException {
		File file = new File(filename);
		if (!file.exists()) {
			throw new FileNotFoundException(filename);
		}
		reader = new BufferedReader(new FileReader(file));
	}
	
	/**
	 * Reads a single integer on a line
	 * @return the only integer on the line
	 * @throws NumberFormatException
	 * @throws IOException
	 */
	public int readInt() throws NumberFormatException, IOException {
		return Integer.parseInt(reader.readLine());
	}
	
	public int[] readIntArray(int items) throws IOException   {
		String[] prc = reader.readLine().split(" ");
		int[] result = new int[items];
		for (int i = 0; i< items; i++) {
			result[i] = Integer.parseInt(prc[i]);
		}
		
		return result;
	}
	
	public String readLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}
	
	public void close() throws IOException {
		this.reader.close();
	}
}
