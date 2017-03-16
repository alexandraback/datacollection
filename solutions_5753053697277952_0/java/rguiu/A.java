import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class A {


    public static void main(String[] args) throws IOException {
        A trans = new A();
        trans.doMe();
    }

    private static final String NAME = "A-small-attempt0";

    public void doMe() throws IOException {
        File file = new File("./inputs/"+NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter("./output/"+NAME+".out"));
        try {
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);
                for (int i=0;i<count;i++) {
                    line = input.readLine();
                    String line2 = input.readLine();
                    String str = this.proccessLine(line.trim(), line2.trim());
                    out.write("Case #"+(i+1)+": "+str);
                    if (i<count-1)
                        out.write(System.getProperty("line.separator"));
                    System.out.println(str);
                }
            } finally {
                input.close();
                out.flush();
                out.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    String proccessLine(String line1, String line2) {
        int count = Integer.parseInt(line1);
        String tokens[] = line2.split(" ");

        Party p[] = new Party[count];
        int total  = 0;
        for (int i = 0; i < tokens.length; i++) {
            int uu = Integer.parseInt(tokens[i]);
            p[i] = new Party(uu, i);
            total += uu;
        }

        List<Party> parties = Arrays.asList(p);
        Collections.sort(parties);

        List<String>sol = new ArrayList<>();

        while(total > 0) {
            if (total==3) {
                sol.add(Character.toString(alpha.charAt(parties.get(0).index)));
                parties.get(0).sens -= 1;
                total--;
                Collections.sort(parties);
            } else {
                String a = "";
                for (int i = 0; i < 2; i++) {
                    a += alpha.charAt(parties.get(0).index);
                    parties.get(0).sens -= 1;
                    total--;
                    Collections.sort(parties);
                }
                sol.add(a.trim());
            }
        }
        return sol.stream().collect(Collectors.joining(" "));
    }

    class Party implements  Comparable<Party>{
        int sens = 0;
        int index;

        Party(int sens, int index) {
            this.sens = sens;
            this.index = index;

        }

        @Override
        public int compareTo(Party o) {
            return o.sens - sens;
        }
    }

}
