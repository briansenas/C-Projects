module CivitasRB
  require_relative 'casilla.rb'
  class Tablero
    #Setter/getters de las variables privadas necesarias.
    attr_accessor :numCasillaCarcel, :tieneJuez
    #Constructor con parámetro.
    def initialize(numCasillaCarcel)
      if numCasillaCarcel >= 1
        @numCasillaCarcel = numCasillaCarcel
      else
        @numCasillaCarcel = 1
      end
      @casillas = Array.new()
      @casillas << (CasillaDescanso.new("Salida"))
      @porSalida = 0
      @tieneJuez = false
    end
    
    #Verificamos si ya hemos añadido la casillaCarcel.
    def correcto()
      result = false
      if(@casillas.length > @numCasillaCarcel && @tieneJuez)
        result = true
      end
      return result
    end
    
    #Verificamos si self.jugadorCorrecto() y además si el parámetro dado 
    #Está dentro del rango del array @casillas.
    def is_correcto(numCasilla)
      return (self.correcto() && numCasilla >= 0 && numCasilla < @casillas.length)
    end
    
    #Decrementamos el valor de PorSalida y devuelvemos su valor;
    def getPorSalida()
      if(@porSalida>0)
        @porSalida -= 1
      end
      return @porSalida
    end
    
    #Añadimos una casillas nueva pero siempre verificamos si ya 
    #deberiamos añádir la casilla carcel.
    def anadeCasilla(casilla)
      if @casillas.length == @numCasillaCarcel
          @casillas << CasillaDescanso.new("Carcel")
      else
        @casillas << casilla
      end
      if @casillas.length == @numCasillaCarcel
           @casillas << CasillaDescanso.new("Carcel")
      end
    end
    
    #Si aún no hemos añadido el juez, debemos hacerlo ahora.
    def anadeJuez
      if !@tieneJuez
        @casillas << CasillaJuez.new(@numCasillaCarcel,"Juez")

      end
      @tieneJuez = true
    end
    
    #Si self.is_jugadorCorrecto() enteonces podemos devolver esa casilla.
    def getCasilla(numCasilla)
      if self.is_correcto(numCasilla)
        return @casillas.at(numCasilla)
      else
        return nil
      end
    end
    
    def getCasillas()
      result = Array.new
      if(self.correcto)
        result = @casillas
      end
      return result
    end
    
    #Tras tirar el dado ( param tirada ) debemos calcualr la nueva posicion
    #sumando a la actual el valor tirada. Pero debe estar dentro del tablero
    #Para asegurar eso, podemos utilizar la operación modulus.
    def nuevaPosicion(actual, tirada)
      new = -1
      if self.correcto 
        new = ( actual + tirada ) % @casillas.length
      end 
      if new != actual + tirada
        @porSalida += 1 
      end
      return new
    end
    
    #Calculamos cuanto debemos sacar para llegar a cierto destino+
    def calcularTirada(origen, destino)
      result = destino - origen 
      while result < 0
        result += @casillas.length
      end
      if result > @casillas.length
        result = result % @casillas.length
      end
      return result
    end
    
  end
end 
