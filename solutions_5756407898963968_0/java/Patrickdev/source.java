import java.io.*;
import java.util.ArrayList;

/**
 * Created by Patrick on 12-4-14.
 */
public class MagicTrick {

    final static String INPUTFILE = "D:\\gcj\\2014\\magictrick\\A-small-attempt0.in";

    static void docase(int casenumber) throws Exception {

        int row1 = in.nextInt(),
                row2;
        ArrayList<Integer> list1 = new ArrayList<Integer>(),
                list2 = new ArrayList<Integer>();

        for (int i = 1; i <= 4; i++) {
            if (i == row1) {
                for (int a = 0; a < 4; a++) {
                    list1.add(in.nextInt());
                }
            } else {
                // skip
                in.nextLine();
            }
        }

        row2 = in.nextInt();

        for (int i = 1; i <= 4; i++) {
            if (i == row2) {
                for (int a = 0; a < 4; a++) {
                    list2.add(in.nextInt());
                }
            } else {
                // skip
                in.nextLine();
            }
        }


        ArrayList<Integer> common = new ArrayList<Integer>();
        // find common
        for (int i : list1) {
            if (list2.contains(i)) {
                common.add(i);
            }
        }

        out.add("Case #" + casenumber + ": " + (common.size() == 0 ? "Volunteer cheated!" : (common.size() > 1 ? "Bad magician!" : common.get(0))));

    }



    public static void main(String args[]) {
        try {

            int totalcases = in.nextInt();

            caseloop:
            for (int currentcase = 1; currentcase <= totalcases; currentcase++) {

                docase(currentcase);

            }

            out.write();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    static class In {
        BufferedReader br;
        String buffer = "";

        In() throws Exception {
            br = new BufferedReader(new FileReader(INPUTFILE));
        }

        String nextLine() throws Exception {
            buffer = "";
            return br.readLine();
        }

        String nextString() throws Exception {
            if (buffer.equals("")) {
                buffer = nextLine();
            }

            String line = buffer;

            if (line.contains(" ")) {
                int spacePos = line.indexOf(" ");
                buffer = line.substring(spacePos + 1, line.length());
                return line.substring(0, spacePos);
            } else {
                buffer = "";
                return line;
            }

        }

        int nextInt() throws Exception {
            return Integer.parseInt(nextString());
        }
    }

    static class Out {
        StringBuilder strBuilder = new StringBuilder();

        void add(Object str) {
            strBuilder.append(str.toString());
            strBuilder.append("\n");
            log(str);
        }

        void write() throws Exception {
            File file = new File(INPUTFILE.replace(".in", ".out"));
            if (file.exists()) {
                file.delete();
                file.createNewFile();
            }

            BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
            bw.write(strBuilder.toString());
            bw.close();
        }
    }

    static In in;
    static Out out;
    static {
        try {
            in = new In();
            out = new Out();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }


    static void log(Object o) {
        System.out.println("" + o);
    }
}
