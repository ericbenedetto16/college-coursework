/**
 * Partially completed Direction ENUM 
 */

package edu.cuny.csi.csc330.lab5;

import edu.cuny.csi.csc330.util.Randomizer;
import java.util.HashMap;

// Add values for the change in the ave/street
public enum Direction {
	 NONE(0,0), NORTH(0,1), EAST(-1,0), SOUTH(0,-1), WEST(1,0), NORTHEAST(-1,1), NORTHWEST(1,1), SOUTHWEST(1,-1), SOUTHEAST(-1,-1);
	
	private HashMap<String, Integer> changes = new HashMap<String, Integer>();
	 private Direction(int avenueChange, int streetChange) {
		 this.changes.put("avenue", avenueChange);
		 this.changes.put("street", streetChange);
	 }
	 
	 public Direction getFavorite() {
		 return SOUTH;  // It's getting cold! ... 
	 }
	 
	 public Direction getNextRandom() {
			int direction = Randomizer.generateInt(1, 8); 
			
			switch(direction) {
			case 1:
				return SOUTH;
			case 2:
				return WEST;
			case 3:
				return NORTH;
			case 4:
				return EAST;
			case 5:
				return NORTHEAST;
			case 6:
				return NORTHWEST;
			case 7:
				return SOUTHWEST;
			default:
				return SOUTHEAST;
			}
	 }
	 
	 public HashMap<String, Integer> getChanges() {
		 return this.changes;
	 }
	 
	 public static void main(String [] args)  {
		 
		 int c = 0; 
		 while(c++ < 100) {  
			 System.out.println(Direction.NONE.getNextRandom() );
		 }
		 
	 }
	 
	 
}
