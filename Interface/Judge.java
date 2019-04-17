import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowListener;
import java.awt.event.WindowEvent;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SwingWorker;
import javax.swing.text.DefaultCaret;

public class Judge extends Lib{
	
	JTextArea textArea 	   = new JTextArea(26, 60);
	JScrollPane scrollPane = new JScrollPane(textArea);
	DefaultCaret caret     = (DefaultCaret) textArea.getCaret();
	ProcessBuilder pb;
	Process p;

	
	public Judge(String fileDir) {
		super("Judging");
		caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);
		
		addWindowListener( new WindowAdapter() {
		    public void windowClosing(WindowEvent e) {
				p.destroy();		 
	            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		    }
		});
		 
		Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
		setSize(600, 400);

        // Determine the new location of the window
		int w = getSize().width;
		int h = getSize().height;
		int x = (dim.width - w) / 2;
		int y = (dim.height - h) / 2;

        // Move the window
		setLocation(x, y);

		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		textArea.setFont(new Font("Consolas", Font.PLAIN, 14));
		textArea.setEditable(false);

		add(scrollPane);
		
		setVisible(true);

		
		SwingWorker sw = new SwingWorker() {
			
			protected String doInBackground() throws Exception {  
				
				String drive = fileDir.substring(0, 2);
				
				pb = new ProcessBuilder("cmd.exe","/c","start","cmd");

				pb = pb.directory(new File(drive));
				pb.command(fileDir);
				pb.redirectErrorStream(true);

				p = pb.start();
					

				BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
				
				String line;
				while ((line = br.readLine()) != null) {
					publish(line);
				}
				
				return "Done";
			}
			
			protected void process(List chunk) {
				for (int i = 0; i < chunk.size(); i++) {
					textArea.append((String) chunk.get(i) + "\n");
				}
			}

			protected void done() {
				ShowResult sr = new ShowResult();
				setVisible(false);
			}
		};
		sw.execute();
	}

	public static void main(String[] args) {
		Judge j = new Judge("D:\\DINH\\MyJudge\\ChamBai\\SoFile_Compiled.exe");
	}
}