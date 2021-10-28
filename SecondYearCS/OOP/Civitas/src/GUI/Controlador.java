package GUI;

import civitas.*;
import java.util.ArrayList;

public class Controlador {
    private CivitasJuego juego;
    private CivitasView vista;

    Controlador(CivitasJuego juego, CivitasView vista){
        this.juego = juego;
        this.vista = vista;
    }

    public void juega() throws Exception{
        vista.setCivitasJuego(juego);
        while(!juego.finalDelJuego()){
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
                       //vista.pausa();
                       vista.gestionar();
                       GestionesInmobiliarias gestion = GestionesInmobiliarias.values()[vista.getGestionElegida()];
                       //OperacionInmobiliaria Op = new OperacionInmobiliaria(gestion,vista.getPropiedadElegida());
                       switch(gestion){
                           case VENDER:
                               juego.vender(vista.getPropiedadElegida());
                               break;
                           case HIPOTECAR:
                               juego.hipotecar(vista.getPropiedadElegida());
                               break;
                           case CANCELAR_HIPOTECA:
                               juego.cancelarHipoteca(vista.getPropiedadElegida());
                               break;
                           case CONSTRUIR_CASA:
                               juego.construirCasa(vista.getPropiedadElegida());
                               break;
                           case CONSTRUIR_HOTEL:
                               juego.construirHotel(vista.getPropiedadElegida());
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
        vista.Ranking();
    }
}
