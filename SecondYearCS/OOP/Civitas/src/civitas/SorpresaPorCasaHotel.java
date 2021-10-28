package civitas;

import java.util.ArrayList;

public class SorpresaPorCasaHotel extends Sorpresa{
      
    private float valor;
    
    //Resto de sorpresasa
    SorpresaPorCasaHotel(float valor, String texto){
        super(texto);
        this.valor = valor;
    }
    
    /**
     * @brief Se modifica el saldo del jugador con el valor de la sorpresa multiplicado
     * por el número de casas y hoteles del jugador
     */
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            informe(actual,todos);
            ArrayList<TituloPropiedad> arr = todos.get(actual).getPropiedades();
            int sum = 0;
            for(int i=0;i<arr.size();i++){
                sum += arr.get(i).getNumCasas();
                sum += arr.get(i).getNumHoteles();
            }
            todos.get(actual).modificarSaldo(this.valor * sum);
        }
    }

    @Override
    public String toString(){
       return super.toString() + " valor: " + valor;
    }

}