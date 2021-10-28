package juegoTexto;

import civitas.*;
import java.util.ArrayList;

public class Controlador {
    private CivitasJuego juego;
    private VistaTextual vista;

    Controlador(CivitasJuego juego, VistaTextual vista){
        this.juego = juego;
        this.vista = vista;
    }

    public void juega() throws Exception{
        vista.setCivitasJuego(juego);
        while(!juego.finalDelJuego()){
            System.out.println("Jugador " + juego.getJugador().getNombre() + " con saldo " + juego.getJugador().getSaldo());
            vista.actualizarVista();
            vista.pausa();
            OperacionesJuego operacion = juego.siguientePaso();
            vista.mostrarSiguienteOperacion(operacion);
            if(operacion==OperacionesJuego.PASAR_TURNO){
                vista.mostrarEventos();
            }
            if(!juego.finalDelJuego()){
               switch(operacion){
                   case COMPRAR:
                       Respuestas res = vista.comprar();
                       if(res==Respuestas.SI)
                           juego.comprar();
                       juego.siguientePasoCompletado(operacion);
                       break;
                   case GESTIONAR:
                       vista.gestionar();
                       GestionesInmobiliarias gestion = GestionesInmobiliarias.values()[vista.getGestion()];
                       OperacionInmobiliaria Op = new OperacionInmobiliaria(gestion,vista.getPropiedad());
                       switch(gestion){
                           case VENDER:
                               juego.vender(vista.getPropiedad());
                               break;
                           case HIPOTECAR:
                               juego.hipotecar(vista.getPropiedad());
                               break;
                           case CANCELAR_HIPOTECA:
                               juego.cancelarHipoteca(vista.getPropiedad());
                               break;
                           case CONSTRUIR_CASA:
                               juego.construirCasa(vista.getPropiedad());
                               break;
                           case CONSTRUIR_HOTEL:
                               juego.construirHotel(vista.getPropiedad());
                               break;
                           case TERMINAR:
                               juego.siguientePasoCompletado(operacion);
                               break;
                        }
                       break;
                   case SALIR_CARCEL:
                       vista.salirCarcel();
                       juego.siguientePasoCompletado(operacion);
                       break;                  
               }
            }   
        }
        ArrayList<Jugador> ranking = juego.ranking();
                for(int i=0;i<ranking.size();i++){
                    System.out.println(ranking.get(i).toString());
                }
    }
}
