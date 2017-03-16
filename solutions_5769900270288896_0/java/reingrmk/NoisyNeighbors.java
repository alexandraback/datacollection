import java.io.*;
import java.nio.channels.FileChannel;
import java.util.Date;

/**
 * Date: 02/05/2015
 * Time: 19:02
 */

public class NoisyNeighbors {

    public static void main(String[] args) throws IOException {
        new NoisyNeighbors().doSomething();
    }

    void doSomething() throws IOException {
        try {
            File test = new File(System.getProperty("user.home") + System.getProperty("file.separator") + "Downloads").getAbsoluteFile();
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

            File fsrc = new File("src" + System.getProperty("file.separator") + "NoisyNeighbors.java");
            File fsrcCopy = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "NoisyNeighbors.java");
            if (fsrcCopy.exists()) {
                fsrcCopy.delete();
            }
            fsrcCopy.createNewFile();
            FileChannel fsrcChannel = new FileInputStream(fsrc).getChannel();
            FileChannel fsrcCopyChannel = new FileOutputStream(fsrcCopy).getChannel();
            fsrcCopyChannel.transferFrom(fsrcChannel, 0, fsrcChannel.size());
            fsrcChannel.close();
            fsrcCopyChannel.close();

            File fOut = new File(test.getAbsolutePath() + System.getProperty("file.separator") + "NoisyNeighbors.out");
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
        String[] s = in.readLine().split(" ");
        int r = Integer.valueOf(s[0]);
        int c = Integer.valueOf(s[1]);
        int n = Integer.valueOf(s[2]);
        int rc = r * c;
        int noise = 0;

        n = n - (rc + 1) / 2;
        if (n <= 0) {
            return "0";
        }

        int cornerPlaces = (rc % 2 == 0) ? 2 : 0;
        int edgePlaces = (r / 2 + c / 2) * 2 - cornerPlaces * 2;
        if (r % 2 != c % 2) {
            edgePlaces = edgePlaces + 1;
        }

        if (r == 1 || c == 1) {
            if (rc % 2 == 0) {
                n = n - 1;
                noise = noise + 1;
            }
            cornerPlaces = (rc - 1) / 2;
        }


        if (n <= cornerPlaces) {
            return Integer.toString(2 * n + noise);
        } else {
            noise = 2 * cornerPlaces;
            n = n - cornerPlaces;
        }

        if (n < edgePlaces) {
            noise = noise + 3 * n;
            if (rc % 3 == 0) {
                if (Math.max(r, c) == n) {
                    noise = noise - 1;
                }
            }
            return Integer.toString(noise);
        } else {
            noise = noise + 3 * edgePlaces;
            n = n - edgePlaces;
        }

        noise = noise + n * 4;

        return Integer.toString(noise);
    }

}
