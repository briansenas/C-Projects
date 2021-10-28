package civitas;

import java.util.ArrayList;

public class SorpresaSalirCarcel extends Sorpresa{
    
    private MazoSorpresa Mazo;
    
    //se utiliza para evitar la carcel
    SorpresaSalirCarcel(MazoSorpresa mazo, String texto){
        super(texto);
        this.Mazo = mazo;
        Mazo.habilitarCartaEspecial(this);
    }
    
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            informe(actual,todos);
            boolean tieneSC = false;
            for( int i = 0; i < todos.size() && !tieneSC; i++ ){
                if( todos.get(i).tieneSalvoconducto() ){
                    tieneSC = true;
                }
            }
            if( !tieneSC ){
                todos.get(actual).obtenerSalvoConducto(this);
                salirDelMazo();
            }
        }
    }

    void salirDelMazo(){
        this.Mazo.inhabilitarCartaEspecial(this);
    }
    
    void usada(){
        this.Mazo.habilitarCartaEspecial(this);
    }

    @Override
    public String toString(){
       return super.toString();
    }

}