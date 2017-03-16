import java.util.*;
import java.io.*;

public class codejam {
    private static String filename = "A-small-attempt0";

    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(directory + filename + ".in"));
        StringBuilder sb = new StringBuilder();
        
        String line = br.readLine();
        int caseTotal = Integer.parseInt(line);
        int caseNum = 1;
        
        while (caseNum <= caseTotal) {
            int row = Integer.parseInt(br.readLine());
            String row1 = "", row2 = "";
            
            for (int i = 1; i <= 4; ++i) {
                line = br.readLine();
                if (i == row) {
                    row1 = line;
                }
            }
            
            row = Integer.parseInt(br.readLine());
            for (int i = 1; i <= 4; ++i) {
                line = br.readLine();
                if (i == row) {
                    row2 = line;
                }
            }
            
            String[] rowNum1 = row1.split("\\s+");
            String[] rowNum2 = row2.split("\\s+");
            
            ArrayList<String> al = new ArrayList<String>();
            
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (rowNum1[i].equals(rowNum2[j])) {
                        al.add(rowNum1[i]);
                    }
                }
            }
            
            String result = "";
            if (al.size() == 0) {
                result = "Volunteer cheated!";
            } else if (al.size() == 1) {
                result = al.get(0);
            } else {
                result = "Bad magician!";
            }
            
            sb.append(String.format("Case #%d: %s" + newLineChar, caseNum++, result));
        }
 
        writeToFile(sb);
		System.out.println("Done");
    }
    
    public static void writeToFile(StringBuilder sb) throws IOException { 
		File file = new File(directory + filename + ".out");
        if (!file.exists()) {
            file.createNewFile();
        }

        FileWriter fw = new FileWriter(file.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write(sb.toString());
        bw.close();
    }
    
    private static String newLineChar = System.getProperty("line.separator");
    private static String directory = "C:\\Users\\Qing\\Desktop\\";
}

