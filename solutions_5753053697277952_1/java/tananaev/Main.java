import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Set;
import java.util.HashSet;

public class Main {

    private static class Item {
        int count;
        char letter;
    }

    private static Comparator<Item> comparator = new Comparator<Item>() {
        @Override
        public int compare(Item i1, Item i2) {
            return i2.count - i1.count;
        }
    };

    private static int sum(Item[] items) {
        int count = 0;
        for (int i = 0; i < items.length; i++) {
            count += items[i].count;
        }
        return count;
    }

    public static void solve(int[] data, PrintWriter writer) {
        Item[] items = new Item[data.length];
        for (int i = 0; i < data.length; i++) {
            Item item = new Item();
            item.count = data[i];
            item.letter = (char) ('A' + i);
            items[i] = item;
        }

        Arrays.sort(items, comparator);
        int sum = sum(items);

        while (items[0].count > 0) {
            writer.print(items[0].letter);
            System.out.print(items[0].letter);
            items[0].count -= 1;
            sum -= 1;

            Arrays.sort(items, comparator);
            if ((items[0].count == 1 || (items[0].count - 1) * 2 <= sum - 1) && (items[1].count == 0 || items[1].count * 2 <= sum - 1)) {
                writer.print(items[0].letter);
                System.out.print(items[0].letter);
                items[0].count -= 1;
                sum -= 1;
            }

            writer.print(" ");
            System.out.print(" ");
            Arrays.sort(items, comparator);
        }
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter("output.txt");
            int count = Integer.valueOf(br.readLine());

            for (int ii = 0; ii < count; ii++) {
                br.readLine();
                String[] d1 = br.readLine().split(" ");
                int[] d2 = new int[d1.length];
                for (int i = 0; i < d1.length; i++) {
                    d2[i] = Integer.valueOf(d1[i]);
                }

                String output = "Case #" + (ii+1) + ": ";
                System.out.print(output);
                writer.print(output);
                solve(d2, writer);
                System.out.println("");
                writer.println("");
            }

            br.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }

}
