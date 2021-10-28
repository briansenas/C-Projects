package civitas;

import java.util.ArrayList;

public class Tablero {
    
    /**
     * @brief variables privadas a utilizar
     * @param numCasillaCarcel ubicación en el tablero de la carcel
     * @param casillas array con todas las casillas del tablero
     * @param porSalida número de veces que damos la vuelta al tablero
     * @param tieneJuez si ya hemos añadido el juez o no al tablero
     */
    private int numCasillaCarcel;
    private ArrayList<Casilla> casillas;
    private int porSalida;
    private boolean tieneJuez;
    
    /**
     * @brief constructor con ubicación de la casilla carcel
     * @param num ubicación casilla carcel
     */
    public Tablero(int num){
         if(num>=1)
            this.numCasillaCarcel = num;
        else
            this.numCasillaCarcel = 1;
         
        this.casillas = new ArrayList<>();
        this.casillas.add(new CasillaDescanso("Salida"));
        
        this.porSalida = 0;
        this.tieneJuez = false;
    }
    
    /**
     * @brief Asegurarse si ya podemos empezar el juego
     * @note Podemos empezar siempre y cuando ya hayamos añadido la casilla Carcel
     * @return verdadero / falso
     */
    private boolean correcto(){
        boolean result = false;
        if ( this.casillas.size() > this.numCasillaCarcel && this.tieneJuez)
            result = true;
        return result;
    }
    
    /**
     * @brief Verificamos si podemos acceder a una casilla dada
     * @see correcto()
     * @param numCasilla casilla que intentemos acceder
     * @return succeso / error
     */
    private boolean correcto(int numCasilla){
        boolean result = false;
        if ( this.correcto() && numCasilla >= 0 && numCasilla < casillas.size() )
            result = true;
        return result;
    }
    
    //Consultor del atributo numCasillaCarcel
    int getCarcel(){
        return this.numCasillaCarcel;
    }
    //Decrementa y devuelve el valor de porSalida
    int getPorSalida(){
        int temp = this.porSalida;
        if(this.porSalida>0)
            this.porSalida--;
        return temp;
    }
    
    /**
     * @brief Añadimos casillas pero verificamos siempre si ya podemos añadir la
     * casilla carcel
     * @param casilla casilla a añadir 
     */
    void añadeCasilla(Casilla casilla){
        if(this.casillas.size() == this.numCasillaCarcel)
            this.casillas.add(new CasillaDescanso("Carcel"));
        this.casillas.add(casilla);
        if(this.casillas.size() == this.numCasillaCarcel)
            this.casillas.add(new CasillaDescanso("Carcel"));
    }
    
    /**
     * @brief Si aún no tenemos juez, le añadimos uno al tablero y cambiamos
     * @b this.tieneJuez a true.
     */
    void añadeJuez(){
        if(!this.tieneJuez)
            this.casillas.add(new CasillaJuez(this.numCasillaCarcel,"Juez"));
        this.tieneJuez = true;
    }
    
    /**
     * @brief devuelve una casilla si tenemos el índice válido
     * @param numCasilla índice a verificar.
     * @see correcto(int num)
     * @return 
     */
    Casilla getCasilla(int numCasilla){
        Casilla p = null;
        if(correcto(numCasilla))
            p = this.casillas.get(numCasilla);
        return p;
    }
    
    
    /**
     * @brief Devolvemos la lista de casillas del tablero
     * @return 
     */
    public ArrayList<Casilla> getCasillas(){
        ArrayList<Casilla> result = new ArrayList<>();
        if(this.correcto())
            result = this.casillas;
        return result;
    }
    /**
     * @brief Calcular las nuevas posiciones del tablero despues de tirar el dado.
     * @param actual posición actual
     * @param tirada número obtenido al tirar el dado
     * @return nueva posición en el tablero.
     */
    int nuevaPosicion(int actual, int tirada){
        int result = -1;
        if(this.correcto()){
            result = ( actual + tirada ) % this.casillas.size();
            if ( result != actual + tirada )
                this.porSalida += 1;
        }
        return result;
    }
    
    /**
     * @brief Calcula el resultado necesario para llegar de una casilla a otra
     * @param origen posición actual
     * @param destino posición a la que queremos llegar
     * @return número de pasos a dar
     */
    int calcularTirada(int origen, int destino){
        int result = destino - origen;
        while(result < 0)
            result += this.casillas.size();
        if( result >= this.casillas.size() )
            result %= this.casillas.size();
        return result;
    }
    
    int sizeTablero(){
        return this.casillas.size();
    }
    
}
