import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import javax.swing.JFileChooser;

public class ProblemA {

    public static void main(String[] args) {
    	
        JFileChooser fc = new JFileChooser("C:\\Users\\ede\\Desktop\\codeJam");
        int res = fc.showOpenDialog(null);
        if(res == JFileChooser.APPROVE_OPTION){
            File file = fc.getSelectedFile();
            try{
                computeFile(file);
                System.out.println("done. ");
            }catch(FileNotFoundException ex){
                System.err.println("file not found: " + ex);
            } catch (IOException ex) {
                System.err.println("io exception: " + ex);
            }
        }
    }
    
    public static void computeFile(File file) throws FileNotFoundException, IOException{
        BufferedReader in = new BufferedReader(new FileReader(file));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File(file.getParent(), "solution.txt")));
        int nCases = Integer.parseInt(in.readLine());
        for(int i=0; i<nCases; i++){
        	int N = Integer.parseInt(in.readLine());
        	String[] words = new String[N];
        	for(int j=0; j<words.length; j++)
        		words[j] = in.readLine();
            String solution = computeCase(words);
            String line = "Case #" + (i+1) + ": " + solution + "\n";
            System.out.print(line);
            out.write(line);
        }
        in.close();
        out.close();
    }
    
    public static String computeCase(String[] words) {
    	String normalizedWord = normalize(words[0]);
    	int[][] nums = new int[normalizedWord.length()][words.length];
    	for(int i=0; i<words.length; i++) {
    		if(!normalizedWord.equals(normalize(words[i])))
    			return "Fegla Won";
    		int[] conversion = convert(words[i], normalizedWord);
    		for(int j=0; j<conversion.length; j++) {
    			nums[j][i] = conversion[j];
    		}
    	}
    	int[] medians = new int[normalizedWord.length()];
    	for(int i=0; i<medians.length; i++) {
    		Arrays.sort(nums[i]);
    		int mIndex = nums[i].length/2;
    		medians[i] = nums[i][mIndex];
    	}
    	int steps = 0;
    	for(int i=0; i<nums.length; i++) {
    		for(int j=0; j<nums[i].length; j++){
    			steps += Math.abs(nums[i][j] - medians[i]);
    		}
    	}
    	return "" + steps;
    }
    
    public static String normalize(String word) {
    	String result = "";
    	char prev = word.charAt(0);
    	result += prev;
    	for(int i=1; i<word.length(); i++) {
    		if(word.charAt(i) != prev) {
    	    	prev = word.charAt(i);
    	    	result += prev;
    		}
    	}
    	return result;
    }

    public static int[] convert(String word, String normalized) {
    	int[] result = new int[normalized.length()];
    	char prev = word.charAt(0);
    	int jChar = 0;
    	result[jChar] += 1;
    	for(int i=1; i<word.length(); i++) {
    		if(word.charAt(i) != prev) {
    	    	prev = word.charAt(i);
    	    	jChar++;
    		}
        	result[jChar] += 1;
    	}
    	return result;
    }
}
