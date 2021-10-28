package civitas;
import GUI.Dado;
import java.util.ArrayList;
import java.util.Collections;
public class CivitasJuego {
    
    private ArrayList<Jugador> jugadores = new ArrayList<>();
    private int indiceJugadorActual;
    private GestorEstados gestorEstados;
    private EstadosJuego estado;
    private Tablero tablero;
    private int carcel=5;
    private MazoSorpresa mazo;
    
    public CivitasJuego(ArrayList<String> nombres){
        for(int i=0;i<nombres.size();i++){
            Jugador nuevo = new Jugador(nombres.get(i));
            jugadores.add(nuevo);
        }
        gestorEstados = new GestorEstados();
        this.estado = gestorEstados.estadoInicial();
        indiceJugadorActual = Dado.getInstance().quienEmpieza(jugadores.size());
        mazo = new MazoSorpresa(true);
        this.inicializaTablero(this.mazo);
        this.inicializaMazoSorpresa(this.tablero);
    }
    
    private void inicializaTablero(MazoSorpresa mazo){
        this.tablero = new Tablero(carcel);
        for(int i=1;i<20;i++){
            if(i==3 || i == 12 | i == 17)
                this.tablero.añadeCasilla(new CasillaSorpresa(this.mazo,"Sorpresa"));
            else if(i==6)
                continue;
            else if(i==7)
                this.tablero.añadeCasilla(new CasillaImpuesto(0.15f*1000f,"Impuesto"));
            else if(i==10)
                this.tablero.añadeCasilla(new CasillaDescanso("Parking"));
            else if(i==15)
                this.tablero.añadeJuez();
            else 
                this.tablero.añadeCasilla(new CasillaCalle(new TituloPropiedad("Calle"+Integer.toString(i),25 + i*25,0.5f + i*0.1f,40 + i*5,40 + i*20,60 + i*5),"Calle")); //Values?¿
        }
       

    }
    
    /**
     * @param tablero 
     * EL profesor inicializa sus sorpresas con x lineas de una simple
     * llamada a mazo.AlMazo, de manera que vamos a ignorar nuestro bucle y 
     * realizarlo de esta manera tambien.
     */
    private void inicializaMazoSorpresa(Tablero tablero){
       mazo.alMazo(new SorpresaIrCasilla(tablero,10,"IrACasilla"));
       mazo.alMazo(new SorpresaIrCasilla(tablero,3,"IrACasilla"));
       mazo.alMazo(new SorpresaJugadorEspeculador("ConvertirAJugadorMafioso",300f));
       mazo.alMazo(new SorpresaJugadorEspeculador("ConvertirAJugadorEntrepeneur",150f));
       mazo.alMazo(new SorpresaIrCarcel(tablero,"IrACarcelPringao"));
       mazo.alMazo(new SorpresaIrCarcel(tablero,"IrACarcelPringao2"));
       mazo.alMazo(new SorpresaPagarCobrar(75f,"PagarCobrar"));
       mazo.alMazo(new SorpresaSalirCarcel(this.mazo,"PorChivato"));
       mazo.alMazo(new SorpresaSalirCarcel(this.mazo,"ErrorPapeleo"));
       mazo.alMazo(new SorpresaPorCasaHotel(10f,"APagarImpuesto"));
       mazo.alMazo(new SorpresaPorCasaHotel(-10f,"ErrorImpuesto"));
       mazo.alMazo(new SorpresaPorJugador(30f,"HasGanadoAlPoker"));
       mazo.alMazo(new SorpresaPorJugador(-30f,"HasPerdidoAlPoker"));
    }
    
    public void contabilizarPasosPorSalida(Jugador jugadorActual){
        while(this.tablero.getPorSalida()>0){
            jugadorActual.pasaPorSalida();
        }
    }
    
    private void pasarTurno(){
        this.indiceJugadorActual++;
        if(this.indiceJugadorActual >= this.jugadores.size())
            indiceJugadorActual = 0;
    }
    
    public void siguientePasoCompletado(OperacionesJuego operacion){
        this.estado = this.gestorEstados.siguienteEstado(jugadores.get(indiceJugadorActual), this.estado, operacion);
  
    }
    
    public boolean construirCasa(int ip){
        return this.jugadores.get(this.indiceJugadorActual).construirCasa(ip);
    }
    
    public boolean construirHotel(int ip){
        return this.jugadores.get(this.indiceJugadorActual).construirHotel(ip);
    }
    
    public boolean vender(int ip){
        return this.jugadores.get(this.indiceJugadorActual).vender(ip);
    }
    
    public boolean hipotecar(int ip){
        return this.jugadores.get(this.indiceJugadorActual).hipotecar(ip);
    }
    
    public boolean cancelarHipoteca(int ip){
        return this.jugadores.get(this.indiceJugadorActual).cancelarHipoteca(ip);
    }
    
    public boolean salirCarcelPagando(){
        return this.jugadores.get(this.indiceJugadorActual).salirCarcelPagando();
    }
    
    public boolean salirCarcelTirando(){
        return this.jugadores.get(this.indiceJugadorActual).salirCarcelTirando();
    }
    
    public boolean finalDelJuego(){
        boolean result = false;
        for(Jugador jugador: this.jugadores){
            if(jugador.enBancarrota())
                result = true;
        }
        return result;
    }
    
    public ArrayList<Jugador> ranking(){
        Collections.sort(this.jugadores);
        Collections.reverse(this.jugadores);
        return this.jugadores;
    }
    
    private void avanzaJugador() throws Exception{
        Jugador jugadorActual = this.jugadores.get(indiceJugadorActual);
        int posicionActual = jugadorActual.getNumCasillaActual();
        int tirada = Dado.getInstance().tirar();
        int posicionNueva = this.tablero.nuevaPosicion(posicionActual,tirada);
        Casilla casilla = this.tablero.getCasilla(posicionNueva);
        this.contabilizarPasosPorSalida(jugadorActual);
        jugadorActual.moverACasilla(posicionNueva);
        casilla.recibeJugador(indiceJugadorActual, jugadores);
        this.contabilizarPasosPorSalida(jugadorActual);
    }
    
    public OperacionesJuego siguientePaso() throws Exception{
        Jugador jugadorActual = this.jugadores.get(indiceJugadorActual);
        OperacionesJuego operacion = gestorEstados.operacionesPermitidas(jugadorActual, estado);
        if(operacion==OperacionesJuego.PASAR_TURNO){
            this.pasarTurno();
            this.siguientePasoCompletado(operacion);
        }else if (operacion==OperacionesJuego.AVANZAR){
            this.avanzaJugador();
            this.siguientePasoCompletado(operacion);
        }
        return operacion;
    }
    
    public boolean comprar(){
        boolean result = false;
        Jugador jugadorActual = this.jugadores.get(indiceJugadorActual);
        int numCasillaActual = jugadorActual.getNumCasillaActual();
        Casilla casilla = this.tablero.getCasilla(numCasillaActual);
        TituloPropiedad titulo = ((CasillaCalle)casilla).getTituloPropiedad();
        result = jugadorActual.comprar(titulo);
        return result;
    }
    
    public Jugador getJugador(){
        return this.jugadores.get(this.indiceJugadorActual);
    }
    
    public Casilla getCasillaActual(){
        Jugador jugadorActual = this.jugadores.get(this.indiceJugadorActual);
        int numCasillaActual = jugadorActual.getNumCasillaActual();
        return this.tablero.getCasilla(numCasillaActual);
    }
    
    public int numCasillaActual(){
        return this.jugadores.get(this.indiceJugadorActual).getNumCasillaActual();
    }
    
}
