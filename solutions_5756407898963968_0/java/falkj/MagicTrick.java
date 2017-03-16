import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class MagicTrick {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	    try {
	    	Scanner in = new Scanner(new FileReader("D:/input.txt"));
	    	PrintWriter writer = new PrintWriter("D:/output.txt", "UTF-8");
	    	int testCases = in.nextInt();
	    	int firstRow, secondRow;
	    	for (int i = 1; i <= testCases; i++) {
	    		firstRow = in.nextInt();
	    		int goToRow = 0;
	    		while((firstRow - 1) * 4 > goToRow) {
	    			in.nextInt();
	    			goToRow++;
	    		}
	    		HashSet<Integer> possibleCards = new HashSet<Integer>(); 
	    		possibleCards.add(in.nextInt());
	    		possibleCards.add(in.nextInt());
	    		possibleCards.add(in.nextInt());
	    		possibleCards.add(in.nextInt());
	    		goToRow += 4;
	    		
	    		while(goToRow < 16) {
	    			in.nextInt();
	    			goToRow++;
	    		}
	    		
	    		secondRow = in.nextInt();
	    		goToRow = 0;
	    		
	    		while (((secondRow - 1) * 4)  > goToRow) {
	    			in.nextInt();
	    			goToRow++;
	    		}
	    		
	    		int counter = 0;
	    		int correctCard = -1;
	    		int newCard;
	    		for (int j = 0; j < 4; j++) {
	    			if (possibleCards.contains(newCard = in.nextInt())) {
	    					counter++;
	    					correctCard = newCard;
	    			}
	    		}
	    		goToRow += 4;
	    		while(goToRow < 16) {
	    			in.nextInt();
	    			goToRow++;
	    		}
	    		if (counter == 1) {
	    			writer.println("Case #" + i + ": " + correctCard);
	    		} else if (counter == 0) {
	    			writer.println("Case #" + i + ": Volunteer cheated!");
	    		} else {
					writer.println("Case #" + i + ": Bad magician!");
	    		}
	    	}
	    	writer.close();
	    	in.close();
	    } catch (Exception e) {
			e.printStackTrace();
			System.out.println(e.getLocalizedMessage());
		}
	}

}
