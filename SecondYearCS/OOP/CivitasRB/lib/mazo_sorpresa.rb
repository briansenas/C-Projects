module CivitasRB
  require_relative 'sorpresa.rb'
  require_relative 'tipo_sorpresa.rb'
  class MazoSorpresa
    #Setter/getters de las variables privadas necesarias.
    attr_accessor :barajada, :usadas, :debug, :ultimaSorpresa 
    #Constructor con parámetro con valor por defecto
    def initialize(debug=false)
      @ultimaSorpresa = 0
      @barajada = false
      @usadas = 0
      @debug = debug
      if @debug 
        Diario.instance.ocurre_evento("Debug Activated in Mazo")
      end
      @sorpresas = Array.new
      @cartasEspeciales = Array.new
    end
    
    #Si no hemos barajado el mazo, podemos seguir añadiendo cartas.
    def alMazo(s)
      if !@barajado
        @sorpresas << s
      end
    end
    
    #Si no hemos barajado el mazo, o ya hemos utilizado todas las cartas
    #Entonces debemos barajar el mazo y luego sacar una de las cartas
    #Si ya estabamos jugando, entonces simplemente sacamos la siguiente
    #carta
    def siguiente
      if ( !@barajado || @sopresas.length == @usadas ) && !@debug
        @sorpresas = @sorpresas.shuffle #Contrario al .sort
        @usadas = 0
        @barajada = true
      end
      @usadas += 1
      @ultimaSorpresa = @sorpresas.at(0)
      @sorpresas.delete_at(0)
      @sorpresas << @ultimaSorpresa
      return @ultimaSorpresa
    end
    
    #Si tenemos en la baraja una carta "s", entonces debemos quitarla
    #Y añadirla en la baraja de cartasEspeciales.
    def inhabilitarCartaEspecial(s)
      if @sorpresas.include?(s)
        @sorpresas.delete(s)
        @cartasEspeciales << s
        Diario.instance.ocurre_evento("Hemos desactivado una carta especial")
      end
    end
    
    #Verificamos si cartasEspeciales posee una carta "s", en caso
    #afirmativo debemos quitarle esa carta y añadirle a nuestra baraja normal.
    def habilitarCartaEspecial(s)
      if @cartasEspeciales.include?(s)
        @cartasEspeciales.delete(s)
        @sorpresas << s
        Diario.instance.ocurre_evento("Hemos activado una carta especial")
      end
    end
    
  end
end
