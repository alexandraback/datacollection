package qual2014;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.HashSet;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("qual2014/A-sample.in"), System.out);
        io = new Kattio(new FileInputStream("qual2014/A-small-0.in"), new FileOutputStream("qual2014/A-small-0.out"));
//        io = new Kattio(new FileInputStream("qual2014/A-large.in"), new FileOutputStream("qual2014/A-large.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new A().solve(io);
        }
        io.close();
    }

    private HashSet<Integer> getCandidates(Kattio io) {
        HashSet<Integer> h = new HashSet<>();
        int row = io.getInt();
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j < 4; j++) {
                int y = io.getInt();
                if (row == i) h.add(y);
            }
        }
        return h;
    }

    private void solve(Kattio io) {
        HashSet<Integer> c1 = getCandidates(io), c2 = getCandidates(io);
        c1.retainAll(c2);
        if (c1.size() == 0) {
            io.println("Volunteer cheated!");
        } else if (c1.size() > 1) {
            io.println("Bad magician!");
        } else {
            io.println(c1.iterator().next());
        }
    }
}
