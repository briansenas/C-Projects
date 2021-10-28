import java.util.ArrayList;
import java.util.Date;
public class Plan {
    private String nombre;
    private Date fechaConsecución;
    private int prioridad;
    private int posicionPasoSiguiente = 0;
    private boolean terminado = false;
    private ObjetivoMaligno objetivo;
    private ArrayList<Paso> pasos;
          
    public boolean getTerminado(){
        return terminado;
    }
    public boolean estaActivo(){
        boolean resultado = false;
        if ( posicionPasoSiguiente < pasos.size() && !terminado)
            resultado = true;
        return resultado;
    }
    public void darPasoSiguiente(){
        pasos[posicionPasoSiguiente].setTerminado(true);
        posicionPasoSiguiente++;
        if (posicionPasoSiguiente >= pasos.size())
            posicionPasoSiguiente = 0;
    }
    public int inversionPasoSiguiente(){
        return pasos[posicionPasoSiguiente].getInversion();
    }
}
