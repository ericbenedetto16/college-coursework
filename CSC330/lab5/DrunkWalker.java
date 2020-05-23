package edu.cuny.csi.csc330.lab5;

import java.math.*;
import java.util.*;
import java.util.stream.Collectors;

import edu.cuny.csi.csc330.util.Randomizer;


public class DrunkWalker {
	
	private Intersection startIntersection;
	private Intersection currentIntersection;
	private ArrayList<Intersection> history = new ArrayList<Intersection>();
	private HashMap<Intersection, Integer> count = new HashMap<Intersection, Integer>();

	private DrunkWalker() {
		 init();
	}
	
	public DrunkWalker(int avenue, int street) {
		this.startIntersection = new Intersection(avenue, street);
		this.currentIntersection = new Intersection(avenue, street);
		init();
	}
	
	public HashMap<Intersection,Integer> getCount() {
		return this.count;
	}
	
	private void init() {
		addToHistory();
		count();
	}
	
	public void step() {
		takeAStep();
		addToHistory();
		count();
	}

	public ArrayList<Intersection> getHistory() {
		return this.history;
	}
	

	private void takeAStep() {
		Direction dir = Direction.NONE.getNextRandom();
		this.currentIntersection.adjustIntersection(dir);
	}
	
	private void addToHistory() {
		this.history.add(createIntersectionCopy(this.currentIntersection));
	}

	private void count() {
		Intersection intersection = this.createIntersectionCopy(this.currentIntersection);
		count.computeIfPresent(intersection, (key, val) -> ++val );
		count.computeIfAbsent(intersection, k -> 1);
	}
	
	private Intersection createIntersectionCopy(Intersection intersection) {
		return new Intersection(intersection.getAvenue(), intersection.getStreet());
	}
	
	public String getLocation() {
		return String.format("Current location: DrunkWalker [avenue=%d, street=%d]", 
				currentIntersection.getAvenue(), currentIntersection.getStreet() );
	}

	public void fastForward(int steps ) {
		for(int i = 0; i < steps; i++) {
			step();
		}
	}
	
	public void displayWalkDetails() {
		System.out.printf("Starting Location: %s\nCurrent/Ending Location: %s\nDistance (blocks): %d\nNumber of steps taken: %d\nNumber of unique intersections visited: %d\n\n%s\n",
				this.startIntersection, 
				this.currentIntersection, 
				this.howFar(), 
				this.getNumSteps(), 
				this.count.size(),
				this.getVisitedMoreThanOnceString()
				);

	}
	
	private Map<Intersection, Integer> getVisitedMoreThanOnce() {
		return this.count.entrySet().stream()
		.filter(val -> (val.getValue() > 1))
		.collect(Collectors.toMap(val -> val.getKey(), val -> val.getValue())
		);
	}
	
	public String getVisitedMoreThanOnceString() {
		return this.getVisitedMoreThanOnce().entrySet().stream()
		.map((val) -> String.format("Visited %s %d times!\n",val.getKey(), val.getValue()))
		.collect(Collectors.joining());
	}
	
	public int getNumSteps() {
		return this.count.entrySet().stream()
				.mapToInt(val -> val.getValue())
				.sum() - 1;
	}
	
	public int howFar() {
		int startAvenue = this.startIntersection.getAvenue();
		int avenue = this.currentIntersection.getAvenue();
		int startStreet = this.startIntersection.getStreet();
		int street = this.currentIntersection.getStreet();

		return (Math.abs(startAvenue - avenue) ) + (Math.abs(startStreet - street));
	}

	@Override
	public String toString() {
		return "DrunkWalker [startIntersection=" + startIntersection + ", currentIntersection=" + currentIntersection
				+ ", getNumSteps()=" + getNumSteps() + ", howFar()=" + howFar() + "]";
	}

	public static void main(String[] args) {
		// create Drunkard with initial position (ave,str)
		DrunkWalker billy = new DrunkWalker(6,23);
		final Date startTime = new Date();
		
		for(int i = 1 ; i <= 3 ; ++i ) {
			billy.step();
			System.out.printf("billy's location after %d steps: %s\n",
					i, billy.getLocation() );
		}

		// have him move 25  random intersections
		billy.fastForward(25);
		final Date endTime = new Date();
		
		// get his current location
		String location = billy.getLocation();
		// get distance from start
		int distance = billy.howFar();
		
		System.out.println("Current location after fastForward(): " + location);
		System.out.println("That's " + distance + " blocks from start.");
		
		System.out.printf("\nStart Time: %s\n", startTime);
		System.out.printf("End Time: %s\n", endTime);
		
		billy.displayWalkDetails();
	}

}
