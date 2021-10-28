require_relative 'sorpresa.rb'
require_relative 'casilla.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class CasillaJuez < Casilla
    def initialize(numCasillaCarcel, nombre)
      super(nombre)
      @carcel = numCasillaCarcel
    end
    #Encarcelar al jugador
    #Pre-Condicion, asegurar que la instancia esta bien
    #inicializada en la clase tablero. (sorpresa!=nil)
    def recibeJugador(act,todos)
      if self.jugadorCorrecto(act,todos)
        self.informe(act,todos)
        todos.at(act).encarcelar(@carcel)
      end
    end

    def to_s
      res = super.to_s
      res += " en la casilla " + @carcel.to_s
      return res
    end

  end
end
