import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class Magician {

    
    
    /**
     * @param args
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please add the file name as the first parameter");
        }
        
        Magician sc = new Magician();
        
        try {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            int cases = Integer.parseInt(in.readLine());
            
            String[] cards1;
            String[] cards2;
            
            String matrix1 = null;
            String matrix2 = null;
            for (int caseNo = 1; caseNo <= cases; caseNo++) {
                // get test case data
                int row1 = Integer.parseInt(in.readLine());
                for (int j = 1; j <= 4; j++) {
                    if (j == row1)
                        matrix1 = in.readLine();
                    else
                        in.readLine();
                }
                
                int row2 = Integer.parseInt(in.readLine());
                for (int j = 1; j <= 4; j++) {
                    if (j == row2)
                        matrix2 = in.readLine();
                    else
                        in.readLine();
                }
                
                cards1 = matrix1.split("\\s");
                cards2 = matrix2.split("\\s");
                
                System.out.print("Case #" + caseNo + ": ");
                compare(cards1, cards2);
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static void compare(String[] cards1, String[] cards2) {
        int sameCount = 0;
        String same = null;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (cards1[i].equals(cards2[j])) {
                    sameCount++;
                    if (sameCount == 1) {
                        same = cards1[i];
                    }
                }
            }
        }
        
        if (sameCount == 0) {
            System.out.println("Volunteer cheated!");
        } else if (sameCount == 1) {
            System.out.println(same);
        } else {
            System.out.println("Bad magician!");
        }
    }
    
}
