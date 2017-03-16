
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by lin on 4/15/14.
 */
public class InputHandler {
    public static void main(String[] args) {
        try {
            BufferedReader br =
                    new BufferedReader(new InputStreamReader(System.in));
            String line = br.readLine();

            int caseCount = 1;

            while ((line = br.readLine()) != null) {
                int strCount = Integer.parseInt(line);
                List<StringBuilder> strings = new ArrayList<StringBuilder>();
                for(int i = 0; i < strCount; ++i) {
                    line = br.readLine();
                    strings.add(new StringBuilder(line));

                }

                System.out.println("Case #" + caseCount + ": " + ASolution.solve(strings));
                caseCount++;

            }

        } catch (IOException io) {
            io.printStackTrace();
        }
    }
}
