package edu.cuny.csi.csc330.lab6;

public class QuickPickerException extends Exception {
	public static int MISSING_PROPERTIES_FILE = 0;
	public static int INVALID_PROPERTY = 1;
	
	public static String[] MESSAGE = {
			"Unknown Game - Can't Locate Specified Game.",
			"Missing Property - Check your Properties File"
	};
	
	protected int code;
	
	private QuickPickerException() { ; }
	
	public QuickPickerException(String msg) {
		super(msg);
	}
	
	public QuickPickerException(String msg, int code) {
		super(msg);
		this.code = code;
	}
	
	public int getCode() {
		return code;
	}

	@Override
	public String toString() {
		return "QuickPickerException [code=" + code + ", toString()=" + super.toString() + "]\n" + MESSAGE[code];
	}
	
	
	
}
