require_relative 'sorpresa.rb'
module CivitasRB
  class SorpresaPorCasaHotel < Sorpresa
    attr_accessor :valor
    #Constructores por defecto y con parametro asdfas
    def initialize(valor,texto)
      super(texto)
      @valor = valor
    end

    def aplicarAJugador(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        arr = todos.at(act).getPropiedades();
        sum = 0
        for x in arr do
          sum += x.numCasas + x.numHoteles
        end
        todos.at(act).modificarSaldo(@valor*sum)
      end
    end

    def to_s
      return super.to_s +  " valor: " + @valor +  " "
    end
    
  end
end