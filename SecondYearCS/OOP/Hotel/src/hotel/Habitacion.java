package hotel;

public class Habitacion {
    private int numero; //< Número de habitación
    private int camasM; //< Número de camas de matrimonio
    private int camasI; //< Número de camas individuales
    
    public Habitacion(int numero, int camasM, int camasI) {
        this.numero = numero;
        this.camasM = camasM;
        this.camasI = camasI;
    }
    public int getNumero() {
        return numero;
    }
    public void setNumero(int numero) {
        this.numero = numero;
    }
    public int getCamasM() {
        return camasM;
    }
    public void setCamasM(int camasM) {
        this.camasM = camasM;
    }
    public int getCamasI() {
        return camasI;
    }
    public void setCamasI(int camasI) {
        this.camasI = camasI;
    }

    public int capacidad() {
        return camasI + camasM*2;
    }
}
