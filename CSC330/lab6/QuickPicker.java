package edu.cuny.csi.csc330.lab6;

import java.util.PropertyResourceBundle;
import java.util.ResourceBundle;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.MissingResourceException;

import edu.cuny.csi.csc330.util.Randomizer;

public class QuickPicker {
	public final static int DEFAULT_GAME_COUNT = 1; 
	private final static ArrayList<String> ENFORCED_PROPERTIES = new ArrayList(Arrays.asList("GameName", "Pool1", "Pool2", "Vendor"));
	
	private String propertyFile;
	private String gameName;
	private String vendorName;
	private ArrayList<Pool> pools;

	private ArrayList<LottoQuickPickerGame> gamesData = new ArrayList<LottoQuickPickerGame>();

	public QuickPicker(String propertyFile) throws QuickPickerException {
		init(propertyFile, DEFAULT_GAME_COUNT); 
	}

	public QuickPicker(String propertyFile, int games) throws QuickPickerException {
		init(propertyFile, games); 
	}
	
	private void init(String propertyFile, int games) throws QuickPickerException { // Add throws statement
		this.propertyFile = propertyFile;
		try {
			ResourceBundle env = ResourceBundle.getBundle(propertyFile);
			
			if(this.keysPresent(env)) {
				this.gameName = env.getString("GameName");
				this.vendorName = env.getString("Vendor");
				ArrayList<String> p = new ArrayList<String>();
				p.add(env.getString("Pool1"));
				p.add(env.getString("Pool2"));
				this.pools = this.digestPools(p);
			}else {
				throw new QuickPickerException("Can't Find Required Property", QuickPickerException.INVALID_PROPERTY);
			}
					
			for(int i = 1; i <= games; i++) {
				LottoQuickPickerGame g = new LottoQuickPickerGame(i, pools);
				
				this.gamesData.add(g);
			}
		}catch(MissingResourceException e) {
			throw new QuickPickerException("Can't Find: " + this.propertyFile, QuickPickerException.MISSING_PROPERTIES_FILE);
		}catch(QuickPickerException e) {
			
		}
	}
	
	private boolean keysPresent(ResourceBundle env) {
		for(String key : ENFORCED_PROPERTIES) {
			if(!env.containsKey(key)) {
				return false;
			}
		}
		return true;
	}
	
	private ArrayList<Pool> digestPools(ArrayList<String> pools) {
		ArrayList<Pool> p = new ArrayList<Pool>();
		
		for(String pool : pools) {
			int selectionCount = Integer.parseInt(pool.split(("/"))[0]);
			int selectionSize = Integer.parseInt(pool.split(("/"))[1]);
			p.add(new Pool(selectionCount, selectionSize));
		}
		
		return p;
	}

	public void displayTicket() {
		displayHeading(); 
		
		for(LottoQuickPickerGame game : this.gamesData) {
			System.out.println(game.toString());
		}
			
		displayFooter(); 
		
		return;
	}

	protected void displayHeading() {
	 System.out.printf("%1$s%2$s%3$s%4$s%5$s", "---------------------------------\r\n" + 
	 		"------------ ", this.gameName ,"------------\r\n" + 
	 		"", new Date(), "\r\n\r\n");
		
	}

	protected void displayFooter() {
		System.out.printf("%1$s%2$,d%3$s%4$s%5$s","\r\n\r\nOdds of Winning: 1 in ", this.calculateOdds(),"\r\n----- (c) ", this.vendorName, "-----\r\n" + 
				"---------------------------------\r\n" + 
				""); 
	}


	private long calculateOdds() {
		long odds = 1;

		for(Pool pool : this.pools) {
			if(pool.selectionCount != 0) {
				for(int i = 0; i < pool.selectionCount; i++) {
					odds = odds * (pool.selectionSize-i)/(i+1);
				}
			}
		}

		return odds;
	}


	public static void main(String[] args) throws QuickPickerException {
		int numberOfGames  = DEFAULT_GAME_COUNT; 
		String propertyFile = "";
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the name of the game you would like to play.");
		
		propertyFile = sc.nextLine();
		
		System.out.println("How many games would you like to play? (Default: 1)");
		
		try {
			numberOfGames = Integer.parseInt(sc.nextLine());
		} catch(NumberFormatException e) {
			Logger logger = Logger.getLogger(QuickPicker.class.getName());
			logger.setLevel(Level.INFO);
			logger.info("Invalid or No Input, Number of Games Set to 1 by Default.");
		}
		
		QuickPicker lotto = new QuickPicker(propertyFile,numberOfGames);
		 
		lotto.displayTicket(); 
	}

}

class Pool {
	protected int selectionCount;
	protected int selectionSize;
	
	public Pool(int selectionCount, int selectionSize) {
		this.selectionSize = selectionSize;
		this.selectionCount = selectionCount;
	}
}

class LottoQuickPickerGame {
	private final int gameNumber;
	
	private ArrayList<Pool> pools;
	private ArrayList<String> selectedNumbers;
	private Map<String,Object> attributes = new HashMap<String,Object>();

	public LottoQuickPickerGame(final int gameNumber, ArrayList<Pool> pools) {
		this.gameNumber = gameNumber;
		this.pools = pools;
		this.selectedNumbers = this.generateNumbers(pools);
		this.setAttributes();
	}
	
	private ArrayList<String> generateNumbers(ArrayList<Pool> pools) {
		TreeSet<Integer> sortedNumbers = new TreeSet<Integer>();
		ArrayList<String> selectedNumbers = new ArrayList<String>();
		int totalSize = 0;
		for(Pool pool : pools) {
			totalSize += pool.selectionCount;
			
			while(sortedNumbers.size() < totalSize) {
				sortedNumbers.add(Randomizer.generateInt(1,pool.selectionSize));
			}
		}
		
		for(Integer n : sortedNumbers) {
			selectedNumbers.add(String.format("%02d", n));
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





