/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author brian
 */
import javax.swing.JFrame;

public class Main {
    
    public Main(){
        JFrame frame = new JFrame();
        GamePanel gamepanel = new GamePanel();
        
        frame.add(gamepanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("Object Oriented Programing");
        
        frame.pack();
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
    }
    
    public static void main(String[] args){
        new Main();
    }
}
