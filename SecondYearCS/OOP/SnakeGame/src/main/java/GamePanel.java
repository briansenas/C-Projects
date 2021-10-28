/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author brian
 */
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.Random;


import javax.swing.JPanel;
public final class GamePanel extends JPanel implements Runnable,KeyListener {
    
    private static final long serialVersionID = 1L;
    
    public static final int WIDTH = 500, HEIGHT = 500, TILESIZE = 10;
    
    private Thread thread;
   
    private boolean running; 
    private boolean right = true, left = false, down = false, up = false;
    
    private BodyPart b;
    private ArrayList<BodyPart> snake;
    
    private Apple apple;
    private ArrayList<Apple> apples;
    
    private Random r;
    
    private int xCoor=10, yCoor = 10, size = 300,SPEED = 320000;
    private int ticks = 0;
    
    public GamePanel(){
        setFocusable(true);   
        
        setPreferredSize(new Dimension(WIDTH,HEIGHT));
        addKeyListener(this);
        
        snake = new ArrayList<BodyPart>();
        apples = new ArrayList<Apple>();
        
        r = new Random();
        
        start();
    }
    
    public void start(){
        running = true;
        thread = new Thread(this);
        thread.start();
    }
    
    public void stop(){
        running = false;
        try{
            thread.join();
        } catch (InterruptedException e){
            //Do something
        }
        
    }
    
    public void tick(){
        if(snake.isEmpty()){
            b = new BodyPart(xCoor, yCoor, TILESIZE);
            snake.add(b);
        }
        ticks++;
        if(ticks > SPEED){
            if(right) xCoor++;
            if(left) xCoor--;
            if(up) yCoor--;
            if(down) yCoor++;
            
            if(xCoor > WIDTH/TILESIZE - 2){
                xCoor = 0;
            }
            if(xCoor < 0){
                xCoor = WIDTH/TILESIZE-1;
            }
            
            if(yCoor > HEIGHT/TILESIZE-2){
                yCoor = 0;
            }
            if(yCoor < 0){
                yCoor = HEIGHT/TILESIZE - 1 ;
            }
            ticks = 0;
            b = new BodyPart(xCoor, yCoor, TILESIZE);
            snake.add(b);
            
  
            
            if(snake.size()> size){
                snake.remove(0);
            }
            if(snake.size()>200){
                SPEED -= 3000;
            }
            if(snake.size()>300){
                SPEED -= 2000;
            }
            
        }
        if(apples.isEmpty()){
            int x = r.nextInt(WIDTH/TILESIZE - 1);
            int y = r.nextInt(HEIGHT/TILESIZE - 1);
            
            apple = new Apple(x, y, TILESIZE);
            apples.add(apple);
        }
        for(int i=0;i<apples.size();i++){
            if(xCoor == apples.get(i).getxCoor() && yCoor == apples.get(i).getyCoor()){
                size++;
                apples.remove(i);
                i++;
            }
        } 
        for(int i=0; i<snake.size();i++){
            if(xCoor == snake.get(i).getxCoor() && yCoor == snake.get(i).getyCoor()){
                if(i != snake.size()-1)
                    stop();
            }
        }
    }
    @Override
    public void paint(Graphics g){
        g.clearRect(0,0,WIDTH,HEIGHT);
        
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, WIDTH, HEIGHT);
        
        
        for(int i=0; i<WIDTH/TILESIZE; i++){
            g.drawLine(i*TILESIZE,0,i*TILESIZE,HEIGHT);
        }
        for(int i=0; i<HEIGHT/10; i++){
            g.drawLine(0,i*TILESIZE,HEIGHT,i*TILESIZE);
        }
        for(int i=0;i<snake.size();i++){
            snake.get(i).draw(g);
        }
        for(int i = 0; i<apples.size(); i++){
            apples.get(i).draw(g);
        }
    }
    
    @Override
    public void run(){
        while(running){
            tick();
            repaint();
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();
        if(key == KeyEvent.VK_RIGHT && !left){
            right = true;
            up = false;
            down = false;
        }
        if(key == KeyEvent.VK_LEFT && !right){
            left = true;
            up = false;
            down = false;
        }
        if(key == KeyEvent.VK_UP && !down){
            up = true;
            right = false;
            left = false;
        }
        if(key == KeyEvent.VK_DOWN && !up){
            down = true;
            right = false;
            left = false;
        }
        
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
