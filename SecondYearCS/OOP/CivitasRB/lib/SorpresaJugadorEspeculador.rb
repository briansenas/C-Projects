require_relative 'sorpresa.rb'
require_relative 'JugadorEspeculador.rb'
module CivitasRB
  class SorpresaJugadorEspeculador < Sorpresa
    attr_accessor :valor
    #Constructores por defecto y con parametro asdfas
    def initialize(valor,texto)
      super(texto)
      @valor = valor
    end

    def aplicarAJugador(act, todos)
      if(self.jugadorCorrecto(act,todos))
        self.informe(act,todos)
        newJugador = JugadorEspeculador.new(todos.get(act),@valor)
        lista = todos.get(act).getPropiedades()
        lista.each do |prop|
          prop.actualizaPropietarioPorConversion(newJugador)
        end
        todos.delete_at(act)
        todos.add(act,newJugador)
      end
    end

  end
end