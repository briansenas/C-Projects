package hotel;

public class HabitacionFamiliaNumerosa extends Habitacion {
    private int literas;

    public HabitacionFamiliaNumerosa(int numero, int camasM, int camasI, int literas) {
        super(numero, camasM, camasI);
        this.literas = literas;
    }

    public int getLiteras() {
        return literas;
    }
    
    public void setLiteras(int literas) {
        this.literas = literas;
    }

    @Override
    public int capacidad() {
        return super.capacidad() + literas;
    }
}
