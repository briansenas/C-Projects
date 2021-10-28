require_relative 'sorpresa.rb'
require_relative 'casilla.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class CasillaDescanso < Casilla
    def initialize(nombre)
      super(nombre)
    end

    def recibeJugador(act, todos)
      self.informe(act, todos)
    end

  end
end
