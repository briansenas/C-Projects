require_relative 'sorpresa.rb'
module CivitasRB
  class SorpresaIrCarcel < Sorpresa
    attr_accessor :valor
    #Constructores por defecto y con parametro asdfas
    def initialize(tablero, texto)
      super(texto)
      @tablero = tablero
      @valor = tablero.numCasillaCarcel
    end

    #Informamos al diario y le enviamos a la casilla adecuada.
    def aplicarAJugador(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        todos.at(act).encarcelar(@valor)
      end
    end

    def to_s
      return super.to_s + " casilla: " + @valor +  " "
    end
    
  end
end