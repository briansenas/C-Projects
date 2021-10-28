public abstract class Casilla {

	private int coste;
	private int numeroCasilla;

	public int getCoste() {
		return this.coste;
	}

	private int getNumeroCasilla() {
		return this.numeroCasilla;
	}

	public abstract boolean soyEdificable();

}