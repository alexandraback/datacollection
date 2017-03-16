import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemA {
    static String in = "src/a.in";
    static String out = "src/a.out";

    public static void main(String[] args) throws FileNotFoundException, IOException {
        //int cards1[][] = new int[4][4];
        //int cards2[][] = new int[4][4];
        boolean possibles[] = new boolean[17];

        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        for(int x = 1; x <= numlines; x++) {
            for(int a = 0; a < 16; a++) {
                possibles[a] = false;
            }

            int row1 = scan.nextInt();
            for(int a = 0; a < 4; a++) {
                if(a+1 == row1) {
                    for(int b = 0; b < 4; b++) {
                        possibles[scan.nextInt()] = true;
                    }
                } else {
                    for(int b = 0; b < 4; b++) {
                        possibles[scan.nextInt()] = false;
                    }
                }
            }

            int numPossible = 4;

            int row2 = scan.nextInt();
            for(int a = 0; a < 4; a++) {
                if(a+1 == row2) {
                    scan.nextInt();
                    scan.nextInt();
                    scan.nextInt();
                    scan.nextInt();
                } else {
                    for(int b = 0; b < 4; b++) {
                        int card = scan.nextInt();
                        if(possibles[card]) {
                            numPossible--;
                            possibles[card] = false;
                        }
                    }
                }
            }

            if(numPossible < 1) {
                write.write("Case #" + x + ": Volunteer cheated!");
            }
            else if(numPossible > 1) {
                write.write("Case #" + x + ": Bad magician!");
            }
            else {
                int num = 0;
                for(int a = 1; a <= 16; a++) {
                    if(possibles[a]) {
                        num = a;
                        break;
                    }
                }
                write.write("Case #" + x + ": " + num);
            }
            write.write("\n");

        }
        scan.close();

        write.close();
    }
}
