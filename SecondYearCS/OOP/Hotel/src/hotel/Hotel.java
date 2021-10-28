package hotel;

import java.util.ArrayList;

public class Hotel {
    
    private static final int MAXHABITACIONES = 100;
    
    private String ciudad;
    private String direccion;
    private int estrellas;
    private Director dirige;
    private ArrayList<Habitacion> habitaciones;

    public Hotel(String ciudad, String direccion, int estrellas){
        this.ciudad = ciudad;
        this.direccion = direccion;
        this.estrellas = estrellas;
        
        this.dirige = null;
        this.habitaciones = new ArrayList<>();
    }
    public Hotel(String ciudad, String direccion){
        this.ciudad = ciudad;
        this.direccion = direccion;
        this.estrellas = 4;
        
        this.dirige = null;
        this.habitaciones = new ArrayList<>();
    }
    
    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }
    public String getDireccion() {
        return direccion;
    }
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }
    public int getEstrellas() {
        return estrellas;
    }
    public void setEstrellas(int estrellas) {
        if ((estrellas >= 1) && (estrellas <= 5)) {
            this.estrellas = estrellas;        
        } else { 
            System.out.println("Hotel::setEstrellas: estrellas debe estar entre 1 y 5");
            this.estrellas = 1;           
        }
    }
    public ArrayList<Habitacion> getHabitaciones() {
        return habitaciones;
    }

    public Director getDirige() {
        return dirige;
    }

    public void setDirige(Director dirige) {
        if (dirige.getTelefono() == 0) {
            System.out.println("Hotel::setDirige: Director no válido");
        } else this.dirige = dirige;
    }

    public void asigna(Hotel otro) {
        ciudad = otro.ciudad;
        direccion = otro.direccion;
        estrellas = otro.estrellas;
        dirige = otro.dirige;
        
        habitaciones = new ArrayList<>();
        for(Habitacion hab: otro.habitaciones) {
            habitaciones.add(new Habitacion(hab.getNumero(), hab.getCamasM(), hab.getCamasI()));
        }
    }

    public void añadirHabitacion(int numero, int camasM, int camasI) {
        if (habitaciones.size() == MAXHABITACIONES) {
            System.out.println("Hotel::añadirHabitacion: número máximo de habitaciones alcanzado");
        } else {
            habitaciones.add(new Habitacion(numero, camasM, camasI));
        }
    }
    
    public Habitacion consultaHabitacion(int numero) {
        for(Habitacion hab: habitaciones) {
            if (hab.getNumero() == numero) return hab;
        }
        System.out.println("Hotel::consultaHabitacion: la habitación no existe");
        return null;
    }
    
    public int capacidad() {
        int total = 0;
        for(Habitacion hab: habitaciones) {
            total += hab.getCamasI() + hab.getCamasM()*2;
        }
        return total;
    }
	
    public String informacion() {
      Director director = getDirige();
      String nombre = director.getNombre();
      String cadena = "El director del hotel se llama " + nombre + " y las habitaciones son: ";
      ArrayList<Habitacion> habitaciones = getHabitaciones();
      for (Habitacion habitacion: habitaciones) {
        int numero = habitacion.getNumero();
        cadena += " " + numero;
      }
      return(cadena);
    }

    public void añadirHabitacionFamiliaNumerosa(int numero, int camasM, int camasI, int literas) {
        if (habitaciones.size() == MAXHABITACIONES) {
            System.out.println("Hotel::añadirHabitacionFamiliaNumerosa: número máximo de habitaciones alcanzado");
        } else {
            habitaciones.add(new HabitacionFamiliaNumerosa(numero, camasM, camasI, literas));
        }
    }

    public Habitacion habitacionMayorCapacidad() {
        int mayor = 0;
        Habitacion hmayor = null;
        for(Habitacion hab: habitaciones) {
            if (hab.capacidad() > mayor) {
                hmayor = hab;
                mayor = hab.capacidad();
            }
        }
        return hmayor;
    }
}
