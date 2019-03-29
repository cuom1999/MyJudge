import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MyJudge extends Lib{
	private Desktop desktop = Desktop.getDesktop();
	
	public String optionList[] = {"SoFile", "Float", "Checker"};

	JLabel testNum   		  = new JLabel("Number of Test: ");
	JTextField testNumInput   = new JTextField("", 8);
	JLabel timeLimit 		  = new JLabel("Time Limit: ");
	JTextField timeLimitInput = new JTextField("", 8);
	JLabel error 			  = new JLabel("Error: ");
	JTextField errorInput 	  = new JTextField("", 8);
	JButton change 			  = new JButton("Activate Changes!");
	JButton useAvailable	  = new JButton("Use Available Files");
	JComboBox<String> option  = new JComboBox<String>(optionList);


	JButton button1 = new JButton("Open Generator");
	JButton button2 = new JButton("Run Generator");
	JButton button3 = new JButton("Compile and Run");
	JButton button4 = new JButton("Open Stats");
	JButton button5 = new JButton("Input");
	JButton button6 = new JButton("Output");
	JButton button7 = new JButton("Answer");
	JButton button8 = new JButton("Sample Input");

	ButtonAction buttonAction = new ButtonAction();
	JTextArea submission 	  = new JTextArea("Submission here!",26,60);
	JTextArea solution 		  = new JTextArea("Solution here!",26,60);
	JTextField announce 	  = new JTextField("Hello!!!",30);
	JScrollPane scroll1 	  = new JScrollPane(submission);
	JScrollPane scroll2 	  = new JScrollPane(solution);
	JOptionPane showResult    = new JOptionPane();
	
	FlowLayout fl 			  = new FlowLayout();
	
	String res;
	File report = new File (LINK + "Chambai\\report.txt");
	
	public MyJudge(){
		super("My Judge");
		
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
			File fileTestNum   = new File(LINK + "Data\\Number_Of_Tests.txt");
			File fileTimeLimit = new File(LINK + "Data\\TimeLimit.txt");
			File fileError     = new File(LINK + "Data\\Error.txt");
			
			testNumInput.setText(new Scanner(fileTestNum).next());
			timeLimitInput.setText(new Scanner(fileTimeLimit).next());
			errorInput.setText(new Scanner(fileError).next());
		}
		catch(Exception e){
		}

		change.addActionListener(buttonAction);
		useAvailable.addActionListener(buttonAction);
		option.setEditable(false);

		add(testNum);
		add(testNumInput);
		add(timeLimit);
		add(timeLimitInput);
		add(error);
		add(errorInput);
		add(change);
		add(useAvailable);
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
	}

	public void createAnnounce(){
		announce.setEditable(false);
		announce.setFont(new Font("monospace",Font.ITALIC,18));
		announce.setHorizontalAlignment(JTextField.CENTER);
		add(announce);
	}

	public class ButtonAction implements ActionListener {
		public void actionPerformed (ActionEvent e){
			if (e.getSource() == button1){
				try {			
					desktop.open(new File(LINK + "Generator\\Generator.cpp"));
					announce.setText("Open Generator successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to Open Generator!");
				}
			}
			if (e.getSource() == button2){
				try {			
					desktop.open(new File(LINK + "Generator\\Generator.exe"));
					announce.setText("Run Generator successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to Run Generator!");
				}
			} 
			if (e.getSource() == button3){
				
				String sub = submission.getText();
				String sol = solution.getText();

				boolean areCompiled = false;

				try {
					String oldSub = new Scanner(new File(LINK + "Submission\\main.cpp")).useDelimiter("^_^").next();
					String oldSol = new Scanner(new File(LINK + "Solution\\main.cpp")).useDelimiter("^_^").next();
					
					if (sub.equals(oldSub) && sol.equals(oldSol)) {
						areCompiled = true;
					}
				}
				catch(Exception e1) {
					announce.setText("Something wrong with sub or sol folder");
				}

				// Check the last compilation first (CE or not)
				try {
					int resLog = new Scanner(new File(LINK + "ChamBai\\resultLog.txt")).nextInt();
					areCompiled &= (resLog != 3);
				}
				catch (Exception e2){}

				
				if (areCompiled == false) {
					// copy text
					try {
						Formatter copySub = new Formatter(LINK + "Submission\\main.cpp");
						Formatter copySol = new Formatter(LINK + "Solution\\main.cpp");
						copySub.format("%s", sub);
						copySol.format("%s", sol);		
						copySub.close();
						copySol.close();			
						announce.setText("Copy successfully!!!");
					}
					catch(Exception ee) {
						announce.setText("Fail to copy!");
					}
				}				

				int opt = option.getSelectedIndex();

				// run judge

				String judgeFile = "";

				if (opt == 0){ //So file
					if (areCompiled == false) judgeFile = "SoFile.exe";
					else {
						judgeFile = "SoFile_Compiled.exe";
					}
				}

				else if (opt == 1) { //Float
					if (areCompiled == false) judgeFile = "Float.exe";
					else {
						judgeFile = "Float_Compiled.exe";
					}
				}

				else if (opt == 2) { //Checker
					if (areCompiled == false) judgeFile = "Checker.exe";
					else {
						judgeFile = "Checker_Compiled.exe";
					}
				}

				String fileDir = LINK + "ChamBai\\" + judgeFile;
				// call Judge.java
				System.out.println(fileDir);

				Judge judgeUI = new Judge(fileDir);
			}
			if (e.getSource() == button4){
				try{
					desktop.open(new File(LINK + "ChamBai\\stats.csv"));
					announce.setText("Open stats.csv successfully!!!");
				}
				catch(Exception eeee){
					announce.setText("Fail to open checker!!!");
				}
			}
			if (e.getSource() == button5){
				try{
					desktop.open(new File(LINK+"ChamBai\\ExportFile\\input.txt"));
					
					announce.setText("Open Input Test successfully!!!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Input Test!");
				}
			}
			if (e.getSource() == button6){
				try{			
					desktop.open(new File(LINK+"ChamBai\\ExportFile\\output.txt"));
					announce.setText("Open Output successfully!!!");
				}

				catch(Exception ee){
					announce.setText("Fail to open Output!!!");
				}
			}
			if (e.getSource() == button7){
				try{			
					desktop.open(new File(LINK+"ChamBai\\ExportFile\\ans.txt"));
					announce.setText("Open Answer successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Answer!!!");
				}
			}
			if (e.getSource() == button8){
				try{			
					desktop.open(new File(LINK+"TestCases\\test1.txt"));
					announce.setText("Open Sample successfully!");
				}
				catch(Exception ee){
					announce.setText("Fail to open Sample!!!");
				}
			}
			if (e.getSource() == change) {
				try{
					Formatter f = new Formatter(LINK + "Data\\Number_Of_Tests.txt");
					f.format("%s",testNumInput.getText());
					f.close();
					f = new Formatter(LINK + "Data\\TimeLimit.txt");
					f.format("%s",timeLimitInput.getText());
					f.close();
					f = new Formatter(LINK + "Data\\Error.txt");
					f.format("%s",errorInput.getText());
					f.close();
					announce.setText("Activated changes!!!");
				}
				catch(Exception ee){
					announce.setText("Fail to activate changes!!!");
				}
			}
			if (e.getSource() == useAvailable) {
				try{
					File fileSub   = new File(LINK + "Submission\\main.cpp");
					File fileSol   = new File(LINK + "Solution\\main.cpp");

					submission.setText(new Scanner(fileSub).useDelimiter("^_^").next());
					solution.setText(new Scanner(fileSol).useDelimiter("^_^").next());

					announce.setText("Copy successfully!!!");
				}
				catch (Exception eee) {
					announce.setText("Fail to Copy Texts!!!");
				}
			}
		}
	}

	public static void main(String[] args) {
		MyJudge app = new MyJudge();
	}

}