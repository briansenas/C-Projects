package civitas;
import java.util.ArrayList;

public class CasillaImpuesto extends Casilla {

    private float importe;
    //Tipo Impuesto
    CasillaImpuesto(float cantidad, String nombre){
        super(nombre);
        this.importe = cantidad;
    }
    
    @Override
    void recibeJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            this.informe(actual,todos);
            todos.get(actual).pagaImpuesto(this.importe);
        }
    }

    @Override
    public String toString(){
       String result = super.toString();
       return result;
    } 
}
