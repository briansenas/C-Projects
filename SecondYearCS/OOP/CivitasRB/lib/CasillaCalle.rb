require_relative 'sorpresa.rb'
require_relative 'casilla.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class CasillaCalle < Casilla
    def initialize(tituloPropiedad,nombre)
      super(nombre)
      @tituloPropiedad = tituloPropiedad
    end

    def recibeJugador(act, todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act, todos)
        jugadorActual = todos.at(act)
        if !@tituloPropiedad.tienePropietario
          if jugadorActual.puedeComprarCasilla
            @tituloPropiedad.tramitarAlquiler(jugadorActual)
          end
        end
      end
    end

    def getTituloPropiedad
      return @tituloPropiedad
    end


    def to_s
      res = super.to_s
      if (@tituloPropiedad != nil)
        res += " con: " + "\n 1- precioCompra: " + @tituloPropiedad.precioCompra.to_s +
            "\n 2- precioEdificación: " + @tituloPropiedad.precioEdificar.to_s +
            "\n 3- AlquilerBase: " + @tituloPropiedad.alquilerBase.to_s
      end
      return res
    end

  end
end
