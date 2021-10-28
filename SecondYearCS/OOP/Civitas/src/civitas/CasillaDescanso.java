package civitas;
import java.util.ArrayList;

public class CasillaDescanso extends Casilla {

    CasillaDescanso ( String nombre ) {
        super(nombre);
    }
    
    @Override
    void recibeJugador (int actual, ArrayList<Jugador> todos){
        informe(actual,todos);
    };

    @Override
    public String toString(){
       String result = super.toString();
       return result;
    }

}
