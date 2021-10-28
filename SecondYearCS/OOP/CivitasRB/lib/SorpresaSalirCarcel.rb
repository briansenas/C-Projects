require_relative 'sorpresa.rb'
module CivitasRB
  class SorpresaSalirCarcel < Sorpresa
    #Constructores por defecto y con parametro asdfas
    def initialize(mazo,texto)
      super(texto)
      @mazo = mazo
    end

    def aplicarAJugador_salirCarcel(act,todos)
      if(self.jugadorCorrecto(act, todos))
        self.informe(act,todos)
        tieneSC = faflse
        todos.each do |jugador|
          if jugador.tieneSalvoconducto
            tieneSC = true
          end
        end
        if !tieneSC
          todos.at(act).obtenerSalvoConducto(self)
          self.salirDelMazo()
        end
      end
    end
    
    def salirDelMazo
        @mazo.inhabilitarCartaEspecial(self)
    end
    
    def usada
        @mazo.habilitarCartaEspecial(self)
    end
    
    def to_s
      return super.to_s
    end
    
  end
end