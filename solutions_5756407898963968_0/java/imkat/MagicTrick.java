import java.io.*;
import java.util.*;
public class MagicTrick {	
    public static void main(String[] args) throws IOException {
        File path = new File("A-small-attempt0.in");
        Scanner inFile = new Scanner(new FileReader(path));
    	PrintWriter outFile = new PrintWriter ("MagicTrick.out");
        int T = inFile.nextInt();
        for(int i = 1; i <= T; i++){
        	//input
        	int[][] ansRow = new int [2][4];
        	for(int j = 0; j < 2; j++){
        		int iAns = inFile.nextInt();
            	for(int k = 1; k < iAns; k++){
            		for(int ii = 1; ii <=4; ii++){
            			inFile.nextInt();
            		}
            	}
            	for(int k = 0; k < 4; k++){
            		ansRow[j][k] = inFile.nextInt();
            	}
            	for(int k = iAns + 1; k <= 4 ; k++){
            		for(int ii = 1; ii <=4; ii++){
            			inFile.nextInt();
            		}
            	}
        	}
        	//process
        	int ncard = 0;
        	int card = 0;
        	for(int j = 0; j < 4; j++){
        		for(int k = 0; k < 4; k++){
        			if(ansRow[0][j] == ansRow[1][k]){
        				ncard++;
        				card = ansRow[0][j];
        			}
        		}
        	}
        	//output
        	outFile.print("Case #");
        	outFile.print(i);
        	outFile.print(": ");
        	if(ncard == 0){
        		outFile.println("Volunteer cheated!");
        	} else if(ncard == 1){
        		outFile.println(card);
        	} else {
        		outFile.println("Bad magician!");
        	}
        }
        inFile.close();
        outFile.close();
    }
}