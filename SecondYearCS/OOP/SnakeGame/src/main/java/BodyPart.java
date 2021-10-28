/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author brian
 */
import java.awt.Color;
import java.awt.Graphics;

public class BodyPart {
    
    private int xCoor, yCoor, width, height;
    
    public BodyPart(int xCoor, int yCoor, int tileSize){
        this.xCoor = xCoor;
        this.yCoor = yCoor;
        width = tileSize;
        height = tileSize;
    }
    
    public void tick(){
        
    }
    public void draw(Graphics g){
        g.setColor(Color.YELLOW);
        g.fillRect(xCoor*width, yCoor*height, width, height);
    }

    public int getxCoor() {
        return xCoor;
    }

    public int getyCoor() {
        return yCoor;
    }

    public void setxCoor(int xCoor) {
        this.xCoor = xCoor;
    }

    public void setyCoor(int yCoor) {
        this.yCoor = yCoor;
    }
    
}
