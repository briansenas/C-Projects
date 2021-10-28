require_relative 'sorpresa.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class Casilla
    attr_accessor :nombre, :tituloPropiedad
    def initialize(nombre)
      @nombre = nombre
    end

   def jugadorCorrecto(act,todos)
      act >=0 && act < todos.length
    end
    
    def to_s
     res = "\nCasilla: " + @nombre
     return res
    end
    
    #Informar al diario de la ocurrencia 
    def informe(act,todos)
      if self.jugadorCorrecto(act,todos)
        Diario.instance.ocurre_evento("Jugador: " + 
                    todos.at(act).nombre + self.to_s)
      end
    end
    
    #LLamar al metodo paga impuesto de la clase jugador
    def recibeJugador(act,todos)
      raise NotImplementedError,
            "this #{self.class} doesn't respond to: "
    end

    def getTituloPropiedad
      return nil
    end
  end
end
