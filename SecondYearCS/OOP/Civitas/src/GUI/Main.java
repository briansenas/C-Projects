/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;

import civitas.CivitasJuego;
import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author brian
 */
public class Main {
    public static void main(String[] args) throws Exception{
        CivitasView vista = new CivitasView();
        Dado.createInstance(vista);
        //Dado.getInstance().setDebug(true);
        CapturaNombres CapNombres = new CapturaNombres(vista,true);
        ArrayList<String> nombres = new ArrayList<>();
        nombres = CapNombres.getNombres();
        nombres.removeAll(Arrays.asList("",null));
        CivitasJuego juego = new CivitasJuego(nombres);
        Controlador control = new Controlador(juego,vista);
        vista.setCivitasJuego(juego);
        control.juega();        
    }
}
