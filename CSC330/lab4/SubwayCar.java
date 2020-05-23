package edu.cuny.csi.csc330.lab4;

import java.util.*;

enum Direction {
	N, S, E, W;
}

public class SubwayCar {
	private final String manufacturer;
	private final Date manufacturedDate;
	private final String modelNumber;
	private final String serialNumber;
	private Date lastMaintanence = null;
	private boolean running = false;
	private Line line = null;
	private Direction direction = null;
	private ArrayList<String> stops = null;
	private int stopIndex = -1;
	private String nextStop = null;
	private Map<String,Double> currentLocation = null;
	private Map<String,Double> lastKnownLocation = null;

	enum Line {
		ONE("1", new ArrayList<String>(Arrays.asList("Stop 1", "Stop 2", "Stop 3")), Direction.N ),
		TWO("2", new ArrayList<String>(Arrays.asList("Stop 1", "Stop 2", "Stop 3", "Stop 4")), Direction.S);
		
	    private String alias;
	    private ArrayList<String> stops;
	    private ArrayList<String> inverseStops;
	    private Direction defaultDirection;
	    
	    private Line(String alias, ArrayList<String> stops, Direction defaultDirection) {
	        this.alias = alias;
	        this.stops = stops;
	        this.defaultDirection = defaultDirection;
	        this.inverseStops = initInverseStops();
	    }
	    
	    public String getAlias() {
	        return this.alias; 
	    }

	    public ArrayList<String> initInverseStops() {
	    	ArrayList<String> inverseStops = (ArrayList<String>) this.stops.clone();
	    	Collections.reverse(inverseStops);
	    	
	    	return inverseStops;
	    }
	    
	    public ArrayList<String> getStops(Direction direction) {
	    	return direction == this.defaultDirection ? this.stops : this.inverseStops;
	    }
	}

	/*
	 *  Constructor for new car. Manufactured/Maintenance is when instantiated b
	 *  because it is assumed to be right off of the assembly line.
	 */
	public SubwayCar(String manufacturer, String modelNumber, String serialNumber) {
		this.manufacturer = manufacturer;
		this.manufacturedDate = new Date();
		this.modelNumber = modelNumber;
		this.serialNumber = serialNumber;
		this.lastMaintanence = this.manufacturedDate;
	}

	/*
	 * Constructor for Used Car. May have been bought from another company so
	 * the manufactured and maintenance dates are initialized from input.
	 */
	public SubwayCar(String manufacturer, Date manufacturedDate, String modelNumber, String serialNumber, Date lastMaintenance) {
		this.manufacturer = manufacturer;
		this.manufacturedDate = manufacturedDate;
		this.modelNumber = modelNumber;
		this.serialNumber = serialNumber;
		this.lastMaintanence = lastMaintenance;
	}
	
	public void updateMaintenance(Date lastMaintenance) {
		this.lastMaintanence = lastMaintenance;
	}
	
	
	// Running on new line in different direction
	public void updateRoute(Line line, Direction direction) {
		if(this.running) this.running = false;
		
		this.initialize(line, direction, this.currentLocation);
	}
	
	// Running in same direction on new line
	public void updateRoute(Line line) {
		if(this.running) this.running = false;
		
		this.initialize(line, this.direction, this.currentLocation);
	}
	
	// Running on same line in new direction
	public void updateRoute(Direction direction) {
		if(this.running) this.running = false;

		this.initialize(this.line, direction, this.currentLocation);
	}
	
	// Set the next stop ordinally
	public void nextStop() {
		this.stopIndex++;
		this.nextStop = this.stops.get(this.stopIndex);
	}
	
	// Set the next stop manually
	public void nextStop(int index) {
		this.stopIndex = index;
		this.nextStop = this.stops.get(this.stopIndex);
	}
	
	// Update the location
	public void updateLocation(Map<String,Double> currentLocation) {
		this.currentLocation = currentLocation;
		this.lastKnownLocation = currentLocation;
	}
	
	public void updateLocation(double lat, double lng) {
		Map<String, Double> currentLocation = new HashMap<String,Double>();
		currentLocation.put("lat", lat);
		currentLocation.put("lng", lng);
		this.updateLocation(currentLocation);
	}
	
	// Start a train
	public void initialize(Line line, Direction direction, Map<String,Double> currentLocation) {
		this.running = true;
		this.line = line;
		this.direction = direction;
		this.stops = line.getStops(direction);
		this.stopIndex = 0;
		this.nextStop = this.stops.get(stopIndex);
		this.updateLocation(currentLocation);
	}
	
	// Turn a train off
	public void deinitialize() {
		this.running = false;
		this.line = null;
		this.direction = null;
		this.stops = null;
		this.stopIndex = -1;
		this.nextStop = null;
		this.lastKnownLocation = this.currentLocation;
		this.currentLocation = null;
	}
	
	// Miscellaneous Getters and Setters
	public String getManufacturer() {
		return this.manufacturer;
	}
	
	public Date getManufacturedDate() {
		return this.manufacturedDate;
	}
	
	public String getModelNumber() {
		return this.modelNumber;
	}
	
	public String getSerialNumber() {
		return this.serialNumber;
	}
	
	public Date getLastMaintenance() {
		return this.lastMaintanence;
	}
	
	public boolean isRunning() {
		return this.running;
	}
	
	public Line getLine() {
		return this.line;
	}
	
	public Direction getDirection() {
		return this.direction;
	}
	
	public ArrayList<String> getStops() {
		return this.stops;
	}
	
	public Map<String,Double> getCurrentLocation() {
		return this.currentLocation;
	}
	
	public Map<String,Double> getLastKnownLocation() {
		return this.lastKnownLocation;
	}
	
	public String toString() {
		return "Manufacturer: " + this.manufacturer + ", Manufactured Date: " + this.manufacturedDate + 
				",\nModel Number: " + this.modelNumber + ", Serial Number: " + this.serialNumber +
				",\nLast Maintenance Date: " + this.lastMaintanence + ", Running: " + this.running + ", Line: " + 
				(Objects.isNull(this.line) ? this.line : this.line.getAlias()) +
				",\nDirection: " + this.direction + ", Stops: " + this.stops + ", Next Stop: " + this.nextStop +
				", Stop Index: " + (this.stopIndex == -1 ? null : (this.stopIndex + 1)) + ",\nCurrent Location: " + 
				this.currentLocation + ", Last Known Location: " + this.lastKnownLocation;
	}
	
	public static void main(String[] args) {
		SubwayCar oneTrain = new SubwayCar("JetTech", "1ZAF394B-4B", "1QAD39CA9C0290CAJ3019CN1XX933JA");
		
		System.out.println("New Instance");
		System.out.println(oneTrain.toString());
		System.out.println("\n");
		
		Map<String, Double> currentLocation =  new HashMap<String,Double>();
		currentLocation.put("lat", 42.312982); 
		currentLocation.put("lng", -74.102932);
		
		oneTrain.initialize(Line.ONE, Direction.S, currentLocation);
		System.out.println("Train Started");
		System.out.println(oneTrain.toString());
		System.out.println("\n");
		
		oneTrain.nextStop();
		System.out.println("At Next Stop");
		System.out.println(oneTrain.toString());
		System.out.println("\n");
		
		oneTrain.updateRoute(Direction.N);
		System.out.println("Switched Train Direction");
		System.out.println(oneTrain.toString());
		System.out.println("\n");
		
		oneTrain.deinitialize();
		System.out.println("Train Off");
		System.out.println(oneTrain.toString());
		System.out.println("\n");
	}

}
