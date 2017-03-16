package codejam1A;

public class Triple implements Comparable<Triple> {

	private int waitingTime;
	private int unitTime;
	private int barber;


	public Triple(int w, int u, int b) {
		this.waitingTime  = w;
		this.unitTime = u;
		this.barber = b;
	}

	@Override
	public int compareTo(Triple o) {
		if (this.waitingTime > o.waitingTime)
			return 1;
		else if (this.waitingTime < o.waitingTime)
			return -1;
		else{
			if(this.barber > o.barber){
				return 1;
			}
			else if(this.barber < o.barber)
				return -1;
			return 0;
		}

	}

	public void update(){
		this.waitingTime+=this.unitTime;
	}
	public int getBID(){
		return this.barber;
	}
	public int getWTime(){
		return this.waitingTime;
	}
	public int getUTime(){
		return this.unitTime;
	}


}