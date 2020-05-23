/**
 * LAB 3 -  Lotto QuickPicker Game 
 */
package edu.cuny.csi.csc330.lab3;

import java.util.*;

import edu.cuny.csi.csc330.util.Randomizer;

public class LottoQuickPicker {
	
	// constants  specific to current game - BUT NOT ALL GAMES 
	public final static int DEFAULT_GAME_COUNT = 3; 
	private final static String GAME_NAME = "Lotto";
	
	// Change from private to protected to allow LottoQuickPickerGame access
	protected final static int SELECTION_POOL_SIZE = 59; 
	protected final static int SELECTION_COUNT = 6;

	// Initialize Object that stores game num (key) and array ints (values)
	private ArrayList<LottoQuickPickerGame> gamesData = new ArrayList<LottoQuickPickerGame>();

	public LottoQuickPicker() {
		init(DEFAULT_GAME_COUNT); 
	}
	
	public LottoQuickPicker(int games) {
		init(games); 
	}
  
	private void init(int games) {
		// For the amount of games in games
		for(int i = 1; i <= games; i++) {
			LottoQuickPickerGame g = new LottoQuickPickerGame(i);
			
			// Add game data to an ArrayList
			this.gamesData.add(g);
		}		
	}


	/**
	 * 
	 */
	public void displayTicket() {
		// display ticket heading 
		displayHeading(); 
		
		// display selected numbers
		for(LottoQuickPickerGame game : this.gamesData) {
			System.out.println(game.toString());
		}
			
		// display ticket footer 
		displayFooter(); 
		
		return;
	}
	
	protected void displayHeading() {
	 System.out.printf("%1$s%2$30s%3$s", "---------------------------------\r\n" + 
	 		"------------  LOTTO ------------\r\n" + 
	 		"", new Date(), "\r\n\r\n");
		
	}
	
	protected void displayFooter() {
		System.out.printf("%1$s%2$,d%3$s","\r\n\r\nOdds of Winning: 1 in ", this.calculateOdds(),"\r\n----- (c) S.I. Corner Deli -----\r\n" + 
				"---------------------------------\r\n" + 
				""); 
	}
	
	
	/**
	 * 
	 * @return
	 */
	private long calculateOdds() {
		long odds = 1;
		for(int i = 0; i < SELECTION_COUNT; i++) {
			odds = odds * (SELECTION_POOL_SIZE-i)/(i+1);
		}

		return odds;
	}
  

	/**
	 * @param args 
	 */
	public static void main(String[] args) {
		// takes an optional command line parameter specifying number of QP games to be generated
		//  By default, generate 1  
		int numberOfGames  = DEFAULT_GAME_COUNT; 
		
		if(args.length > 0) {  // if user provided an arg, assume it to be a game count
			numberOfGames = Integer.parseInt(args[0]);  // [0] is the 1st element!
		}
		
		LottoQuickPicker lotto = new LottoQuickPicker(numberOfGames);
		 
		lotto.displayTicket(); 
		
		// COMMENT THIS OUT WHEN YOU'RE DONE ... 
		// System.out.println("Leaving ...");

	}

}


class LottoQuickPickerGame {
	private final int gameNumber;
	private ArrayList<String> selectedNumbers;
	private Map<String,Object> attributes = new HashMap<String,Object>();
	
	public LottoQuickPickerGame(final int gameNumber) {
		this.gameNumber = gameNumber;
		this.selectedNumbers = this.generateNumbers(LottoQuickPicker.SELECTION_POOL_SIZE, LottoQuickPicker.SELECTION_COUNT);
		this.setAttributes();
	}
	
	public LottoQuickPickerGame(final int gameNumber, int selectionSize, int selectionCount) {
		this.gameNumber = gameNumber;
		this.selectedNumbers = this.generateNumbers(selectionSize, selectionCount);
	}
	
	private void setSelectedNumbers(ArrayList<String> selectedNumbers) {
		this.selectedNumbers = selectedNumbers;
	}
	
	private ArrayList<String> generateNumbers(int selectionSize, int selectionCount) {
		ArrayList<String> selectedNumbers = new ArrayList<String>(); 
		for(int i = 0; i < selectionCount; i++) {
			selectedNumbers.add(String.format("%02d", Randomizer.generateInt(1, selectionSize)));
		}
		
		return selectedNumbers;
	}
	
	public int getGameNumber() {
		return this.gameNumber;
	}
	
	public ArrayList<String> getSelectedNumbers() {
		return this.selectedNumbers;
	}
	
	private void setAttributes() {
		this.attributes.put("id",this.gameNumber);
		this.attributes.put("numbers",this.selectedNumbers);
	}

	public Map<String,Object> getAttributes() {
		return this.attributes;
	}
	
	public String toString() {
		return String.format("(%1$s)  %2$s", this.getAttributes().get("id"), this.getAttributes().get("numbers").toString().replace("[","").replace("]","").replace(",",""));
	}
}
