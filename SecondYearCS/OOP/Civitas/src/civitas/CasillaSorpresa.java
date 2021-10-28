package civitas;
import java.util.ArrayList;

public class CasillaSorpresa extends Casilla {

    private MazoSorpresa mazo;              // tipo:: SORPRESA
    
    //Tipo Sorpresa
    CasillaSorpresa(MazoSorpresa mazo, String nombre){
        super(nombre);
        this.mazo = mazo;
    }

    @Override 
    void recibeJugador(int actual, ArrayList<Jugador> todos) throws Exception{
        if(this.jugadorCorrecto(actual,todos)){
            this.informe(actual,todos);
            Sorpresa sorpresa = this.mazo.siguiente();
            sorpresa.aplicarAJugador(actual, todos);
        }
    }

    @Override
    public String toString(){
       String result = super.toString();
       return result;
    }
}
