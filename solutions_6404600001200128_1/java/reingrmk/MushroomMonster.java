import java.io.*;
import java.util.Date;

/**
 * Date: 18/04/2015
 * Time: 03:05
 */

public class MushroomMonster {

    public static void main(String[] args) throws IOException {
        new MushroomMonster().doSomething();
    }

    void doSomething() throws IOException {
        try {
            File test = new File("src").getAbsoluteFile();
            File[] inList = test.listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    return name.toLowerCase().contains(".in");
                }
            });
            File fIn = inList[0];
            for (int i = 1; i < inList.length; i++) {
                if (new Date(fIn.lastModified()).compareTo(new Date(inList[i].lastModified())) < 0) {
                    fIn = inList[i];
                }
            }
            File fOut = new File("src" + File.separator + "MushroomMonster.out");
            BufferedReader in = new BufferedReader(new FileReader(fIn));
            BufferedWriter out = new BufferedWriter(new FileWriter(fOut));
            int n = Integer.valueOf(in.readLine());
            for (int i = 1; i <= n; i++) {
                out.write("Case #" + i + ": " + solve(in));
                out.newLine();
            }
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    String solve(BufferedReader in) throws IOException {
        int n = Integer.valueOf(in.readLine());
        String[] s = in.readLine().split(" ");
        int[] m = new int[n];
        for (int i = 0; i < n; i++) {
            m[i] = Integer.valueOf(s[i]);
        }

        int r1 = 0;
        int r2 = 0;

        int l = 0;

        for (int i = 0; i < n - 1; i++) {
            if (m[i] - m[i + 1] > 0) {
                r1 += m[i] - m[i + 1];
                if (m[i] - m[i + 1] > l) {
                    l = m[i] - m[i + 1];
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (m[i] < l) {
                r2 += m[i];
            } else {
                r2 += l;
            }
        }
        return r1 + " " + r2;
    }

}
