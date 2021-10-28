module CivitasRB
  require_relative 'jugador.rb'
  class TituloPropiedad
    #Setters/getters para las variables privadas necesarias.
    attr_accessor :numCasas, :numHoteles, :precioCompra,
                  :precioEdificar, :nombre, :Propietario, :alquilerBase
                
    #Constructor con parámetros para inicializar las variables.
    def initialize(nom, ab, fr,hb,pc, pe,intereses_hipoteca=1.1)
      @nombre = nom
      @alquilerBase = ab
      @factorRevalorizacion = fr
      @hipotecaBase = hb
      @precioCompra = pc
      @precioEdificar = pe
      @hipotecado = false
      @Propietario = nil
      @numCasas = 0
      @numHoteles = 0
      @@factorInteresesHipoteca = intereses_hipoteca
    end
    
    #Convertimos el estado de nuestra clase en una string.
    def to_s
      "El nombre de la propiedad es " + @nombre + ". El precio base " +
        "de alquiler y hipoteca es " + @alquilerBase.to_s + "€ " + @hipotecaBase.to_s
      + "€. El factor de valorizacion es " + @factorRevaloriacion.to_s +
        ". Por ultimo el precio de compra y edificacion es " + @precioCompra.to_s
      + "€ y " + @precioEdificar.to_s + "€."
    end
    
    #Verificamos si el param Jugador es realmente el propietario.
    def esEsteElPropietario(jugador)
      return @Propietario == jugador
    end
    
    #Utlizamos la formula del juego para calcular el precio del alquiler.
    def getPrecioAlquiler
      result = 0
      if(self.propietarioEncarcelado  && !@hipotecado)
        result = @alquilerBase*(1+(@numCasas*0.5)+(@numHoteles*2.5))
      end
      return result
    end
    
    #Utilizamos la formula del juego para calcular el precio de cancelar
    #El importe de la hipoteca
    # See also getImporteHipoteca.
    def getImporteCancelarHipoteca
       return (self.getImporteHipoteca * @@factorInteresesHipoteca)
    end
    
    #Utilizamos la formula del juego para calcular el importe de hipoteca.
    def getImporteHipoteca
      @hipotecaBase*(1+(@numCasas*0.5)+(@numHoteles*2.5))
    end
    
    #Si el jugador no es el propietario de la casilla
    #Entonces debemso tramitar el alquiler.
    #see self.getPrecioAlquiler y jugador.pagaAlquiler.
    def tramitarAlquiler(jugador)
      if(self.tienePropietario)
        if !self.esEsteElPropietario(jugador)
          jugador.pagaAlquiler(self.getPrecioAlquiler)
          @Propietario.recibe(self.getPrecioAlquiler)
        end
      end
    end
    
    #Verificamos si el propietario está o no encarcelado.
    def propietarioEncarcelado
      result = false
      if @Propietario != nil
        if @Propietario.encarcelado
          result = true
        end
      end
      return result
    end
    
    def cantidadCasasHoteles
      return @numCasas + @numHoteles
    end
    
    def getPrecioVenta
     return @precioCompra*(@numCasas+5*@numHoteles)*@precioEdificar*@factorRevalorizacion
    end
    
    #Debemos derruir un numero dado de casas si tenemos más casas que 
    #el parametro dado y además somos el propietario de la casilla.
    def derruirCasas(n, jugador)
      result = false
      if self.esEsteElPropietario(jugador) && @numCasas >= n
        @numCasas -= n
        result = true
      end
      return result 
    end
    
    #Si somos el propietario y además no estamos hipotecado
    #Entonces podemos vender nuestra propiedad 
    #See also jugador.recibe()
    def vender(jugador)
      result = false
      if self.esEsteElPropietario(jugador) && !@hipotecado
        jugador.recibe(self.getPrecioVenta)
        @Propietario = nil
        @numCasas = 0
        @numHoteles = 0
        result = true
      end
      return result
    end
    
    #Si no tiene propietario, y además el jugador pasado como parámetro
    #tiene más dinero que el necesario para comprarlo ( y puedeComprar).
    #entonces este pasa a ser el propietario de la casilla.
    def comprar(jugador)
      result = false
      if !self.tienePropietario
        @Propietario = jugador
        jugador.paga(@precioCompra)
        result = true
      end
      return result
    end
    
    #Si no hemos alcanzado el máximo de casas que el jugador
    #Puede construir, entonces construimos una casa más.
    def construirCasa(jugador)
      result = false
      if self.esEsteElPropietario(jugador)
        jugador.paga(@precioEdificar)
        @numCasas += 1
        result = true
      end
      return result
    end
    
    #Misma función que construir_casa pero con hoteles.
    def construirHotel(jugador)
      result = false
      if self.esEsteElPropietario(jugador)
        jugador.paga(@precioEdificar)
        @numHoteles += 1
        result = true
      end
      return result 
    end
    
    #Si somos el propietario, podemos hipotecar neustra propiedad.
    #See also jugador.recibe y self.getImporteHipoteca.
    def hipotecar(jugador)
      result = false
      if !@hipotecado && self.esEsteElPropietario(jugador)
        @hipotecado = true
        jugador.recibe(self.getImporteHipoteca)
        result = true
      end
      return result
    end
    
    #Si somos el propietario, podemos cancelar la hipoteca
    #see also jugador.paga y self.getImporteCancelarHipoteca.
    def cancelarHipoteca(jugador)
      result = false
      if self.esEsteElPropietario(jugador) && @hipotecado
        @hipotecado = false
        jugador.paga(self.getImporteCancelarHipoteca)
        result = true
      end
      return result
    end
    
    #Verificamos si la casilla ya posee propietario o no.
    def tienePropietario
      result = false
      if @Propietario != nil
        result = true
      end
      return result
    end
    
    def actualizaPropietarioPorConversion(jugador)
      @Propietario = jugador;
    end
    
  end
end
