package civitas;

import java.util.ArrayList;

public class SorpresaIrCasilla extends Sorpresa{
    
    private Tablero tablero;     
    private int valor;
   

    //se utiliza para mover a una casilla
    SorpresaIrCasilla(Tablero tablero, int valor, String text){
        super(text);
        this.tablero = tablero;
        this.valor = valor;
    }

    /**
     * @param actual indice del jugador actual
     * @param todos array con todos los jugadores.
     * @throws java.lang.Exception
     * @brief Se mueve al jugador a una nueva casilla
     */
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos) throws Exception{
        if( this.jugadorCorrecto(actual, todos) ){
            informe(actual,todos);
            Jugador jugadorActual = todos.get(actual);
            int tirada = this.tablero.calcularTirada( jugadorActual.getNumCasillaActual(), this.valor );
            int nueva_pos = this.tablero.nuevaPosicion( jugadorActual.getNumCasillaActual(), tirada );
            jugadorActual.moverACasilla(nueva_pos);
            this.tablero.getCasilla(nueva_pos).recibeJugador(actual, todos);
        }else{
            throw new Exception("AplicarAJugador: out of boundaries");
        }
    }

    
    @Override
    public String toString(){
        return super.toString() + " casilla: " + valor;
    }
}