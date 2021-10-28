require_relative 'sorpresa.rb'
module CivitasRB
  class SorpresaPorJugador < Sorpresa
    attr_accessor  :valor
    #Constructores por defecto y con parametro asdfas
    def initialize(valor,texto)
      super(texto)
      @valor = valor
    end

    def aplicarAJugador(act,todos)
      if(self.jugadorCorrecto(act, todos))
        self.informe(act,todos)
        todos.each_with_index do |jugador,index|
          if index==act
            jugador.modificarSaldo(@valor*(-1)*(todos.length-1))
          else
            jugador.modificarSaldo(@valor)
          end     
        end
      end
    end

   def to_s
      return super.to_s + " valor: " + @valor  +  " "
    end
    
  end
end