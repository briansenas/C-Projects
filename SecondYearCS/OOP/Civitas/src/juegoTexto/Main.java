package juegoTexto;

import civitas.*;
import GUI.Dado;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception{
        VistaTextual vista = new VistaTextual();
        ArrayList<String> jugadores = new ArrayList<>();
        jugadores.add("Brian");
        //jugadores.add("Maria");
        CivitasJuego juego = new CivitasJuego(jugadores);
        Dado dado = Dado.getInstance();
        dado.setDebug(true);
        Controlador control = new Controlador(juego,vista);
        control.juega();
    }
}

