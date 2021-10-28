require_relative 'sorpresa.rb'
module CivitasRB
  class SorpresaPagarCobrar < Sorpresa
    attr_accessor :valor
    #Constructores por defecto y con parametro asdfas
    def initialize(valor,texto)
      super(texto)
      @valor = valor
    end

    #Modificamos el saldo del jugador según el valor indicado
    def aplicarAJugador(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        todos.at(act).modificarSaldo(@valor)
      end
    end
    
    def to_s
      return super.to_s +  " valor: " + @valor +  " "
    end
    
  end
end