import java.util.PriorityQueue;

public class Barber implements Comparable<Barber> {
	private final int duration; //how long this barber takes to cut hair.
	private final int index;
	private int timeLeft = 0; //how long left til this barber has done cutting the current head of hair.
	
	public Barber(int index, int duration) {
		this.index = index;
		this.duration = duration;
	}
	
	/**
	 * Assigns a new customer to this barber.
	 * Updates the state so that the barber has 'just started'.
	 */
	public void assign() {
		if (timeLeft != 0) throw new IllegalStateException("Barber is already busy.");
		timeLeft = duration;
	}
	
	/**
	 * Models the given amount of time elapsing.
	 * @param time time units to model passing.
	 */
	public void elapseTime(int time) {
		timeLeft -= time;
		if (timeLeft < 0) {
			timeLeft = 0; //should not be required in my use.
			System.err.println("Barber elapsed more time than necessary.");
		}
	}
	
	/**
	 * Gets the amount of time left for this barber to cut the current customer's hair.
	 * @return timeLeft.
	 */
	public int getTimeLeft() {
		return timeLeft;
	}
	
	/**
	 * Getter for index.
	 * @return index.
	 */
	public int getIndex() {
		return index;
	}

	@Override
	public int compareTo(Barber o) {
		int timeDifference = getTimeLeft() - o.getTimeLeft();
		if (timeDifference == 0) return index - o.index;
		else return timeDifference;
	}
	
	@Override
	public String toString() {
		return timeLeft + "/" + duration + " (" + index + ")";
	}
	
	public static void main(String[] args) {
		PriorityQueue<Barber> barbers = new PriorityQueue<Barber>();
		Barber barber1 = new Barber(0, 6);
		Barber barber2 = new Barber(1, 5);
		barber1.assign();
		barber2.assign();
		barbers.add(barber1);
		barbers.add(barber2);
		System.out.println(barbers);
	}
}