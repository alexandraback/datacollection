package com.nwollmann.codejam.year_2016.round1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Nicholas on 5/8/2016.
 */
public class Senate {

    static final boolean CONSOLE_MODE = false;
    static String fileName = "A-large";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

    public static void main(String[] args) throws Exception{
        if(CONSOLE_MODE) {
            writer = new PrintWriter(System.out);
            reader = new Scanner(System.in);
        } else {
            in = new File("C:/Codejam/in/" + fileName + ".in");
            out = new File("C:/Codejam/result.out");
            writer = new PrintWriter(new FileOutputStream(out));
            reader = new Scanner(new FileInputStream(in));
        }

        solve();

        writer.close();
        reader.close();
    }

    public static void solve(){

        int cases = reader.nextInt();

        for(int i = 1; i <= cases; i++) {
            writer.print("Case #" + i + ": ");
            solveCase();
            writer.println();
        }

    }

    public static void solveCase(){

        int partyCount = reader.nextInt();
        Party[] parties = new Party[partyCount];

        int totalPeople = 0;

        for(int i = 0; i < partyCount; i++) {
            parties[i] = new Party(i, reader.nextInt());
            totalPeople += parties[i].membersInRoom;
        }

        Arrays.sort(parties);

        char c;

        while(totalPeople > 3) {
            parties[0].membersInRoom--;
            c = (char)('A' + parties[0].id);
            writer.print(c);
            Arrays.sort(parties);
            parties[0].membersInRoom--;
            c = (char)('A' + parties[0].id);
            writer.print(c + " ");
            Arrays.sort(parties);
            totalPeople -= 2;
        }

        if(totalPeople == 3) {
            parties[0].membersInRoom--;
            c = (char)('A' + parties[0].id);
            writer.print(c + " ");
            Arrays.sort(parties);
            totalPeople--;
        }

        if(totalPeople == 2) {
            parties[0].membersInRoom--;
            c = (char) ('A' + parties[0].id);
            writer.print(c);
            Arrays.sort(parties);
            parties[0].membersInRoom--;
            c = (char) ('A' + parties[0].id);
            writer.print(c + " ");
            Arrays.sort(parties);
        }
    }

    public static class Party implements Comparable<Party>{
        int id;
        int membersInRoom;

        Party (int id, int membersInRoom) {
            this.id = id;
            this.membersInRoom = membersInRoom;
        }

        @Override
        public int compareTo(Party o) {
            return o.membersInRoom - this.membersInRoom;
        }
    }
}
