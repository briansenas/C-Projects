require_relative 'sorpresa.rb'
module CivitasRB
  class SorpresaIrCasilla < Sorpresa
    attr_accessor :valor
    #Constructores por defecto y con parametro asdfas
    def initialize(tablero,valor,texto)
      super(texto)
      @tablero = tablero
      @valor = valor
    end

    #Informamos al diario, calculamos e informamos de posibles
    #Pasos por salida y por ultimo cambiamos la posicion del jugador
    def aplicarAJugador(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act, todos)
        origen = todos.at(act).numCasillaActual
        destino = @tablero.calcularTirada(origen, @valor)
        pos = @tablero.nuevaPosicion(origen, destino)
        todos.at(act).moverACasilla(pos)
        @tablero.getCasilla(pos).recibeJugador(act,todos)
      end
    end
    
    def to_s
      return super.to_s + " casilla: " + @valor +  " "
    end
    
  end
end