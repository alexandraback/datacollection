import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by linxy on 4/29/16.
 */
public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("A-small-attempt0.out"));
        int numCase = in.nextInt();
        in.nextLine();
        for (int caseNum = 1; caseNum <= numCase; caseNum++) {
            out.print("Case #" + caseNum + ": ");
            int n = Integer.parseInt(in.nextLine());
            PriorityQueue<Party> maxQueue = new PriorityQueue<>(new Comparator<Party>() {
                @Override
                public int compare(Party o1, Party o2) {
                    if (o1.num == o2.num) {
                        return Character.compare(o1.c, o2.c);
                    }
                    return -Integer.compare(o1.num, o2.num);
                }
            });
            String line = in.nextLine();
            String[] splits = line.split(" ");
            for (int i = 0; i < n; i++) {
                Party p = new Party((char) ('A' + i), Integer.parseInt(splits[i]));
                if (p.num > 0) {
                    maxQueue.add(p);
                }
            }
            while (maxQueue.size() > 2) {
                Party p = maxQueue.poll();
                out.print(p.c + " ");
                p.num--;
                if (p.num > 0) {
                    maxQueue.add(p);
                }
            }
            Party p1 = maxQueue.poll();
            Party p2 = maxQueue.poll();
            if (p1.num < p2.num) {
                Party tmp = p1;
                p1 = p2;
                p2 = tmp;
            }
            for (int i = 0; i < p1.num - p2.num; i++) {
                out.print(p1.c + " ");
            }
            for (int i = 0; i < p2.num; i++) {
                out.print(p1.c + "" + p2.c + " ");
            }
            out.println();
        }
        in.close();
        out.close();
    }
}

class Party {
    int num;
    char c;
    public Party(char c, int num) {
        this.c = c;
        this.num = num;
    }
}