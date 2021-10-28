package civitas;

import java.util.ArrayList;

public class Diario {
  static final private Diario instance = new Diario(); //Singleton
  
  private ArrayList<String> eventos; //creamos una lista de los eventos
  
  static public Diario getInstance() {
    return instance;
  }
  
  //Constructor sin parámetros
  private Diario () {
    eventos = new ArrayList<>();
  } 
  
  /**
   * @brief Añadimos un evento a @b this.eventos
   * @param e evento a añadir
   */
  void ocurreEvento (String e) {
    eventos.add (e);
  }
  
  /**
   * @brief verificamos si aún queda eventos en @b this.eventos
   * @return verdadero/falso
   */
  public boolean eventosPendientes () {
    return !eventos.isEmpty();
  }
  
  /**
   * @brief Leemos el primer evento de @b this.eventos ( FIFO )
   * @return string nombre evento
   */
  public String leerEvento () {
    String salida = "";
    if (!eventos.isEmpty()) {
      salida = eventos.remove(0);
    }
    return salida;
  }
}
