import java.util.ArrayList;

/**
 * Created by Cristi on 4/12/2014.
 */
public class Magic {
    public Magic() {

    }

    public ArrayList<String> process(ArrayList<String> input) {
        ArrayList<String> result = new ArrayList<String>();
        int size = Integer.parseInt(input.get(0));
        int row = 0;
        int[] line1 = new int[4];
        int[] line2 = new int[4];
        for (int i = 0; i < size; i++) {
            row = Integer.parseInt(input.get(i * 10 + 1));
            String s = input.get(i * 10 + 1 + row);
            String[] split = s.split(" ");
            for (int j = 0; j < 4; j++) {
                line1[j] = Integer.parseInt(split[j]);
            }
            row = Integer.parseInt(input.get(i * 10 + 6));
            s = input.get(i * 10 + 6 + row);
            split = s.split(" ");
            for (int j = 0; j < 4; j++) {
                line2[j] = Integer.parseInt(split[j]);
            }
            result.add(processSet(i + 1, line1, line2));
        }
        return result;
    }

    public String processSet(int nr, int[] line1, int[] line2) {
        int[] pos = new int[4];
        int val = -1;
        int count = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (line1[i] == line2[j]){
                    val = line1[i];
                    count++;
                }
            }
        }
        if (count == 0){
            return "Case #" + nr + ": Volunteer cheated!";
        }
        if (count == 1){
            return "Case #" + nr + ": " + val;
        }
        if (count > 1){
            return "Case #" + nr + ": Bad magician!";
        }
        return null;
    }
}
