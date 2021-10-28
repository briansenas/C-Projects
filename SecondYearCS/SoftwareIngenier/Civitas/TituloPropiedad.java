public class TituloPropiedad {

	Calle calle;
	private string nombre;
	private int alquilerBase;
	private int factorDevaluacion;
	private int hipoteca;
	private boolean hipotecada;
	private int precioCasa;
	private int precioHotel;

	/**
	 * 
	 * @param jugador
	 */
	public void asignarPropietario(Jugador jugador) {
		// TODO - implement TituloPropiedad.asignarPropietario
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param coste
	 */
	public void cobrarAlquiler(int coste) {
		// TODO - implement TituloPropiedad.cobrarAlquiler
		throw new UnsupportedOperationException();
	}

	public int getCosteAlquiler() {
		// TODO - implement TituloPropiedad.getCosteAlquiler
		throw new UnsupportedOperationException();
	}

	public int getHipoteca() {
		return this.hipoteca;
	}

	public boolean getHipotecada() {
		return this.hipotecada;
	}

	public int getNumeroEstacionesPropietario() {
		// TODO - implement TituloPropiedad.getNumeroEstacionesPropietario
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param hipotecada
	 */
	public void setHipotecada(boolean hipotecada) {
		this.hipotecada = hipotecada;
	}

	public void sinPropietario() {
		// TODO - implement TituloPropiedad.sinPropietario
		throw new UnsupportedOperationException();
	}

	public boolean tengoPropietario() {
		// TODO - implement TituloPropiedad.tengoPropietario
		throw new UnsupportedOperationException();
	}

}