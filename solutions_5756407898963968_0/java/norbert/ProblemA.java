import java.io.DataInputStream;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.ObjectInputStream;
import java.io.Reader;
import java.util.Scanner;

public class ProblemA {

    public static void main(String[] args) throws Exception {

        int t, a1 = 0, a2 = 0;
        int b1[] = new int[16], b2[] = new int[16];

        Scanner in = new Scanner(System.in);
        
        t = in.nextInt();

        for(int t_ = 0; t_ < t; t_++) {

            a1 = in.nextInt();
            for (int i = 0; i < 16; i++) {
                b1[i] = in.nextInt();
            }

            a2 = in.nextInt();
            for (int i = 0; i < 16; i++) {
                b2[i] = in.nextInt();
            }

            int hit = 0, v = 0;
            for (int i = (a1-1) * 4; i < a1 * 4; i++) {
                for (int j = (a2-1) * 4; j < a2 * 4; j++)
                    if (b1[i] == b2[j]) {
                        hit++;
                        v = b1[i];
                    }
            }

            String prefix = "Case #" + (t_+1) + ": ";

            if (hit == 0) {
                System.out.println(prefix + "Volunteer cheated!");
            } else if (hit == 1) {
                System.out.println(prefix + v);
            } else {
                System.out.println(prefix + "Bad magician!");
            }
        }
    }
}
