package civitas;
import java.util.ArrayList;

public class TemplateCasilla {

    //atributos de clase
    private String nombre;
    private int carcel;
    private float importe;

    //atributos de referencia
    private TipoCasilla tipo;
    private TituloPropiedad tituloPropiedad; // tipo:: CALLE
    private Sorpresa sorpresa;               // tipo:: SORPRESA
    private MazoSorpresa mazo;              // tipo:: SORPRESA
    
    void init(){
        tipo = null;
        tituloPropiedad = null;
        sorpresa = null;
        mazo = null;
        carcel = -1;
        importe = 0;
    }
    
    TemplateCasilla ( String nombre ) {
        init();
        this.nombre = nombre;
        this.tipo = TipoCasilla.DESCANSO;
    }
    //Tipo Calle
    TemplateCasilla(TituloPropiedad titulo){
        init();
        tipo = TipoCasilla.CALLE;
        this.tituloPropiedad = titulo;    
        this.nombre = titulo.getNombre();
    }
    //Tipo Impuesto
    TemplateCasilla(float cantidad, String nombre){
        init();
        this.importe = cantidad;
        this.nombre = nombre;
        this.tipo = TipoCasilla.IMPUESTO;
    }
    //Tipo Juez
    TemplateCasilla(int numCasillaCarcel, String nombre){
        init();
        this.carcel = numCasillaCarcel;
        this.nombre = nombre;
        this.tipo = TipoCasilla.JUEZ;
    }
    //Tipo Sorpresa
    TemplateCasilla(MazoSorpresa mazo, String nombre){
        init();
        this.nombre = nombre;
        this.mazo = mazo;
        this.tipo = TipoCasilla.SORPRESA;
    }

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
    
    void recibeJugador_impuesto(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            this.informe(actual,todos);
            todos.get(actual).pagaImpuesto(this.importe);
        }
    }

    void recibeJugador_juez(int actual, ArrayList<Jugador> todos){
        if( this.jugadorCorrecto(actual, todos) ){
            this.informe(actual,todos);
            todos.get(actual).encarcelar(this.carcel);
        }
    }
    
    void recibeJugador_calle (int actual, ArrayList<Jugador> todos){
        if(this.jugadorCorrecto(actual,todos)){
            this.informe(actual,todos);
            Jugador jugadorActual = todos.get(actual);
            if(!this.tituloPropiedad.tienePropietario()){
                if(jugadorActual.puedeComprarCasilla())
                    this.tituloPropiedad.tramitarAlquiler(jugadorActual);
            }
        }
    }
    void recibeJugador_sorpresa (int actual, ArrayList<Jugador> todos) throws Exception{
        if(this.jugadorCorrecto(actual,todos)){
            this.informe(actual,todos);
            Sorpresa sorpresa = this.mazo.siguiente();
            sorpresa.aplicarAJugador(actual, todos);
        }
    }
    
    void recibeJugador(int actual, ArrayList<Jugador>todos) throws Exception{
        switch(this.tipo){
            case CALLE:
                recibeJugador_calle(actual,todos);
                break;
            case IMPUESTO:
                recibeJugador_impuesto(actual,todos);
                break;
            case JUEZ:
                recibeJugador_juez(actual,todos);
                break;
            case SORPRESA:
                recibeJugador_sorpresa(actual,todos);
                break;
            default:
                informe(actual,todos);  
                break;
            
        }
    }

    @Override
    public String toString(){
       String result = "Casilla: " + this.nombre;
       if(tituloPropiedad!=null){
           result += "\n 1- precio de compra: " + this.tituloPropiedad.getPrecioCompra()
               + "\n 2- precio de edificación: " + this.tituloPropiedad.getPrecioEdificar()
               + "\n 3- alquiler base: " + this.tituloPropiedad.getAlquilerBase();     
       }
       return result;
    }

    String get_nombre() {
        return nombre;
    }

    public TituloPropiedad getTituloPropiedad(){
        return this.tituloPropiedad;
    }  
}
