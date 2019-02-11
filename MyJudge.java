import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MyJudge extends JFrame{
	Desktop desktop = Desktop.getDesktop();
	public static String Link;
	public String optionList[]={"SoFile", "Float", "Checker"};
	JLabel testNum = new JLabel("Number of Test: ");
	JTextField testNumInput = new JTextField("",8);
	JLabel timeLimit =new JLabel("Time Limit: ");
	JTextField timeLimitInput = new JTextField("",8);
	JLabel error = new JLabel("Error: ");
	JTextField errorInput = new JTextField("",8);
	JButton change = new JButton("Activate Changes!");
	JComboBox option = new JComboBox(optionList);


	JButton button1 = new JButton("Open Generator");
	JButton button2 = new JButton("Run Generator");
	JButton button3 = new JButton("Compile and Run");
	JButton button4 = new JButton("Run");
	JButton button5 = new JButton("Input");
	JButton button6 = new JButton("Output");
	JButton button7 = new JButton("Answer");
	JButton button8 = new JButton("Sample Input");

	ButtonAction buttonAction = new ButtonAction();
	JTextArea submission = new JTextArea("Submission here!",26,60);
	JTextArea solution = new JTextArea("Solution here!",26,60);
	JTextField announce = new JTextField("Hello!!!",30);
	JScrollPane scroll1 = new JScrollPane(submission);
	JScrollPane scroll2 = new JScrollPane(solution);

	JOptionPane showResult = new JOptionPane();
	FlowLayout fl = new FlowLayout();
	String res;
	File report = new File (Link+"Chambai\\report.txt");
	
	public MyJudge(){
		super("MyJudge");
		
		setLayout(fl);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setExtendedState(JFrame.MAXIMIZED_BOTH);
		setLocationRelativeTo(null);
		createTop();
		createTextArea();
		createButton();
		createAnnounce();

		setVisible(true);
	}


	public void createTop(){
		try{
			File fileTestNum = new File (Link+"Data\\Number_Of_Test.txt");
			File fileTimeLimit = new File(Link+"Data\\TimeLimit.txt");
			File fileError = new File(Link+"Data\\Error.txt");
			testNumInput.setText(new Scanner(fileTestNum).next());
			timeLimitInput.setText(new Scanner(fileTimeLimit).next());
			errorInput.setText(new Scanner(fileError).next());
		}
		catch(Exception e){

		}
		change.addActionListener(buttonAction);
		option.setEditable(false);
		add(testNum);
		add(testNumInput);
		add(timeLimit);
		add(timeLimitInput);
		add(error);
		add(errorInput);
		add(change);
		add(option);
	}

	public void createTextArea(){
		submission.setTabSize(2);
		solution.setTabSize(2);
		submission.setLineWrap(true);
		submission.setWrapStyleWord(true);
		submission.setFont(new Font("Consolas", Font.PLAIN, 14));

		solution.setLineWrap(true);
		solution.setWrapStyleWord(true);
		solution.setFont(new Font("Consolas", Font.PLAIN, 14));

		add(scroll1);
		add(scroll2);
	}

	public void createButton(){
		button1.addActionListener(buttonAction);
		button2.addActionListener(buttonAction);
		button3.addActionListener(buttonAction);
		button4.addActionListener(buttonAction);
		button5.addActionListener(buttonAction);
		button6.addActionListener(buttonAction);
		button7.addActionListener(buttonAction);
		button8.addActionListener(buttonAction);
		
		add(button1);
		add(button2);
		add(button8);
		add(button3);
		add(button4);
		add(button5);
		add(button6);
		add(button7);
		//add(button2);
	}

	public void createAnnounce(){
		announce.setEditable(false);
		announce.setFont(new Font("monospace",Font.ITALIC,18));
		announce.setHorizontalAlignment(JTextField.CENTER);
		add(announce);
	}

	public class ButtonAction implements ActionListener {
		public void actionPerformed (ActionEvent e){
			if (e.getSource()==button1){
				try {			
					desktop.open(new File(Link+"Generator\\Generator.cpp"));
					announce.setText("Open Generator successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to Open Generator!");
				}
			}
			if (e.getSource()==button2){
				try {			
					desktop.open(new File(Link+"Generator\\Generator.exe"));
					announce.setText("Run Generator successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to Run Generator!");
				}
			} 
			if (e.getSource()==button3){
				String sub = submission.getText();
				String sol = solution.getText();
				try{
					Formatter copySub = new Formatter(Link+"Submission\\main.cpp");
					Formatter copySol = new Formatter(Link+"Solution\\main.cpp");
					copySub.format("%s",sub);
					copySol.format("%s",sol);		
					copySub.close();
					copySol.close();			
					announce.setText("Copy successfully!!!");
				}
				catch (Exception eee) {
					announce.setText("Fail to Copy Texts!!!");
				}
				int w=option.getSelectedIndex();
				if (w==0){ //So file
					try{
						desktop.open(new File(Link+"ChamBai\\SoFile.exe"));
						announce.setText("Compile and Run successfully!!!");
					}
					catch(Exception eeee){
						announce.setText("Fail to run SoFile.exe!!!");
					}
				}
				else if (w==1) { //Float
					try{
						desktop.open(new File(Link+"ChamBai\\Float.exe"));
						announce.setText("Compile and Run successfully!!!");
					}
					catch(Exception eeee){
						announce.setText("Fail to run Float.exe!!!");
					}
				}
				else if (w == 2) { //Checker
					try{
						desktop.open(new File(Link+"ChamBai\\Checker\\Checker.exe"));
						announce.setText("Compile and Run successfully!!!");
					}
					catch(Exception eeee){
						announce.setText("Fail to run Checker.exe!!!");
					}
				}
			}
			if (e.getSource()==button4){
				try{
					desktop.open(new File(Link+"ChamBai\\SoFile_Compiled\\SoFile.exe"));
					announce.setText("Run successfully!!!");
				}
				catch(Exception eeee){
					announce.setText("Fail to run SoFile_Compiled.exe!!!");
				}
			}
			if (e.getSource()==button5){
				try{
					desktop.open(new File(Link+"ChamBai\\ExportFile\\input.txt"));
					
					announce.setText("Open Input Test successfully!!!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Input Test!");
				}
			}
			if (e.getSource()==button6){
				try{			
					desktop.open(new File(Link+"ChamBai\\ExportFile\\output.txt"));
					announce.setText("Open Output successfully!!!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Output!!!");
				}
			}
			if (e.getSource()==button7){
				try{			
					desktop.open(new File(Link+"ChamBai\\ExportFile\\ans.txt"));
					announce.setText("Open Answer successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Answer!!!");
				}
			}
			if (e.getSource()==button8){
				try{			
					desktop.open(new File(Link+"TestCases\\test1.txt"));
					announce.setText("Open Sample successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Sample!!!");
				}
			}
			if (e.getSource()==change){
				try{
					Formatter f = new Formatter(Link+"Data\\Number_Of_Test.txt");
					f.format("%s",testNumInput.getText());
					f.close();
					f= new Formatter(Link+"Data\\TimeLimit.txt");
					f.format("%s",timeLimitInput.getText());
					f.close();
					f=new Formatter(Link+"Data\\Error.txt");
					f.format("%s",errorInput.getText());
					f.close();
					announce.setText("Activated changes!!!");
				}
				catch(Exception ee){
					announce.setText("Fail to activate changes!!!");
				}
			}
		}
	}

	private static void getLink(){
		try {
			File pathLink= new File("D:\\Path\\Path.txt");
			Scanner getLink = new Scanner(pathLink);
			Link=getLink.next();
		}
		catch (Exception e) {
			System.out.println("Wrong Link!");
		}
	}
	
	
	
	public static void main(String[] args){
		getLink();
		MyJudge app= new MyJudge();
	}
}