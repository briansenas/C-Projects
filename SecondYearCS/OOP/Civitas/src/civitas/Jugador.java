package civitas;

import GUI.Dado;
import java.util.ArrayList;

public class Jugador implements Comparable<Jugador> {
    
    
    protected static int CasasMax = 4, CasasPorHotel  = 4,
                            HotelesMax = 4;
    private static final float PasoPorSalida = 250f, PrecioLibertad = 200f, 
                            SaldoInicial = 1000f;
    
    protected String nombre;
    protected int numCasillaActual;
    protected float saldo;
    protected boolean puedeComprar;
    protected boolean encarcelado;
    protected SorpresaSalirCarcel salvoconducto;
    protected ArrayList<TituloPropiedad> ListaPropiedades;
    
    /**
     * @brief Constructor con parámetro
     * @param nombre nombre del jugador
     */
    Jugador(String nombre){
        this.nombre = nombre;
        numCasillaActual = 0;
        saldo = SaldoInicial;
        encarcelado = false;
        puedeComprar = true;
        ListaPropiedades = new ArrayList<TituloPropiedad>();
        salvoconducto = null;
    }
    
    /**
     * @brief Constructor de copia de visibilidad de paquete protected
     * @param otro jugador al cuál copiamos los datos
     */
    protected Jugador(Jugador otro){
        this.nombre = otro.nombre;
        this.numCasillaActual = otro.numCasillaActual;
        this.saldo = otro.saldo;
        this.encarcelado = otro.encarcelado;
        this.puedeComprar = otro.puedeComprar;
        this.ListaPropiedades = otro.ListaPropiedades;
        this.salvoconducto = otro.salvoconducto;
    }
    
    /**
     * @brief verifica si el jugador debe ser Encarcelado o No, y si posee SalvoConducto
     * @return verdadero/falso
     */
    protected boolean debeSerEncarcelado(){
        boolean result = false;
        if(encarcelado){
            result = true;
        }
        if(this.tieneSalvoconducto()){
            result = false;
            this.perderSalvoconducto();
            Diario.getInstance().ocurreEvento("Se Libre de la Cárcel");
        }
        return result;
    }
    
    /**
     * @brief Si debe ser encarcelado, entonces guardamos el evento en el diario
     * y cambiamos su posición al parámetro de entrada.
     * @see debeSerEncarcelado(), Diario.getInstance()
     * @param numCasillaCarcel posición de la casilla carcel en el tablero.
     * @return succeso/error
     */
    boolean encarcelar(int numCasillaCarcel){
        if(debeSerEncarcelado()){
            this.moverACasilla(numCasillaCarcel);
            this.encarcelado = true;
            Diario.getInstance().ocurreEvento("Va a la Cárcel");
        }
        return this.encarcelado;
    }
    
    /**
     * @brief En caso de no estar @b encarcelado, entonces obtenemos salvoconducto
     * @param s salvoconducto del mazo
     * @return succeso/error
     */
    boolean obtenerSalvoConducto(SorpresaSalirCarcel s){
        boolean result = false;
        if(!this.encarcelado){
            this.salvoconducto = s;
            result = true;
        }
        return result;
    }
    
    /**
     * @brief En caso de haber utilizado el salvoconducto, lo perdemos.
     * @see Sorpresa.usada();
     */
    protected void perderSalvoconducto(){
        salvoconducto.usada();
        salvoconducto = null;
    }
    
    /**
     * @brief Verificamos si tiene salvoconducto
     * @return verdadero/falso
     */
    protected boolean tieneSalvoconducto(){
        boolean result = false;
        if(this.salvoconducto != null){
            result = true;
        }
        return result;
    }
    
    /**
     * @brief Si no está @b encarcelado, entonces puede comprar.
     * @return verdadero/falso
     */
    boolean puedeComprarCasilla(){
        this.puedeComprar = !encarcelado;
        return this.puedeComprar;
    }
    
    /**
     * @brief modificamos el saldo según una cantidad dada
     * @param cantidad cantidad a modificar
     * @see modificarSaldo()
     * @return succeso/error
     */
    boolean paga(float cantidad){
        return this.modificarSaldo(cantidad *(-1));
    }
    
    /**
     * @brief Si no está @b encarcelado, paga cierta cantidad de impuesto
     * @param cantidad cantidad a pagar
     * @see paga()
     * @return 
     */
    boolean pagaImpuesto(float cantidad){
        boolean result = false;
        if(!encarcelado){
            result = this.paga(cantidad);
        }
        return result;
    }
    
    /**
     * @brief sigue la misma estructura que pagaImpuesto()
     * @param cantidad cantidad a pagar
     * @return succeso/error
     */
    boolean pagaAlquiler(float cantidad){
        boolean result = false;
        if(!encarcelado){
            result = this.paga(cantidad);
        }
        return result;
    }
    
    /**
     * @brief Recibe una cantidad dada de dinero
     * @see modficarSaldo()
     * @param cantidad cantidad a recibir
     * @return succeso/error
     */
    boolean recibe(float cantidad){
        boolean result = false;
        if(!encarcelado){
           result = this.modificarSaldo(cantidad);
        }
        return result;
    }
    
    /**
     * @brief añade una cantidad dada de dinero a @b this.saldo
     * @param cantidad cantidad a añadir
     * @return succeso
     */
    boolean modificarSaldo(float cantidad){
        this.saldo += cantidad;
        return true;
    }
    
    /**
     * @brief Debemos mover el jugador a la casilla carcel 
     * @param numCasilla ubicación de la casilla carcel en el tablero
     * @return succeso/error
     */
    boolean moverACasilla(int numCasilla){
        boolean result = false;
        if(!encarcelado){
            this.numCasillaActual = numCasilla;
            this.puedeComprar = false;
            result = true;
            Diario.getInstance().ocurreEvento("Movido a Casilla: " + numCasilla);
        }
        return result;
    }
    
    /**
     * @brief verifica si @b this.saldo >= @b precio
     * @param precio cantidad a pagar
     * @return succeso / error
     */
    protected boolean puedoGastar(float precio){
        boolean result = false;
        if(!encarcelado){
            result = this.saldo >= precio;
        }
        return result;
    }
    
    /**
     * @brief verificamos si el jugador posee la propiedad dada en @b this.ListaPropiedades
     * @param ip ubicación de la propiedad en la lista.
     * @return succeso / error
     */
    private boolean existeLaPropiedad(int ip){
        boolean result = false;
        if(!this.ListaPropiedades.isEmpty()){
            if(ip>=0 && ip < this.ListaPropiedades.size()){
                result = true;
            }
        }
        return result;
    }
    
    /**
     * @brief Si @b !encarcelado y @b existeLaPropiedad() entonces podemos vender
     * @see TituloPropiedad.vender()
     * @param ip propiedad a vende
     * @return succeso / error
     */
    boolean vender(int ip){
        boolean result = false;
        if(!encarcelado){
            if(this.existeLaPropiedad(ip)){
                result = this.ListaPropiedades.get(ip).vender(this);
                if(result){
                    Diario.getInstance().ocurreEvento("Hemos vendido la propiedad "+
                            ListaPropiedades.get(ip).getNombre() + " de " + this.getNombre());
                    this.ListaPropiedades.remove(ip);

                }
            }
        }
        return result;
    }
    
    /**
     * @brief verificar si @b this.ListaPropiedades está vacía o no
     * @return verdadero / falso
     */
    boolean tieneAlgoQueGestionar(){
        return !this.ListaPropiedades.isEmpty();
    }
    
    /**
     * @brief verificamos si @b this.saldo >= @b this.PrecioLibertad
     * @return verdadero / falso
     */
    private boolean puedeSalirCarcelPagando(){
        return ( this.saldo >= Jugador.PrecioLibertad );
    }
    
    /**
     * @brief Intentamos salir de la carcel pagando 
     * @see puedeSalirCarcelPagando()
     * @return succeso / error
     */
    boolean salirCarcelPagando(){
        boolean result = false;
        if (this.encarcelado && this.puedeSalirCarcelPagando()){
            result = this.paga(Jugador.PrecioLibertad);
            if(result){
                this.encarcelado = false;
                Diario.getInstance().ocurreEvento("Salgo de la Carcel Pagando");
            }
        }
        return result;            
    }
    
    /**
     * @brief Intentamos salir de la carcel tirando el dado
     * @see Dado.getInstance().saldoDeLaCarcel()
     * @return succeso / error
     */
    boolean salirCarcelTirando(){
        Dado.getInstance().tirar();
        if(Dado.getInstance().salgoDeLaCarcel()){
            encarcelado = false;
            Diario.getInstance().ocurreEvento("Salgo De La carcel tirando");
        }
        return encarcelado;
        
    }
    
    /**
     * @brief Escribimos en el diario si hemos pasado por salida y recibimos el dinero
     * @see modificarSaldo()
     * @return true
     */
    boolean pasaPorSalida(){
        Diario.getInstance().ocurreEvento("Paso por Salida");
        this.modificarSaldo(Jugador.PasoPorSalida);
        return true;
    }
    
    boolean cancelarHipoteca(int ip){
        boolean result = false;
        if(!encarcelado){
            if(this.existeLaPropiedad(ip)){
                TituloPropiedad propiedad = this.ListaPropiedades.get(ip);
                float cantidad = propiedad.getImporteCancelarHipoteca();
                if(this.puedoGastar(cantidad)){
                    result = propiedad.cancelarHipoteca(this);
                    if(result)
                        Diario.getInstance().ocurreEvento("El jugador " + this.getNombre()
                        + " a cancelado la hipoteca en la " + propiedad.getNombre());
                }
            }
        }
        return result;
    }
    
    boolean comprar(TituloPropiedad titulo){
        boolean result = false;
        if(!encarcelado){
            if(this.puedeComprar){
                float precio = titulo.getPrecioCompra();
                if(this.puedoGastar(precio)){
                    result = titulo.comprar(this);
                    if(result){
                        this.ListaPropiedades.add(titulo);
                        Diario.getInstance().ocurreEvento("El jugador " +
                                this.getNombre() + " ha comprado " + titulo.getNombre());
                    }
                    puedeComprar=false;
                }
            }
        }
        return result;
    }
    
    private boolean puedoEdificarHotel(TituloPropiedad propiedad){
        boolean result = false;
        if(puedoGastar(propiedad.getPrecioEdificar()) &&
           propiedad.getNumHoteles()<getHotelesMax() && 
                propiedad.getNumCasas()>=4) //HardCoded number 4 because Iam not sure what or if i need a function or atribute for that
            result = true;
        return result;
    }
    
    //No estoy seguro de la ultima linea, no se si es necesario...hay que investigar
    boolean construirHotel(int ip){
        boolean result = false;
        if(!encarcelado){
            if(this.existeLaPropiedad(ip)){
                TituloPropiedad propiedad = ListaPropiedades.get(ip);
                boolean puedoEdificarHotel = this.puedoEdificarHotel(propiedad);
                if(puedoEdificarHotel){
                    result = propiedad.construirHotel(this);
                    int casasPorHotel = getCasasPorHotel();
                    propiedad.derruirCasas(casasPorHotel, this);
                    Diario.getInstance().ocurreEvento("El jugador " + this.getNombre()+
                            " construye hotel en " + propiedad.getNombre());
                    ListaPropiedades.set(ip,propiedad);
                }
            }
        }
        return result;
    }
    
    boolean puedoEdificarCasa(TituloPropiedad propiedad){
        boolean result = false;
        float precio = propiedad.getPrecioEdificar();
        if(puedoGastar(precio) && 
           propiedad.getNumCasas()<getCasasMax())
            result = true;
        return result;
    }
    
    boolean construirCasa(int ip){
        boolean result = false;
        if(!encarcelado){
            if(this.existeLaPropiedad(ip)){
                TituloPropiedad propiedad = ListaPropiedades.get(ip);
                boolean puedoEdificarCasa = this.puedoEdificarCasa(propiedad);
                if(puedoEdificarCasa){
                    result = propiedad.construirCasa(this);
                    Diario.getInstance().ocurreEvento("El jugador " + this.getNombre()
                    +  " ha construido una casa en " + propiedad.getNombre());
                    ListaPropiedades.set(ip,propiedad);
                }
            }
        }
        return result;
    }
    
    boolean hipotecar(int ip){
        boolean result = false;
        if(!encarcelado){
            if(this.existeLaPropiedad(ip)){
                TituloPropiedad propiedad = ListaPropiedades.get(ip);
                result = propiedad.hipotecar(this);
                if(result)
                    Diario.getInstance().ocurreEvento("EL jugador " + this.getNombre()
                          + " hipoteca la propiedad " + propiedad.getNombre());
            }
        }
        return result;
    }
    
    /**
     * @brief Sobreescribimos la función compareTo para que funcione con otro Jugador
     * @note Los resultados son -1 ( this menor otro ), 0 ( this == otro ) y 1 ( this mayor otro )
     * @param otro jugador a comparar
     * @return 
     */
    @Override
    public int compareTo(Jugador otro){
        int result;
        if(this.saldo >= otro.saldo)
            result = 1;
        else if (this.saldo == otro.saldo)
            result = 0;
        else
            result = -1;
        return result;
    }
    
    boolean enBancarrota(){
        return (this.saldo <= 0);
    }
    
    private float getPremioPasoSalida(){
        return PasoPorSalida;
    }
    
    private float getPrecioLibertad(){
        return PrecioLibertad;
    }
    
    protected int getCasasMax() {
        return CasasMax;
    }
    
    int getCasasPorHotel(){
        return CasasMax*HotelesMax;
    }

    protected int getHotelesMax() {
        return HotelesMax;
    }

    public String getNombre() {
        return nombre;
    }

    int getNumCasillaActual() {
        return numCasillaActual;
    }

    public float getSaldo() {
        return saldo;
    }

    public ArrayList<TituloPropiedad> getPropiedades(){
        ArrayList<TituloPropiedad> res = new ArrayList<>();
        for( int i = 0; i < this.ListaPropiedades.size(); i++ ){
            res.add( this.ListaPropiedades.get(i) );
        }
        return res;
    }

    public boolean isEncarcelado() {
        return encarcelado;
    }

    protected boolean getPuedeComprar() {
        return puedeComprar;
    }
    
    @Override
    public String toString(){
        String res = "Jugador: " + this.nombre + " saldo: " + this.saldo;
        if(ListaPropiedades.size()>0){
            res += "\n Propiedades:";
        }
        for(int i=0;i<this.ListaPropiedades.size();i++){
            res += "\n\t" + ListaPropiedades.get(i).getNombre();
            res += " casas: " + ListaPropiedades.get(i).getNumCasas();
            res += " hoteles: " + ListaPropiedades.get(i).getNumHoteles();
        }
        return res;
    }
   
}


