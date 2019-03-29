import javax.swing.JFrame;

public class Lib extends JFrame{
	private String curLink = System.getProperty("user.dir");
	public String LINK = curLink.substring(0, curLink.lastIndexOf("\\") + 1);
	public Lib(String s) {
		super(s);
	}
}