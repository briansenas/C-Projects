package civitas;

import java.util.ArrayList;

public class SorpresaPagarCobrar extends Sorpresa{
      
    private float valor;
    
  
    //Resto de sorpresasa
    SorpresaPagarCobrar(float valor, String texto){
        super(texto);
        this.valor = valor;
    }
  
    /**
     * @brief Se informa y se modifica el saldo del jugador actual con el valor de la sorpresa
     */
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            informe(actual,todos);
            todos.get(actual).modificarSaldo(this.valor);
        }
    }


    @Override
    public String toString(){
       return super.toString() + " valor: " + valor;
    }

}