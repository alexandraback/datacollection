package jam;

import java.io.*;
import java.util.Scanner;

public class Main {
    static String inputfile = "qual_b.in";
    static String outputfile = "1b_b.out";
    static String answer;
    static BufferedWriter writer;
    static Scanner scanner;

    public static void writeAnswer(int caseNum) throws Exception {
        System.out.println("Case #" + caseNum + ": " + answer);
        writer.write("Case #" + caseNum + ": " + answer);
        writer.newLine();
    }

    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(inputfile));
        writer = new BufferedWriter(new FileWriter(outputfile));

        //Case loop:
        int numCases = scanner.nextInt();
        for(int caseNum = 1; caseNum <= numCases; caseNum++) {
            //System.out.println("starting case num: " + caseNum);
            answer = "";
            solve();
            writeAnswer(caseNum);
        }

        //Cleanup:
        scanner.close();
        writer.close();
    }


    static int r;
    static int c;
    static int numHoles;
    static int start;

    public static void solve() {
        // get input from scanner
        // write answer to answer

        r = scanner.nextInt();
        c = scanner.nextInt();
        int numTenants = scanner.nextInt();
        System.out.println(r + " " + c + " " + numTenants);

        if((numTenants < ((r * c) % 2 == 1 ? (r*c)/2 + 1 : (r*c)/2))
                || (r == 1 && c == 1)) {
            answer = "0";
            return;
        }

        numHoles = r * c - numTenants;

        start = (r-1) * c + r * (c-1);

        if(r == 1 || c == 1) {
            int one = r == 1 ? r : c;
            int two = r == 1 ? c : r;

            // subtract up to
            if(numHoles < two/2) {
                start = (start - numHoles * 2);
            }
            else {
                start = 0;
            }

            answer = "" + start;
            return;
        }

        int even = getEvenUnhappiness();
        int odd = getOddUnhappiness();
        answer = "" + (even < odd ? even : odd);
    }

    static int getEvenUnhappiness() {
        int result = start;
        int curHoles = numHoles;
        System.out.println("even result: " + result);


        // subtract centers whose coordinates have even sums
        // how many available?
        int numCenters = 0;
        for(int x = 1; x < r-1; x++) {
            for(int y = 1; y < c-1; y++) {
                if((x+y) % 2 == 0) numCenters++;
            }
        }

        int centersSubtracted = numCenters < curHoles ? numCenters : curHoles;
        curHoles -= centersSubtracted;
        result = result - 4*centersSubtracted;
        System.out.println("even result: " + result);

        int numSides = 0;
        int totalEdge = 2 * r + 2 * c - 4;
        int totalEdgeHoles = totalEdge / 2;
        numSides = (r * c) % 2 == 1 ? totalEdgeHoles - 4 : totalEdgeHoles - 2;
        System.out.println("numSides: " + numSides);

        int sidesSubtracted = numSides < curHoles ? numSides : curHoles;
        curHoles -= sidesSubtracted;
        result = result - 3*sidesSubtracted;
        System.out.println("even result: " + result);

        int numCorners = totalEdgeHoles - numSides;

        int cornersSubtracted = numCorners < curHoles ? numCorners : curHoles;
        curHoles -= cornersSubtracted;
        result = result - 2*cornersSubtracted;
        System.out.println("even result: " + result);

        return result;
    }

    static int getOddUnhappiness() {
        int result = start;
        int curHoles = numHoles;
        System.out.println("odd result: " + result);

        // subtract centers whose coordinates have even sums
        // how many available?
        int numCenters = 0;
        for(int x = 1; x < r-1; x++) {
            for(int y = 1; y < c-1; y++) {
                if((x+y) % 2 == 1) numCenters++;
            }
        }

        int centersSubtracted = numCenters < curHoles ? numCenters : curHoles;
        curHoles -= centersSubtracted;
        result = result - 4*centersSubtracted;
        System.out.println("odd result: " + result);

        int numSides = 0;
        int totalEdge = 2 * r + 2 * c - 4;
        int totalEdgeHoles = totalEdge / 2;
        numSides = (r * c) % 2 == 1 ? totalEdgeHoles : totalEdgeHoles - 2;

        int sidesSubtracted = numSides < curHoles ? numSides : curHoles;
        curHoles -= sidesSubtracted;
        result = result - 3*sidesSubtracted;
        System.out.println("odd result: " + result);

        int numCorners = totalEdgeHoles - numSides;

        int cornersSubtracted = numCorners < curHoles ? numCorners : curHoles;
        curHoles -= cornersSubtracted;
        result = result - 2*cornersSubtracted;
        System.out.println("odd result: " + result);

        return result;
    }
}

