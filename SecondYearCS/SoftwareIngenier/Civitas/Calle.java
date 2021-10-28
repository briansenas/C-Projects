public abstract class Calle extends Casilla {

	TituloPropiedad titulo;
	private int numCasas;
	private int numHoteles;

	/**
	 * 
	 * @param jugador
	 */
	public TituloPropiedad asignarPropietario(Jugador jugador) {
		// TODO - implement Calle.asignarPropietario
		throw new UnsupportedOperationException();
	}

	private int calcularValorHipoteca() {
		// TODO - implement Calle.calcularValorHipoteca
		throw new UnsupportedOperationException();
	}

	public int cobrarAlquiler() {
		// TODO - implement Calle.cobrarAlquiler
		throw new UnsupportedOperationException();
	}

	public int edificarCasa() {
		// TODO - implement Calle.edificarCasa
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public void eliminarDeMisPropiedades(Casilla casilla) {
		// TODO - implement Calle.eliminarDeMisPropiedades
		throw new UnsupportedOperationException();
	}

	public boolean estaHipotecada() {
		// TODO - implement Calle.estaHipotecada
		throw new UnsupportedOperationException();
	}

	public int getCosteHipoteca() {
		// TODO - implement Calle.getCosteHipoteca
		throw new UnsupportedOperationException();
	}

	public int getPrecioCasa() {
		// TODO - implement Calle.getPrecioCasa
		throw new UnsupportedOperationException();
	}

	public int getPrecioHotel() {
		// TODO - implement Calle.getPrecioHotel
		throw new UnsupportedOperationException();
	}

	public String getTipo() {
		// TODO - implement Calle.getTipo
		throw new UnsupportedOperationException();
	}

	public int hipotecar() {
		// TODO - implement Calle.hipotecar
		throw new UnsupportedOperationException();
	}

	public boolean propietarioEncarcelado() {
		// TODO - implement Calle.propietarioEncarcelado
		throw new UnsupportedOperationException();
	}

	public boolean puedoTenerPropietario() {
		// TODO - implement Calle.puedoTenerPropietario
		throw new UnsupportedOperationException();
	}

	public void redimirHipoteca() {
		// TODO - implement Calle.redimirHipoteca
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param factor
	 */
	public boolean sePuedeEdificarCasa(int factor) {
		// TODO - implement Calle.sePuedeEdificarCasa
		throw new UnsupportedOperationException();
	}

	public boolean sePuedeEdificarHotel() {
		// TODO - implement Calle.sePuedeEdificarHotel
		throw new UnsupportedOperationException();
	}

	public boolean sePuedeHipotecar() {
		// TODO - implement Calle.sePuedeHipotecar
		throw new UnsupportedOperationException();
	}

	public boolean sePuedeRedimir() {
		// TODO - implement Calle.sePuedeRedimir
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param nuevoNumero
	 */
	public void setNumCasas(int nuevoNumero) {
		this.numCasas = nuevoNumero;
	}

	/**
	 * 
	 * @param nuevoNumero
	 */
	public void setNumHoteles(int nuevoNumero) {
		this.numHoteles = nuevoNumero;
	}

	public boolean soyEdificable() {
		// TODO - implement Calle.soyEdificable
		throw new UnsupportedOperationException();
	}

	public boolean tengoPropietario() {
		// TODO - implement Calle.tengoPropietario
		throw new UnsupportedOperationException();
	}

	public int VenderTitulo() {
		// TODO - implement Calle.VenderTitulo
		throw new UnsupportedOperationException();
	}

}