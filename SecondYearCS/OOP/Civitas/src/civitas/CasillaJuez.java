package civitas;
import java.util.ArrayList;

public class CasillaJuez extends Casilla {


    private int carcel;

    //Tipo Juez
    CasillaJuez(int numCasillaCarcel, String nombre){
        super(nombre);
        this.carcel = numCasillaCarcel;
    }
   
    @Override
    void recibeJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            this.informe(actual,todos);
            todos.get(actual).encarcelar(this.carcel);
        }
    }
    @Override
    public String toString(){
       String result = super.toString() + " en la casilla: " + carcel;
       return result;
    }

}
