package civitas;

import java.util.ArrayList;

public class SorpresaJugadorEspeculador extends Sorpresa{

    private float valor;
    
    public SorpresaJugadorEspeculador(String texto,float valor) {
        super(texto);
        this.valor = valor;
    }
    
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador>todos){
        if(super.jugadorCorrecto(actual, todos)){
            super.informe(actual, todos);
            JugadorEspeculador newJugador = new JugadorEspeculador(todos.get(actual),valor);
            ArrayList<TituloPropiedad> lista = todos.get(actual).getPropiedades();
            for(int i=0;i<lista.size();i++){
                lista.get(i).actualizaPropietarioPorConversion(newJugador);
            }
            todos.remove(actual);
            todos.add(actual, newJugador);
           
        }
    }
    
}
