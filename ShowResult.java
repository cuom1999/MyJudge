import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ShowResult extends JFrame{

	private String LINK = System.getProperty("user.dir") + "\\";
	private File report = new File (LINK + "Chambai\\report.txt");
	private String s;
	private String res;
	
	JOptionPane showResult = new JOptionPane();

	public ShowResult() {

		super();

		try {
			res = new Scanner(report).useDelimiter("\\A").next();
		}
		catch(Exception e){}

		int resLog = new Scanner(new File(LINK + "ChamBai\\resultLog.txt")).nextInt();

		if (resLog == 0) { // AC
			String s = "<html><font color=#4de80d font-weight=bold size=20> " + res;
			showResult.showMessageDialog(null, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\GreenTick.png"));
		}
		else if (resLog == 1) { // WA
			String s = "<html><font color=#fef201 font-weight=bold size=20> " + res;
			showResult.showMessageDialog(this, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\Warning.png"));
		}
		else if (resLog == 2){ // TLE
			String s = "<html><font color=#498cd3 font-weight=bold size=20> " + res;
			showResult.showMessageDialog(this, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\Clock.png"));
		}
		else{ //CE
			String s = "<html><font color=red font-weight=bold size=20>WRONG ANSWER!\n" + res;
			showResult.showMessageDialog(this, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\CE.png"));
		}
	}
	
	public ImageIcon processIcon(String link){
		ImageIcon icon = new ImageIcon(link);
		Image img = icon.getImage();
		Image newimg = img.getScaledInstance(100, 100,  Image.SCALE_SMOOTH);
		ImageIcon newIcon = new ImageIcon(newimg);
		return newIcon;
	}

	public static void main(String[] args) {
		ShowResult app = new ShowResult();
		System.exit(0);
	}
}