package civitas;
import java.util.ArrayList;

public abstract class Casilla {

    //atributos de clase
    private String nombre;

    Casilla ( String nombre ) {
        this.nombre = nombre;
    }
    
    abstract void recibeJugador (int actual, ArrayList<Jugador> todos) throws Exception;

    boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
        boolean res = false;
        if( actual >= 0 && todos.size() > actual ){
            res = true;
        }
        return res;
    }
    
    void informe(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            Diario.getInstance().ocurreEvento( "Jugador: " +
                     todos.get(actual).getNombre() + "\n " +  this.toString() );
        }
    }
    
    @Override
    public String toString(){
       String result = "Casilla: " + this.nombre;
       return result;
    }

    String get_nombre() {
        return nombre;
    }
    
    public TituloPropiedad getTituloPropiedad(){
        return null;
    }  
}
