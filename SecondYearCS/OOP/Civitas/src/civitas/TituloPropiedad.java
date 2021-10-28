package civitas;

public class TituloPropiedad {
    
    private String nombre;
    private float alquilerBase, hipotecaBase, factorRevalorizacion,
               precioCompra, precioEdificar;
    private static final float factorInteresesHipoteca = 1.1f;
    private Jugador Propietario;
    private int numCasas;
    private int numHoteles;
    private boolean hipotecado;
            
    //Constructor con parámetros para inicializar todas las variables.
    TituloPropiedad(String nom,float ab, float fr, float hb,
                    float pc, float pe){
        this.nombre = nom;
        alquilerBase = ab;
        factorRevalorizacion = fr;
        hipotecaBase = hb;
        precioCompra = pc;
        precioEdificar = pe;
        hipotecado = false;
        Propietario = null;
        numCasas = 0;
        numHoteles = 0;
        
    }
    
    /**
     * @brief SobreCarga del operador toString para devolver el estado la clase
     * @return Tipo String
     */
    @Override
    public String toString(){
       String result = "\n\tEl nombre de la propiedad es " + this.nombre
            + "\n\tHipotecaBase: "+ this.hipotecaBase + " €.\n\tEl factor de valorizacion es " + 
            this.factorRevalorizacion + "\n 1- precio de compra: " + precioCompra
               + "\n 2- precio de edificación: " + precioEdificar
               + "\n 3- alquiler base: " + alquilerBase;
       
       return result;
    }


    /**
    * @brief Si el propietario no está encarcelado y no hipotecado, calculamos
    * el precio del alquiler con la fórmula del juego
    * @see Jugador.isEncarcelado()
    * @return valor a pagar.
    */
    public float getPrecioAlquiler(){
        float result = 0;
        if ( !this.propietarioEncarcelado() && !hipotecado )
            result = (float) (this.alquilerBase*(1+(numCasas*0.5)+(numHoteles*2.5)));
        return result;
    }
    
    /**
     * @brief Calculamos el importe de cancelar la hipoteca con la fórmula del 
     * juego y auxiliandonos del otro método de la clase. Devuelve el importe 
     * que se obtiene al hipotecar el título multiplicado por factorInteresesHipoteca
     * @see getImporteHipoteca()
     * @return precio a pagar.
     */
    float getImporteCancelarHipoteca(){
        return (float) ((float)this.getImporteHipoteca()*factorInteresesHipoteca);
    }

    /**
     * @brief Si @b this.Propietario no es igual al jugador ( parámetro ) entonces
     * debemos tramitar el alquiler a pagar
     * @see Jugador.pagaAlquiler(), getPrecioAlquiler()
     * @param jugador 
     */
    void tramitarAlquiler(Jugador jugador){
        if(this.tienePropietario()){
            if (!esEsteElPropietario(jugador)){
                jugador.pagaAlquiler(this.getPrecioAlquiler());
                this.Propietario.recibe(this.getPrecioAlquiler());
            }
        }
    }

    /**
     * @brief verificamos si el propietario esta encarcelado
     * @see Jugador.isEncarcelado
     * @return 
     */
    private boolean propietarioEncarcelado(){
        boolean result = false;
        if(this.Propietario != null){
            if(this.Propietario.isEncarcelado() )
                result = true;
        }
        return result;
    }

    /**
     * @brief Calculamos la suma del nº de casas y hoteles de la propiedad
     * @return El nº total de casas y hoteles
     */
    int cantidadCasasHoteles(){
        return numCasas+numHoteles;
    }  

    /**
     * @brief Aplicamos la fórmula del juego para Obtener el precio de venta.
     * @return precio a pagar
     */
    private float getPrecioVenta(){
        return (precioCompra+(numCasas+5*numHoteles)
                *precioEdificar*factorRevalorizacion);
    }

    /**
     * @brief Si podemos, destruimos n casas que poseemos
     * @param n número de casas a derruir
     * @param jugador propietario de las casas
     * @return succeso / error
     */
    boolean derruirCasas(int n, Jugador jugador){
        boolean result = false;
        if (esEsteElPropietario(jugador) && numCasas >= n){
            numCasas -= n;
            result = true;
        }
        return result;
    }

    /**
     * @brief vendemos nuestra propiedad
     * @param jugador el propietario
     * @return succeso / error
     */
    boolean vender(Jugador jugador){
        boolean result = false;
        if(esEsteElPropietario(jugador) && !hipotecado){
            jugador.recibe(this.getPrecioVenta());
            this.Propietario = null;
            this.numCasas = 0;
            this.numHoteles = 0;
            result = true;
        }
        return result;
    }

    /**
     * @brief Si somos el propietario y estamos hipotecado entonces este recibe 
     * el imoprte de cancelar la hipoteca.
     * @see getImporteCancelarHipoteca(), Jugador.paga()+
     * @param jugador
     * @return 
     */
    boolean cancelarHipoteca(Jugador jugador){
         boolean result = false;
        if(esEsteElPropietario(jugador) && this.hipotecado){
            this.hipotecado = false;
            jugador.paga(this.getImporteCancelarHipoteca());
            result = true;
        }
        return result;
    }

    /**
     * @brief Si el jugador es el propietario entonces recibe el importe de Hipoteca
     * @see getImporteHipoteca(), Jugador.recibe()
     * @param jugador propietario
     * @return succeso / errors
     */
    boolean hipotecar(Jugador jugador){
        boolean result = false;
        if(!hipotecado && esEsteElPropietario(jugador)){
            this.hipotecado = true;
            jugador.recibe(this.getImporteHipoteca());
            result = true;
        }
        return result;
    }

    /**
     * @brief Si tenemos dinero suficiente entonces podemos comprar la propiedad.
     * @param jugador comprador
     * @return succeso / error 
     */
     boolean comprar(Jugador jugador){
        boolean result = false;
        if(!this.tienePropietario()){
            this.Propietario = jugador;
            jugador.paga(this.precioCompra);
            result = true;
        }
        return result;
    }

    /**
     * @brief Si somos el propietario entonces podemos construir más casas
     * @param jugador propietario
     * @return succeso / error
     */
    boolean construirCasa(Jugador jugador){
        boolean result = false;
        if(esEsteElPropietario(jugador)){
            jugador.paga(precioEdificar);
            numCasas++;
            result = true;
        }
        return result;
    }

    /**
     * @brief Similar al método para construir casas
     * @see construirCasa()
     * @param jugador
     * @return 
     */
    boolean construirHotel(Jugador jugador){
        boolean result = false;
        if(esEsteElPropietario(jugador)){
            this.derruirCasas(numCasas, jugador);
            jugador.paga(precioEdificar);
            numHoteles++;
            result = true;
        }
        return result;
    }

    /**
     * @brief Verifica si el parámetro es el @b this.Propietario de la clase.
     * @param jugador Jugador a comparar con
     * @return verdadero / falso
     */
    private boolean esEsteElPropietario(Jugador jugador){
        return this.Propietario == jugador;
    }
    
    /**
     * @brief Convertimos el @b this.Propietario en el nuevo valor pasado
     * @param jugador nuevo valor de @b this.Propietario.
     */
    void actualizaPropietarioPorConversion(Jugador jugador){
        this.Propietario = jugador;
    }
    
    
    /**
     * @brief Aplicamos la fórmula del juego para calcular el importe de Hipoteca
     * @return precio a pagar 
     */
    private float getImporteHipoteca(){
        return (float) (this.hipotecaBase*(1+(numCasas*0.5)+(numHoteles*2.5)));
    }
    

    public String getNombre() {
        return nombre;
    }

    float getPrecioCompra() {
        return precioCompra;
    }

    float getPrecioEdificar() {
        return precioEdificar;
    }

    boolean tienePropietario(){
        boolean result = false;
        if(Propietario!=null){
            result = true;
        }
        return result;
    }
        
    Jugador getPropietario() {
        return Propietario;
    }

    public int getNumCasas() {
        return numCasas;
    }

    public int getNumHoteles() {
        return numHoteles;
    }
    
    public boolean getHipotecado(){
        return hipotecado;
    }
    
    public float getAlquilerBase(){
        return alquilerBase;
    }
    
}
