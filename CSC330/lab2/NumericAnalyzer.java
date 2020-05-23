package edu.cuny.csi.csc330.lab2;
import java.util.Arrays;

public class NumericAnalyzer {
	private String[] set;
	private int[] intSet;
	private int count;
	private int min;
	private int max;
	private int median;
	private int mean;
	private int sum;
	private int range;
	private int variance;
	private int standardDeviation;
	
	public NumericAnalyzer(String[] set) {
		this.set = set;
	}
	
	public String[] getSet() {
		return this.set;
	}
	
	private void setIntSet(int[] intSet) {
		this.intSet = intSet;
	}
	
	public int[] getIntSet() {
		return this.intSet;
	}
	
	private void setCount(int count) {
		this.count = count;
	}
	
	public int getCount() {
		return this.count;
	}
	
	private void setMin(int[] set) {
		Arrays.sort(set);
		this.min = set[0];
	}
	
	private void setMin(int min) {
		this.min = min;
	}
	
	public int getMin() {
		return this.min;
	}
	
	private void setMax(int[] set) {
		Arrays.sort(set);
		this.max = set[set.length-1];
	}
	
	private void setMax(int max) {
		this.max = max;
	}
	
	public int getMax() {
		return this.max;
	}
	
	private void setMedian(int median) {
		this.median = median;
	}
	
	private void setMedian(int[] set) {
		Arrays.sort(set);
		this.median = set[set.length/2];
	}
	
	public int getMedian() {
		return this.median;
	}
	
	private void setMean(int mean) {
		this.mean = mean;
	}
	
	public int getMean() {
		return this.mean;
	}
	
	private void setSum(int sum) {
		this.sum = sum;
	}
	
	public int getSum() {
		return this.sum;
	}
	
	private void setRange(int min, int max) {
		this.range = max - min;
	}
	
	private void setRange(int range) {
		this.range = range;
	}
	
	public int getRange() {
		return this.range;
	}
	 
	private void setVariance(int variance) {
		this.variance = variance;
	}
	
	public int getVariance() {
		return this.variance;
	}
	
	private void setStandardDeviation(int standardDeviation) {
		this.standardDeviation = standardDeviation;
	}
	
	public int getStandardDeviation() {
		return this.standardDeviation;
	}
	
	private int[] castToInt(String[] set) {
		int setLength = set.length;
		int[] setInt = new int[setLength];

		try {
			for(int i = 0; i < setLength; i ++) {
				setInt[i] = Integer.parseInt(set[i]);
			}
		} catch(NumberFormatException e) {
			System.out.println("Expecting Numerical Data " + e.getMessage());
			System.exit(2);
		}
		
		return setInt;
	}
	
	private int calcSum() {
		int sum = 0;
		
		for(int n : this.getIntSet()) {
			sum += n;
		}
		
		return sum;
	}
	
	private int calcMean() {
		return this.getSum() / this.getCount();
	}
	
	private int calcVariance() {
		int mean = this.getMean();
		int[] set = this.getIntSet();
		int len = this.getCount();
		
		int variance = 0;
		
		for(int n : set) {
			variance += (int) Math.pow(mean - n, 2);
		}
		
		variance /= len;
		
		return variance;
	}
	
	private int calcStandardDeviation() {
		return (int) Math.sqrt(this.getVariance());
	}
	
	private void analyze() {
		// Initialize All Members and Perform Calculations & Error Handling
		
		// Set the Integer Set
		this.setIntSet(this.castToInt(this.getSet()));
		
		// Set the Count
		this.setCount(this.getIntSet().length);
		
		// Set the Minimum
		this.setMin(this.getIntSet());
		
		// Set the Maximum
		this.setMax(this.getIntSet());
		
		// Set the Range
		this.setRange(this.getMin(), this.getMax());
		
		// Set the Sum
		this.setSum(this.calcSum());
		
		// Set the Mean
		this.setMean(this.calcMean());
		
		// Set the Median
		this.setMedian(this.getIntSet());
		
		// Set the Variance
		this.setVariance(this.calcVariance());
		
		// Set the Standard Deviation
		this.setStandardDeviation(this.calcStandardDeviation());
	}
	
	public void display() {	
		String formatString = "%,d";
		
		final Object[][] rows = new String[9][];
		rows[0] = new String[] {"Count:", String.format(formatString,this.getCount())};
		rows[1] = new String[] {"Min:", String.format(formatString,this.getMin())};
		rows[2] = new String[] {"Max:", String.format(formatString,this.getMax())};
		rows[3] = new String[] {"Range:", String.format(formatString,this.getRange())};
		rows[4] = new String[] {"Sum:", String.format(formatString,this.getSum())};
		rows[5] = new String[] {"Mean:", String.format(formatString,this.getMean())};
		rows[6] = new String[] {"Median:", String.format(formatString,this.getMedian())};
		rows[7] = new String[] {"Variance:", String.format(formatString,this.getVariance())};
		rows[8] = new String[] {"Deviation:", String.format(formatString,this.getStandardDeviation())};
		
		System.out.printf("%s\n",Arrays.toString(this.getIntSet()).replace(",", " ").replace("[", "").replace("]", ""));
		for(final Object[] row : rows) {
			System.out.printf("%-20s%10s\n", row);
		}
	}
	
	
	public static void main(String[] args) throws IllegalArgumentException {
		if(args.length == 0) {
			throw new IllegalArgumentException("Pass in 1 or more positive integer number values.");
		}
		
		NumericAnalyzer analyzer = new NumericAnalyzer(args);
		analyzer.analyze();
		analyzer.display();
	}
}
