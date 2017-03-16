/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;
import java.util.Set;
import java.util.TreeSet;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_MagicTrick {
    public static final String problemLetter = "A";
    
    static Set<Integer> getSet(BufferedReader reader) throws IOException{
    	int row = Integer.parseInt(reader.readLine());
    	Set<Integer> set = new TreeSet<Integer>();
    	for(int i=0; i < 4; i++){
    		String[] str = reader.readLine().split(" ");
    		if(i == row-1){
    	    	for(int j=0; j < 4; j++){
    	    		set.add(Integer.parseInt(str[j]));
    	    	}
    		}
    	}
    	return set;
    }
    
    public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
        int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
        	Set<Integer> first = getSet(reader);
        	Set<Integer> second = getSet(reader);
        	TreeSet<Integer> result = new TreeSet<Integer>();
            for(int val:first){
            	if(second.contains(val)){
            		result.add(val);
            	}
            }
            if(result.size()==0){
                System.out.println("Case #" + caseNum + ": Volunteer cheated!");
                writer.println("Case #" + caseNum + ": Volunteer cheated!");
            }else if(result.size()>1){
                System.out.println("Case #" + caseNum + ": Bad magician!");
                writer.println("Case #" + caseNum + ": Bad magician!");
            }else{
                System.out.println("Case #" + caseNum + ": " + result.first());
                writer.println("Case #" + caseNum + ": " + result.first());
            }
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File folder = new File(".");
        for(final File entry:folder.listFiles()){
            if(entry.getName().endsWith(".in") && entry.getName().startsWith(problemLetter)){
                BufferedReader reader = new BufferedReader(new FileReader(entry));
                String fileOut = entry.getName().substring(0, entry.getName().length()-3) + ".out";
                System.out.println(entry.getName() + " -> " + fileOut);
                PrintWriter writer = new PrintWriter(fileOut);
                solve(reader, writer);
                reader.close();
                writer.close();
            }
        }
    }
    
}
