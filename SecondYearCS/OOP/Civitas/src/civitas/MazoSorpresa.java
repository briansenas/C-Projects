package civitas;
import java.util.ArrayList;
import java.util.Collections;
        
public class MazoSorpresa {
    
    private boolean barajada;
    private boolean debug;
    private Sorpresa ultimaSorpresa;
    private int usadas;

    private ArrayList<Sorpresa> sorpresas;
    private ArrayList<Sorpresa> cartasEspeciales; 
    // La variable cartasEspeciales almacenará la carta sorpresa del tipo SALIRCARCEL 
    // mientras se considere retirada del mazo (y por tanto en posesión de un jugador). 
    // Se ha definido como una colección para poderle dar más funcionalidad al juego
    
    //Inicializar varias variables privadas
    //para no repetir código en los diferentes constructores
    final void init(){
        this.barajada = false;
        this.usadas = 0;
        this.sorpresas = new ArrayList<>();
        this.cartasEspeciales = new ArrayList<>();
    }
    
    //Constructor sin parámetros
    MazoSorpresa(){
        this.debug = false;
        this.init();
    }
    
    //Constructor con parámetros para this.debug = d
    MazoSorpresa(boolean d){
        this.debug = d;
        this.init();
        if( debug ){
            Diario.getInstance().ocurreEvento("Debug");
        }
    }
    
    /**
     * @brief Si el mazo no ha sido barajado añadimos la nueva sorpresa.
     * @param s nueva sorpresa a añadir
     */
    void alMazo(Sorpresa s){
        if(!this.barajada){
            this.sorpresas.add(s);
        }
    }
    
    /**
     * @brief En caso de haber utilizado todas cartas, o no haberlas barajadas,
     * debemos entonces barajar las cartas utilizando @b Collections.shuffle();
     * @return ultimaSorpresa.
     */
    Sorpresa siguiente(){
        if((!this.barajada || this.usadas==this.sorpresas.size() )&& !this.debug){
            Collections.shuffle(sorpresas);
            this.usadas = 0;
            this.barajada = true;
        }
        this.usadas++;
        this.ultimaSorpresa = this.sorpresas.get(0);//Al quitar una carta
        this.sorpresas.add(this.ultimaSorpresa); //La añadimos al final de la pila
        this.sorpresas.remove(0);
        
        return ultimaSorpresa;       
    }    
    
    /**
     * @brief Si @b this.sorpresas posee el parámetro, entonces lo retiramos y
     * lo añadimos a las @b cartasEspeciales
     * @param sorpresa carta a quitar del mazo
     */
    void inhabilitarCartaEspecial(Sorpresa sorpresa){
        if (this.sorpresas.contains(sorpresa)){
            this.cartasEspeciales.add(sorpresa);
            this.sorpresas.remove(this.sorpresas.indexOf(sorpresa));
            Diario.getInstance().ocurreEvento("InhabilitarEspecial");
        }
    }
    
    /**
     * @brief Exactamente la inversa de inhabilitarCartaEspecial()
     * @param sorpresa 
     */
    void habilitarCartaEspecial(Sorpresa sorpresa){
        if (this.cartasEspeciales.contains(sorpresa)){
            this.sorpresas.add(sorpresa);
            this.cartasEspeciales.remove(this.cartasEspeciales.indexOf(sorpresa));
            Diario.getInstance().ocurreEvento("HabilitarEspecial");
        }
    }
}
