  require 'singleton'
module CivitasRB
    class Dado
    include Singleton #Singleton
    
    def initialize(salida_carcel=5) #Constructor con parámetros.
       @debug = false
       @ultimo_resultado = 0
       @@SalidaCarcel = salida_carcel
    end
    
    #Generamos un número aleatorio entre 1-6 con rand
    #ultimoResultado guarda ese resultado
    def tirar
      if !@debug
        @ultimo_resultado = rand(1..6)
      else
        @ultimo_resultado = 1
      end
      @ultimo_resultado
    end
    
    #Verificamos si el ultimoResultado es mayor que lo necesario para salr 
    #De la carcel.
    def salgoDeLaCarcel
      self.tirar
      salir = false
      if @ultimo_resultado >= @@SalidaCarcel
        salir = true
      end
      return salir
    end
    
    #Generamos un número aleatorio entre 0-(n-1) para saber quien empieza.
    def quienEmpieza(n)
      return rand(n)
    end
    
    #Empezamos a depurar nuestro dado.
    #Además escribimos el evento en nuestro diario.
    def setDebug(d)
      @debug = d
      Diario.instance.ocurre_evento("Debug is activated in Dado")
    end
    
    def ultimoResultado
      return @ultimoResultado
    end
    
  end
end 