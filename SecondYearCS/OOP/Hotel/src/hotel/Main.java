package hotel;

public class Main {
    
    public static void main(String[] args) {
        // Creación de un hotel con su director, tres habitaciones normales y dos habitaciones familia numerosa
        Director dire = new Director("El Director", 95800);
        Hotel hotel = new Hotel("Granada", "C/ Martínez Molina, nº 13", 5);
        hotel.setDirige(dire);
        hotel.añadirHabitacion(101, 1, 2);
        hotel.añadirHabitacion(202, 0, 2);
        hotel.añadirHabitacion(103, 0, 3);
        hotel.añadirHabitacionFamiliaNumerosa(301, 1, 0, 2);
        hotel.añadirHabitacionFamiliaNumerosa(302, 1, 0, 4);
        
        // Creación e inicialización de la vista
        HotelVista vista = new HotelVista(hotel.getHabitaciones());
        vista.setHotel(hotel);
    }    
}
