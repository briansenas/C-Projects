package civitas;

import java.util.ArrayList;

public abstract class Sorpresa{
    
    private String texto; 
  
    Sorpresa(String texto){
        this.texto = texto;
    }
    
    /**
     * @brief Comprueba si el primer parámetro es un índice válido para acceder a los elementos del segundo parámetro
     * @return si lo es o no
     */
    public boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
        boolean result = false;
        if( actual >= 0 && actual < todos.size() ){
            result = true;
        }
        return result;
    }
    
    /**
     * @brief Informa al diario que se está aplicando una sorpresa a un jugador
     */
    public void informe(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            Diario.getInstance().ocurreEvento( "Aplicando Sorpresa a " + todos.get(actual).getNombre() );
        }
        
    }
    
    /**
     * @brief Llama a distintas funciones dependiendo del valor del 
     * tipo de atributo sorpresa del que se trate.
     */
    abstract void aplicarAJugador(int actual, ArrayList<Jugador>todos) throws Exception;
    
    
    @Override
    public String toString(){
       return "Sorpresa: " + this.texto +  " ";
    }

}