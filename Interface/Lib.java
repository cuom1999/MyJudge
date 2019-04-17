import javax.swing.JFrame;
import javax.swing.ImageIcon;


public class Lib extends JFrame{
	private String curLink = System.getProperty("user.dir");
	public String LINK = curLink.substring(0, curLink.lastIndexOf("\\") + 1);
	public Lib(String s) {
		super(s);
		setIconImage((new ImageIcon("Icon\\GreenTick.png")).getImage());
		
	}
}