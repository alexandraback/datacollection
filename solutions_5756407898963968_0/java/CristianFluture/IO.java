import java.io.*;
import java.util.ArrayList;

/**
 * Created by Cristi on 4/12/2014.
 */
public class IO {

    public static ArrayList<String> readFile(String path) {
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(path));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String line = null;
        ArrayList<String> result = new ArrayList<String>();
        try {
            while ((line = reader.readLine()) != null) {
                result.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result;
    }

    public static void writeFile(String path, ArrayList<String> content) {
        FileWriter f0 = null;
        String newLine = System.getProperty("line.separator");

        try {
            f0 = new FileWriter(path);
            for (int i = 0; i < content.size(); i++) {
                f0.write(content.get(i) + newLine);
            }
            f0.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
