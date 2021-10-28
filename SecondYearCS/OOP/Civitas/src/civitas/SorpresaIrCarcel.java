package civitas;

import java.util.ArrayList;

public class SorpresaIrCarcel extends Sorpresa{
    
    private Tablero tablero;     
    private int valor; 
    

    //se utiliza para mover a una casilla
    SorpresaIrCarcel(Tablero tablero, String texto){
        super(texto);
        this.tablero = tablero;
        this.valor = tablero.getCarcel();
    }
    
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            if(todos.get(actual).encarcelar(this.valor)) //O tablero.getCarcel()
            this.informe(actual,todos);
        }
    }

    @Override
    public String toString(){
       return super.toString() + " casilla: " + valor;
    }

}