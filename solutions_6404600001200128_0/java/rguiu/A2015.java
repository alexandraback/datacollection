import static java.lang.Integer.parseInt;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.StringTokenizer;

public class A2015 {


    public static void main(String[] args) throws IOException {
        A2015 trans = new A2015();
        trans.doMe();
    }
//    private static final String ID = "practice";
//    private static final String SIZE = "small";
//    private static final String CODE = "A";

    private static final String NAME = "A-small-attempt0";//"B-small-attempt3";//CODE+"-"+SIZE+"-"+ID;

    public void doMe() throws IOException {
        Path path = Paths.get("inputs/"+NAME + ".in");
        List<String> lines = Files.readAllLines(path);

        BufferedWriter out = new BufferedWriter(new FileWriter("output/"+NAME+".out"));
        try {
            try {
                int count = parseInt(lines.remove(0));

                for (int i=0;i<count;i++) {
                    String str = this.proccessLine(lines.get(2*i).trim(), lines.get(2*i+1));
                    out.write("Case #"+(i + 1)+": "+str);
                    if (i<count-1)
                        out.write(System.getProperty("line.separator"));
                    System.out.println(lines.get(i));
                    System.out.println(str);
                }
            } finally {
                out.flush();
                out.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    int[] toIntArray(String str) {
        StringTokenizer tokens = new StringTokenizer(str);
        int[] a= new int[tokens.countTokens()];
        int i = 0;
        while(tokens.hasMoreElements()) {
            a[i++] = parseInt(tokens.nextToken());
        }
        return a;
    }


    private String proccessLine(String line, String line2) {
        String s[] = line2.split(" ");
        int C = Integer.parseInt(line);

        int is[] = new int[C];

        for (int i = 0; i < C; i++) {
            is[i] = Integer.parseInt(s[i]);
        }

        int prev = is[0];
        int maxv1 = 0;

        int mI = 0;
        for (int i = 1; i < C; i++) {
            if (is[i] < prev) {
                maxv1 += prev - is[i];
                mI = Math.max(mI, prev - is[i]);
            }
            prev = is[i];
        }

        int maxv2 = 0;

        for (int i = 0; i < C - 1; i++) {
            maxv2 += Math.min(is[i], mI);
        }



        return maxv1 + " " + maxv2;
    }

}
