package civitas;
import java.util.ArrayList;

public class CasillaCalle extends Casilla {

   
    private TituloPropiedad tituloPropiedad; // tipo:: CALLE

    //Tipo Calle
    CasillaCalle(TituloPropiedad titulo, String nombre){
        super(nombre);
        this.tituloPropiedad = titulo;    
    }
   
    @Override
    void recibeJugador(int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual,todos)){
            this.informe(actual,todos);
            Jugador jugadorActual = todos.get(actual);
            if(!this.tituloPropiedad.tienePropietario()){
                if(jugadorActual.puedeComprarCasilla())
                    this.tituloPropiedad.tramitarAlquiler(jugadorActual);
            }
        }
    }
    
    @Override
    public String toString(){
       String result = super.toString();
       result += "\n 1- precio de compra: " + this.tituloPropiedad.getPrecioCompra()
               + "\n 2- precio de edificación: " + this.tituloPropiedad.getPrecioEdificar()
               + "\n 3- alquiler base: " + this.tituloPropiedad.getAlquilerBase();     
       return result;
    }

    public TituloPropiedad getTituloPropiedad(){
        return this.tituloPropiedad;
    }  
}
