import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Created by benoi_000 on 4/16/2015.
 */
public class B {

    public static void main(String args[]) throws FileNotFoundException {
        final String defaultFile = B.class.getName()+".in";
        final PrintStream out;
        final InputStream in;
        if (args.length==0) {
            in = new FileInputStream("test/"+defaultFile);
            out =System.out;

        } else {
            in = new FileInputStream("resources/"+args[0]);
            out = new PrintStream(new FileOutputStream("result/"+args[0]));
        }
        Scanner scanner = new Scanner(in);
        int nbTest = scanner.nextInt();
        for (int i=0;i<nbTest;i++) {
            scanner.nextLine();
            long B =scanner.nextLong();
            long n = scanner.nextLong();
            scanner.nextLine();
            List<Long> params = new ArrayList<Long>();
            for (int j=0;j<B;j++) {
                params.add(scanner.nextLong());
            }

            Object res = comput(n,params);
            out.println("Case #"+(i+1)+": "+res);
        }

    }

    public static long comput(long N, List<Long> barbers) {
       double total = 0;
        long max = 0;
        for(long l:barbers) {
            total+=1d/ (double)l;
            max = Math.max(max, l);
        }
        double e =(double)(N-1)/total;
        long time = Math.max(0, (long) e  -max);
        long processed = 0;
        SortedSet<Barber> bees = new TreeSet<Barber>();

        for(int i=0;i<barbers.size();i++) {
            Barber barber = new Barber(i+1,barbers.get(i));
            if (time>0) {
                processed += 1 + Math.floor((double) time / (double) barber.time);
                barber.availability= barber.time- time%barber.time;
            }
            bees.add(barber);
        }
        Barber last = null;
        for (long i=processed;i<N;i++) {
            last = bees.first();
            bees.remove(last);
            last.book();
            bees.add(last);
        }
        return  last.id;
    }





    public static class Barber implements Comparable<Barber> {

        long id;
        long time;
        long availability;

        public Barber(long id, long time) {
            this.id = id;
            this.time=time;
        }
        public void book() {
            availability+=time;
        }
        @Override
        public int compareTo(Barber o) {
            int comp = Long.compare(availability,o.availability);
            if (comp==0) comp = Long.compare( id , o.id);
            return comp;
        }
    }

}
