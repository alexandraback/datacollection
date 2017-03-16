import java.util.*;
import java.io.*;

public class MagicTrick
{

    public static void main(String[] args) {

	Scanner in = new Scanner(System.in);
        
	int t = in.nextInt();

        for (int i = 0; i < t; i++) {
            int row_1 = in.nextInt() - 1;
            int[] numbers1 = new int[16];
            for (int j = 0; j < 16; j++) {
                numbers1[j] = in.nextInt() - 1;
            }
            int row_2 = in.nextInt() - 1;
            int[] numbers2 = new int[16];
            for (int j = 0; j < 16; j++) {
                numbers2[j] = in.nextInt() - 1;
            }
            int[] possibles = new int[16];
            for (int j = 0; j < 16; j++) {
                possibles[j] = 0;
            }
            for (int j = 0; j < 16; j++) {
                if ((j/4) == row_1) {
                    possibles[numbers1[j]] += 1;
                }
                if ((j/4) == row_2) {
                    possibles[numbers2[j]] += 1;
                }
            }
            boolean bad_mag = false;
            int number = -1;
            for (int j = 0; j < 16; j++) {
                if (possibles[j] >= 2) {
                    // Two possible numbers
                    if (number != -1) {
                        bad_mag = true;
                    }
                    number = j;
                }
            }
            
            // bad player
            System.out.print("Case #" + (i+1) + ": ");
            if (number == -1) {
                System.out.println("Volunteer cheated!");
            } else if (bad_mag) {
                System.out.println("Bad magician!");
            } else {
                System.out.println(number+1);
            }
        }
        
    }
}


