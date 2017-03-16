import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class CodeJamB {

    public static final String INPUT = "/opt/dev/TopCoder/src/B-large.in";
    public static final String OUTPUT = "/opt/dev/TopCoder/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
        try {
            solve(br, writer);
        } finally {
            br.close();
            writer.close();
        }
    }

    private static void solve(BufferedReader reader, PrintWriter writer) throws Exception {
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            String[] values = reader.readLine().trim().split(" ");
            int barberCount = Integer.parseInt(values[0]);
            long myPlace = Long.parseLong(values[1]);

            values = reader.readLine().trim().split(" ");
            int[] barberTime = new int[barberCount];
            for (int j = 0; j < barberCount; j++) {
                barberTime[j] = Integer.parseInt(values[j]);
            }

            writer.println("Case #" + (i + 1) + ": " + getResult(barberTime, barberCount, myPlace));
        }
    }

    private static String getResult(int[] barberTime, int barberCount, long myPlace) {
        if (myPlace <= barberCount) {
            return Long.toString(myPlace);
        }

        long[] barberRemain = new long[barberCount];
        long[] safeBarberRemain = new long[barberCount];
        Arrays.fill(barberRemain, 0L);
        for (int i = 0; i < barberCount; i++) {
            safeBarberRemain[i] = barberTime[i];
        }
        long time = 0L;
        long safeClientServed = 0L;
        while (true) {
            long clientServed = 0L;
            time += 1000000;
            for (int i = 0; i < barberCount; i++) {
                clientServed += time / barberTime[i];
                barberRemain[i] = (barberTime[i]) - (time % barberTime[i]);
            }
            if (clientServed + barberCount >= myPlace) {
                break;
            } else {
                safeClientServed = clientServed;
                System.arraycopy(barberRemain, 0, safeBarberRemain, 0, barberCount);
            }
        }
        myPlace -= safeClientServed;

        MinHeap heap = new MinHeap(barberCount);
        for (int i = 0; i < barberCount; i++) {
            heap.add(new Barber(i + 1, safeBarberRemain[i], barberTime[i]));
        }

        myPlace -= barberCount;

        while (true) {
            Barber barber = (Barber) heap.extractMin();
            myPlace--;
            if (myPlace == 0) {
                return Integer.toString(barber.getNumber());
            } else {
                barber.incValue();
                heap.add(barber);
            }
        }
    }

    public static class Barber extends HeapElement {

        private int number;
        private long workTime;
        private long value;

        public Barber(int number, long value, long workTime) {
            this.number = number;
            this.value = value;
            this.workTime = workTime;
        }

        public void setValue(long value) {
            this.value = value;
        }

        public int getNumber() {
            return number;
        }

        public long getValue() {
            return value;
        }

        public void incValue() {
            value += workTime;
        }

        @Override
        public int compareTo(HeapElement o) {
            Barber other = (Barber) o;
            if (value < other.getValue()) {
                return -1;
            } else if (value > other.getValue()) {
                return 1;
            } else {
                if (number < other.getNumber()) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }

    public static abstract class HeapElement implements Comparable<HeapElement> {

        private Integer heapIndex;

        public Integer getHeapIndex() {
            return heapIndex;
        }

        public void setHeapIndex(Integer heapIndex) {
            this.heapIndex = heapIndex;
        }
    }

    public static class MinHeap {

        private HeapElement[] data;
        private int size;

        public MinHeap(int maxCapacity) {
            data = new HeapElement[maxCapacity];
        }

        public void add(HeapElement element) {
            ensureCapacity();
            set(element, size++);
            bubbleUp(size - 1);
        }

        public HeapElement extractMin() {
            HeapElement min = data[0];
            nullPositionIndex(min);
            set(data[--size], 0);
            if (size > 0) {
                bubbleDown(0);
            }
            return min;
        }

        public void delete(HeapElement element) {
            int deleteIndex = element.getHeapIndex();
            if (deleteIndex == (size - 1)) {
                size--;
            } else {
                set(data[--size], deleteIndex);
                if (needToBubbleUp(deleteIndex)) {
                    bubbleUp(deleteIndex);
                } else {
                    bubbleDown(deleteIndex);
                }
            }
            nullPositionIndex(element);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        private void ensureCapacity() {
            if (data.length == size) {
                HeapElement[] newData = new HeapElement[size * 2];
                System.arraycopy(data, 0, newData, 0, size);
                data = newData;
            }
        }

        private void exchange(int first, int second) {
            if (first == second) {
                return;
            }
            HeapElement tmp = data[first];
            data[first] = data[second];
            data[second] = tmp;

            ensurePositionIndex(first);
            ensurePositionIndex(second);
        }

        private void ensurePositionIndex(int index) {
            data[index].setHeapIndex(index);
        }

        private void nullPositionIndex(HeapElement element) {
            element.setHeapIndex(null);
        }

        private void set(HeapElement element, int index) {
            data[index] = element;
            ensurePositionIndex(index);
        }

        private int parent(int index) {
            return (index - 1) / 2;
        }

        private int left(int index) {
            return index * 2 + 1;
        }

        private int right(int index) {
            return index * 2 + 2;
        }

        private void bubbleUp(int index) {
            if (needToBubbleUp(index)) {
                int parent = parent(index);
                exchange(index, parent);
                bubbleUp(parent);
            }
        }

        private boolean needToBubbleUp(int index) {
            if (index == 0) {
                return false;
            }
            int parentIndex = parent(index);
            return data[index].compareTo(data[parentIndex]) < 0;
        }

        private void bubbleDown(int index) {
            int leftIndex = left(index);
            int rightIndex = right(index);

            if (leftIndex >= size) {
                return;
            }

            int candidateIndex;
            if (rightIndex == size || data[leftIndex].compareTo(data[rightIndex]) < 0) {
                candidateIndex = leftIndex;
            }  else {
                candidateIndex = rightIndex;
            }

            if (data[candidateIndex].compareTo(data[index]) < 0) {
                exchange(index, candidateIndex);
                bubbleDown(candidateIndex);
            }
        }
    }
}
