package OldStuff;
import java.util.Random;

class Dado {

    static final private Dado instance = new Dado(); //implementar singleton
    
    private final Random random;
    private int ultimoResultado;
    private boolean debug;
    private static int SalidaCarcel = 5; // valor 5 como static const al principio
    
    static public Dado getInstance(){
        return instance;
    }
    //Constructor sin parámetros
    private Dado(){
        this.random = new Random();
        this.ultimoResultado = 0;
        this.debug = false;
    }
    /**
     * @brief Devuelve un número aleatorio generado entre 1-6 ( Dado )
     * @return @b this.ultimoResultado ( parámetro de la clase )
     */
    int tirar(){
        this.ultimoResultado = 1;
        if(!this.debug){
            this.ultimoResultado = this.random.nextInt(6)+1;
        }
        return this.ultimoResultado;
    }
    /**
     * @brief Verificamos si el @b this.ultimoResultado >= @b this.SalidaCarcel
     * @return verdadero/falso
     */
    boolean salgoDeLaCarcel(){
        boolean result = false;
        if(this.ultimoResultado >= Dado.SalidaCarcel)
            result = true;
        return result;
    }
    /**
     * @brief Decide que jugar empieza utilizando this.random
     * @param n número de jugadores
     * @return el jugador que debe empezar entre 0 y n-1
     */
    int quienEmpieza(int n){
        return this.random.nextInt(n);
    }
    /**
     * @brief Cambiamos el valor de @b this.debug
     * @param d nuevo valor de @b this.debug
     */
    public void setDebug(boolean d){
        this.debug = d;
        Diario.getInstance().ocurreEvento("Debug");
    }
    /**
     * @return devuelve el @b this.ultimoResultado
     */
    int getUltimoResultado(){
        return this.ultimoResultado;
    }
    
}
