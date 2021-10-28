require_relative 'sorpresa.rb'
require_relative 'casilla.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class CasillaSorpresa < Casilla
    def initialize(mazo,nombre)
      super(nombre)
      @mazo = mazo
    end

    def recibeJugador(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        sorpresa = @mazo.siguiente()
        sorpresa.aplicarAJugador(act,todos)
      end
    end

  end
end
