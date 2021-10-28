package civitas;

import java.util.ArrayList;

public class SorpresaPorJugador extends Sorpresa{
     
    private float valor; 
    
    
    //Resto de sorpresasa
    SorpresaPorJugador(float valor, String texto){
        super(texto);
        this.valor = valor;
    }
    
    /**
     * @brief Todos los jugadores dan dinero al jugador actual
     */
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            informe(actual,todos);
            for(int i=0;i<todos.size();i++){
                if(i==actual)
                    todos.get(i).modificarSaldo(valor*(-1)* (todos.size()-1) );
                else
                    todos.get(i).modificarSaldo(valor);
            }
        }
    }

    @Override
    public String toString(){
       return super.toString() + " valor: " + valor;
    }

}