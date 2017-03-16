package util.io;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;

public class FileAccess {

	protected static final String LINE_SEP=System.getProperty("line.separator");

	/**
	 * Returns the text content of the file in a String array, where each element
	 * of the array holds on line of the text.
	 */
	public static String[] readFileIntoArray(File f){
		final LinkedList<String> lines = new LinkedList<>();
		try {
			BufferedReader fileReader=new BufferedReader(new FileReader(f));
			String nextLine = fileReader.readLine();
			while (nextLine!=null){
				lines.add(nextLine);
				nextLine = fileReader.readLine();
			}
			fileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		return lines.toArray(new String[]{});
	}	
	
	
	/**@deprecated use readFileIntoArray to avoid coding problems of line breaks and improve efficiency
	 * Returns the text content of the file specified by file.
	 */
	public static String readFile(File f){
		String content="";
		String nextLine="";
		try {
			BufferedReader fileReader=new BufferedReader(new FileReader(f));
			nextLine = fileReader.readLine();
			while (nextLine!=null){
				content += nextLine + LINE_SEP;
				nextLine = fileReader.readLine();
			}
			fileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		return content;
	}
	
	/**
	 * Write content into the File specified by dest.</br>
	 * <b>ATTENTION:</b> If dest already exists in the file system, it will
	 * be overwritten without request.
	 */
	public static boolean write(String content, File dest){
		//int hashValue=getHashValue(content);
		try {
			FileWriter fileWriter = new FileWriter(dest);
			fileWriter.write(content);
			fileWriter.flush();
			fileWriter.close();
		} catch (IOException e) {
				e.printStackTrace();
				return false;
		}
		return true;
	}
}
