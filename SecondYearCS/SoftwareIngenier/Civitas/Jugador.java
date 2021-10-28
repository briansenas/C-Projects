import java.util.*;

public class Jugador {

	Casilla casillaActual;
	Collection<TituloPropiedad> propiedades;
	Sorpresa libertad;
	private boolean encarcelado;
	private static int factorEspeculador = 1;
	private String nombre;
	private int numeroEstacionesEnPropiedad;
	private int saldo;

	/**
	 * 
	 * @param casilla
	 */
	public boolean actualizarPosicion(Casilla casilla) {
		// TODO - implement Jugador.actualizarPosicion
		throw new UnsupportedOperationException();
	}

	public void comprarTitulo() {
		// TODO - implement Jugador.comprarTitulo
		throw new UnsupportedOperationException();
	}

	public Sorpresz devolverCartaSalirCarcel() {
		// TODO - implement Jugador.devolverCartaSalirCarcel
		throw new UnsupportedOperationException();
	}

	public int getNUmeroEstacionesEnPropiedad() {
		// TODO - implement Jugador.getNUmeroEstacionesEnPropiedad
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public void irACarcel(Casilla casilla) {
		// TODO - implement Jugador.irACarcel
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param cantidad
	 */
	public void modificarSaldo(int cantidad) {
		// TODO - implement Jugador.modificarSaldo
		throw new UnsupportedOperationException();
	}

	public int obtenerCapital() {
		// TODO - implement Jugador.obtenerCapital
		throw new UnsupportedOperationException();
	}

	public Casilla obtenerPosicion() {
		// TODO - implement Jugador.obtenerPosicion
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param cantidad
	 */
	public void pagarCobrarPorCasaYHotel(int cantidad) {
		// TODO - implement Jugador.pagarCobrarPorCasaYHotel
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param cantidad
	 */
	public boolean pagarLibertad(int cantidad) {
		// TODO - implement Jugador.pagarLibertad
		throw new UnsupportedOperationException();
	}

	public boolean puedoComprarTitulo() {
		// TODO - implement Jugador.puedoComprarTitulo
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public boolean puedoEdificarCasa(Casilla casilla) {
		// TODO - implement Jugador.puedoEdificarCasa
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public boolean puedoEdificarHotel(Casilla casilla) {
		// TODO - implement Jugador.puedoEdificarHotel
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public boolean puedoHipotecar(Casilla casilla) {
		// TODO - implement Jugador.puedoHipotecar
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public boolean puedoPagarHipoteca(Casilla casilla) {
		// TODO - implement Jugador.puedoPagarHipoteca
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public boolean puedoVenderPropiedad(Casilla casilla) {
		// TODO - implement Jugador.puedoVenderPropiedad
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param carta
	 */
	public void recibirCartaSalirCarcel(Sorpresa carta) {
		// TODO - implement Jugador.recibirCartaSalirCarcel
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param encarcelado
	 */
	public void setEncarcelado(boolean encarcelado) {
		this.encarcelado = encarcelado;
	}

	public boolean tieneCartaLibertad() {
		// TODO - implement Jugador.tieneCartaLibertad
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param cantidad
	 */
	private boolean tengoSaldo(int cantidad) {
		// TODO - implement Jugador.tengoSaldo
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	public void venderPropiedad(Casilla casilla) {
		// TODO - implement Jugador.venderPropiedad
		throw new UnsupportedOperationException();
	}

	private int calcularCantidadPorCasaYHotel() {
		// TODO - implement Jugador.calcularCantidadPorCasaYHotel
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	private void eliminarDeMisPropiedades(Casilla casilla) {
		// TODO - implement Jugador.eliminarDeMisPropiedades
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	private boolean esDeMiPropiedad(Casilla casilla) {
		// TODO - implement Jugador.esDeMiPropiedad
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param casilla
	 */
	private void irA(Casilla casilla) {
		// TODO - implement Jugador.irA
		throw new UnsupportedOperationException();
	}

	public int getFactorEspeculador() {
		return this.factorEspeculador;
	}

}