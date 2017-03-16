package codejam.round1a.b;

public class Barber implements Comparable<Barber> {
    public int id;
    public int speed;
    public int timeLeft;

    public Barber(int id, int speed, int timeLeft) {
        this.id = id;
        this.speed = speed;
        this.timeLeft = timeLeft;
    }

    @Override
    public int compareTo(Barber o) {
        int a = timeLeft - o.timeLeft;

        return a == 0 ? id - o.id : a;
    }
}
