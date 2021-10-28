module CivitasRB
  class Sorpresa
    attr_accessor :texto
    #Constructores por defecto y con parametro asdfas
    def initialize(nombre)
      @texto = nombre
    end
    
    #Verificamos si el primer parametro es válido para el segundo
    def jugadorCorrecto(act, todos)
      return (act>=0 && act < todos.size)
    end
    
    #Informamos al diario de la aplicación de una sorpresa
    def informe(act,todos)
      if self.jugadorCorrecto(act, todos)
        Diario.instance.ocurre_evento("Aplicando Sorpresa " +
                @tipo.to_s + " a " + todos.at(act).nombre)
      end
    end
    
    #Diferenciamos los distintos tipos de sorpresas
    def aplicarAJugador(act, todos)
      raise NotImplementedError,
            "this #{self.class} doesn't respond to: "
    end
    
    def to_s
      return "Sorpresa: " + @texto +  " "
    end
    
  end
end