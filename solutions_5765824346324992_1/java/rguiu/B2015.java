import static java.lang.Integer.parseInt;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class B2015 {


    public static void main(String[] args) throws IOException {
        B2015 trans = new B2015();
        trans.doMe();
    }
//    private static final String ID = "practice";
//    private static final String SIZE = "small";
//    private static final String CODE = "A";

    private static final String NAME = "B-large";//"B-small-attempt3";//CODE+"-"+SIZE+"-"+ID;

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


    private String proccessLine(String line1, String line2) {
        System.out.println("++++++++++++++");
        String s1[] = line1.split(" ");

        int C = Integer.parseInt(s1[0]);
        int position = Integer.parseInt(s1[1]);

        int is[] = toIntArray(line2);

        List<BarberTime>barberTimes = new ArrayList<BarberTime>(C);

        if (position <= C) return Integer.toString(position);

        int current = 0;

        double costInMinute = 0;

        int maxTime = 0;
        for (int i = 0; i < is.length; i++) {
            costInMinute += 1.0/is[i];
            maxTime = Math.max(maxTime, is[i]);
        }

        double myTurn = position*1.0/costInMinute;

        long minutePrev = (long)myTurn;
        minutePrev-= maxTime;
        if (minutePrev<0) {
            minutePrev = 0;
        }
        System.out.println(myTurn+":"+minutePrev);

        System.out.println("> " + minutePrev + "-");
        for (int i = 0; i < C; i++) {
            long cuts = minutePrev / is[i];
            long cMinute = cuts * is[i];
            barberTimes.add(new BarberTime(i+1, cMinute));
            System.out.println(barberTimes.get(barberTimes.size() - 1));
            current+=cuts;
        }
//        if (current==position) {
//            return Integer.toString(C);
//        }
        System.out.printf("current: "+current);
        System.out.println(">> "+current+ "-"+position+"("+(position-current)+")");
        Collections.sort(barberTimes);

        while(current<position) {
            current++;
            BarberTime bt = barberTimes.remove(0);
            if (current == position) return Integer.toString(bt.barberIndex);
            barberTimes.add(new BarberTime(bt.barberIndex, bt.timeToFinish + is[bt.barberIndex - 1]));
            Collections.sort(barberTimes);
        }
        return "error";
    }


    class BarberTime implements Comparable<BarberTime> {
        int barberIndex;
        long timeToFinish;


        BarberTime(int barberIndex, long timeToFinish) {
            this.barberIndex = barberIndex;
            this.timeToFinish = timeToFinish;
        }

        @Override
        public int compareTo(BarberTime o) {
            if (timeToFinish != o.timeToFinish) {
                if (timeToFinish>o.timeToFinish) return 1;
                return -1;
            }
            return barberIndex - o.barberIndex;
        }

        public String toString() {
            return barberIndex+": "+timeToFinish;
        }
    }
}
