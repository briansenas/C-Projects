require_relative 'sorpresa.rb'
require_relative 'casilla.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class CasillaImpuesto < Casilla
    def initialize(cantidad, nombre)
      super(nombre)
      @importe = cantidad
    end

    #LLamar al metodo paga impuesto de la clase jugador
    def recibeJugador(act,todos)
      if self.jugadorCorrecto(act,todos)
        self.informe(act,todos)
        todos.at(act).pagaImpuesto(@importe)
      end
    end

   end
end
