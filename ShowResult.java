import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ShowResult extends JFrame{
	static String LINK;
	File report = new File (LINK + "Chambai\\report.txt");
	String s;
	String res;
	JOptionPane showResult = new JOptionPane();

	public ShowResult(){
		super();
		try{
			res = new Scanner(report).useDelimiter("\\A").next();
		}
		catch(Exception e){}

		char st = res.charAt(0);
		if (st == 'A'){
			String s = "<html><font color=#4de80d font-weight=bold size=20> " + res;
			showResult.showMessageDialog(null, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\GreenTick.png"));
		}
		else if (st == 'C'){
			String s = "<html><font color=#fef201 font-weight=bold size=20> " + res;
			showResult.showMessageDialog(this, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\Warning.png"));
		}
		else if (st == 'T' && res.charAt(1)=='I'){
			String s = "<html><font color=#498cd3 font-weight=bold size=20> " + res;
			showResult.showMessageDialog(this, s, "Result",JOptionPane.INFORMATION_MESSAGE,processIcon("Icon\\Clock.png"));
		}
		else{
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


	private static void getLink(){
		try {
			File pathLink = new File("D:\\Path\\Path.txt");
			Scanner getLink = new Scanner(pathLink);
			LINK = getLink.next();
		}
		catch (Exception e) {
			System.out.println("Wrong Link!");
		}
	}

	public static void main(String[] args){
		getLink();
		ShowResult dialog = new ShowResult();
		System.exit(0);
	}


}