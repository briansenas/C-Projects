package fantasmaarcade;
  
import java.util.ArrayList;
import java.util.EnumSet;

enum Colores{
    ROJO,
    NEGRO,
    VERDE,
    AZUL,
    AMARILLO,
    ROSA,
    NARANJA
}

public class Fantasma {
        
    private int x,y;
    private final int speed = 10;
    private Colores color;
    private EnumSet<Colores> colors = EnumSet.allOf(Colores.class);
    
    
    Fantasma(){
        x = 0;
        y = 0;
    }
    
    Fantasma(int x,int y,Colores color){
        this.x = x;
        this.y = y;
        if( CanUseColor(color) )
            this.color = color;
    }
    
    public boolean CanUseColor(Colores color){
        boolean result = false;
        if (colors.contains(color)){
            result = true;
            colors.remove(color);
        }
        return result;
    }
    
    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public Colores getColor() {
        return color;
    }

    public void setColor(Colores color) {
        if(this.CanUseColor(color))
            this.color = color;
    }
    
}
