module CivitasRB
  require_relative 'dado.rb'
  require_relative 'diario.rb'
  require_relative 'titulo_propiedad.rb'
  require_relative 'sorpresa.rb'
  class Jugador
    attr_accessor :PasoPorSalida, :PrecioLibertad, :SaldoInicial,
                  :nombre, :numCasillaActual, :encarcelado, :saldo,
                  :puedeComprar
                
    #Constructor con parámetros para inicializar las variabels necesarias.
    def initialize(nombre,casas_max=4,hoteles_max=4,casas_por_hotel=4,
                    precio_libertad=200,saldo_inicial=1000,paso_por_salida=1000)
      @nombre = nombre
      @numCasillaActual = 0
      @saldo = saldo_inicial
      @encarcelado = false
      @puedeComprar = true
      @ListaPropiedades = Array.new
      @salvoconducto = nil
      @@CasasMax = casas_max
      @@HotelesMax = hoteles_max
      @@CasasPorHotel = casas_por_hotel
      @@PrecioLibertad = precio_libertad
      @@PasoPorSalida = paso_por_salida
    end
    
    #Constructor de copia para copiar los valores de "otro" jugador.
    def copia(otro)
      @nombre = otro.nombre
      @numCasillaActual = otro.numCasillaActual
      @saldo = otro.saldo
      @encarcelado = otro.encarcelado
      @puedeComprar = otro.puedeComprar
      @ListaPropiedades = otro.getPropiedades()
      @salvoconducto = otro.salvoconducto
    end
    
    #Verificamos si el jugador debe ser encarcelado
    #En caso afirmativo, debemos verificar si tiene salvoconducto o no
    #En caso afirmativo, debemos utilizar-lo y no llevarlo a la carcel.
    def debeSerEncarcelado
      result = false
      if @encarcelado
        result = true
      end
      if self.tieneSalvoconducto
        result = false
        self.perderSalvoconducto
        Diario.instance.ocurre_evento("Se libra de la carcel")
      end
      return result
    end
    
    #Si debeSerEncarcelado entonces le llevamos a la carcel 
    #Además indicaremos en el diario el evento que acaba de ocurrir.
    def encarcelar(numCasillaCarcel)
      if self.debeSerEncarcelado
        self.moverACasilla(numCasillaCarcel)
        @encarcelado = true
        Diario.instance.ocurre_evento("Va a la Carcel")
      end
      return @encarcelado
    end
    
    #Si no está en la carcel, podemos entonces recibir una carta del mazo.
    #En este caso, es para obtener un salvconducto.
    def obtenerSalvoconducto(s)
      result = false
      if !@encarcelado
        @salvoconducto = s
        result = true
      end
      return result 
    end
    
    #Si tenemos que ir a la carcel, y tenemos un salvocnducto.
    #Entonces podemos utilizar neustro salvoconducto.
    def perderSalvoconducto
      @salvoconducto.usada
      @salvoconducto = nil
    end
    
    #Verificamos si realmente tenemos un salvoconducto 
   def tieneSalvoconducto
      result = false
      if @salvoconducto != nil
        result = true
      end
      return result
    end
    
   #Verificamos si estamos en condiciones para comprar casillas.
    def puedeComprarCasilla
     @puedeComprar = !@encarcelado
     return @puedeComprar
    end
    
    #Debemos modificarSaldo una cierta cantidad, en negativo ya que perdemos.
    def paga(cantidad)
      self.modificarSaldo(cantidad*(-1))
    end
    
    #Si no estamos encarcelados, debemso pagar impuestos como todos.
    #Para ello es necesario que llamemos al metodo paga.
    def pagaImpuesto(cantidad)
      result = false
      if !@encarcelado
        result = self.paga(cantidad)
      end
      return result
    end
    
    #Es una copia de pagaImpuesto, pero para alquiler.
    def pagaAlquiler(cantidad)
      result = false
      if !@encarcelado
        result = self.paga(cantidad)
      end
      return result
    end
    
    #Haremos lo mismo que cuando tenemos que pagar algo, pero en este caso
    #Modificaremos el saldo una cantidad positiva.
    def recibe(cantidad)
      result = false
      if !@encarcelado
        result = self.modificarSaldo(cantidad)
      end
      return result
    end
    
    #Método auxiliar para los métodos anteriores
    #Dónde modificamos nuestra variable saldo directamente.
    def modificarSaldo(cantidad)
      @saldo += cantidad
      return true
    end
    
    #Si no estamos encarcelados, nos movemos a una nueva casilla dada.
    #Además debemos informarlo en el diario.
    def moverACasilla(numCasilla)
      result = false
      if !@encarcelado
        @numCasillaActual = numCasilla
        @puedeComprar = false
        result = true
        Diario.instance.ocurre_evento("Movido a la casilla " + numCasilla.to_s)
      end
      return result
    end
    
    #Verificamos si tenemos más saldo que precio a pagar.
    def puedoGastar(precio)
      result = false
      if !@encarcelado
        result = @saldo >= precio
      end
     return result
    end
    
    #Verificamos si poseemos una propiedad dada.
    def existeLaPropiedad(ip)
      result = false
      if !@ListaPropiedades.empty?
        if ip >= 0 && ip < @ListaPropiedades.length
          result = true
        end
      end
      return result
    end
    
    #Si no estamos encarcelados y además existe la propiedad entonecs
    #Podemos venderla y recibir la cantidad determinada.
    def vender(ip)
      result = false
      if !@encarcelado
        if self.existerLaPropiedad(ip)
          result = @ListaPropiedades.at(ip).vender(self)
          if(result)
            @ListaPropiedades.delete_at(ip) 
            Diario.instance.ocurre_evento("Hemos vendido" + @ListaPropiedades.at(ip).nombre + " de " + @nombre)
          end
        end
      end
      return result
    end
    
    #Verificamos si poseemos alguna propiedad.
    def tieneAlgoQueGestionar
      return !@ListaPropiedades.empty?
    end
    
    #Verificamos si podemos salir de la carcel pagando.
    def puedeSalirCarcelPagando
      return (@saldo >= @PrecioLibertad)
    end
    
    #Si estamos encarcelado y podemos salir de la carcel apgando
    #entonces podemso pagar por nuestra libertad.
    def salirCarcelPagando
      result = false
      if @encarcelado && self.puedeSalirCarcelPagando
        result = self.paga(@PrecioLibertad)
        if result
          @encarcelado = false
        end
        Diario.instance.ocurre_evento("Salgo de la carcel pagando")
      end
      result
    end
    
    #Verificamos si podemos salir de la carcel tirando.
    #Además debemos informar a nuestro diario.
    def salirCarcelTirando
      Dado.instance.tirar
      if Dado.instance.salgoDeLaCarcel
        @encarcelado = false
        Diario.instance.ocurre_evento("Salgo de la Cracel tirando")
      end
      return @encarcelado
    end
    
    #Informamos que acabamos de pasar por sailda  recibimos la paga
    #determinada.
    def pasaPorSalida
      Diario.instance.ocurre_evento("Pasa por Salida")
      self.modificarSaldo(@PasoPorSalida)
      return true
    end
    
    
    #Sobreescribimos la función "ship" para que funcione con nuestra clase
    #Y además se comporte como visto en las diapositivas o el código de Java.
    # -1 < , 0 =  , 1 >
    def <=>(otro)
      @saldo <=> otro.saldo
    end
    
    
    def puedoEdificarCasa(propiedad)
      result = false
      if (self.puedoGastar(propiedad.precioEdificar) &&
          propiedad.numCasas < self.getCasasMax)
        result = true
      end
      return result
    end
    
    def construirCasa(ip)
      result = false
      if !@encarcelado
        if self.existeLaPropiedad(ip)
          propiedad = @ListaPropiedades.at(ip)
          result = self.puedoEdificarCasa(propiedad)
          if(result)
            propiedad.construirCasa(self)
            Diario.instance.ocurre_evento("El jugador " + 
              @nombre + " ha construido una casa en " + propiedad.nombre)
            @ListaPropiedades[ip] = propiedad
          else
            Diario.instance.ocurre_evento("El jugador " + @nombre + " NO HA construido una casa en " + propiedad.nombre)
          end
        end
      end
      return result
    end
    
    def puedoEdificarHotel(propiedad)
      result = false
      if (self.puedoGastar(propiedad.precioEdificar) &&
          propiedad.numHoteles < self.getHotelesMax() &&
          propiedad.numCasas >= 4)
          result = true
      end
      return result
    end
    
    def construirHotel(ip)
      result = false
      if !@encarcelado
        if self.existeLaPropiedad(ip)
          propiedad = @ListaPropiedades.at(ip)
          puedoEdificarHotel = self.puedoEdificarHotel(propiedad)
          if(puedoEdificarHotel)
            result = propiedad.construirHotel(self)
            casasPorHotel = @@CasasPorHotel
            propiedad.derruirCasas(casasPorHotel, self)
            Diario.instance.ocurre_evento("El jugador " + @nombre + 
                " construye hotel en " + propiedad.nombre)
            @ListaPropiedades[ip] = propiedad
          else
            Diario.instance.ocurre_evento("El jugador " + @nombre + " NO HA construido un hotel en " + propiedad.nombre)
          end
        end
      end
      return result
    end
    
    def comprar(titulo)
      result = false
      if !@encarcelado
        if self.puedeComprar
          precio = titulo.precioCompra
          if self.puedoGastar(precio)
            result = titulo.comprar(self)
            if(result)
              @ListaPropiedades << titulo
              Diario.instance.ocurre_evento("El jugador " + @nombre +
                  " ha comprado " + titulo.nombre)
            end
            @puedeComprar = false
          end
        end
      end 
      return result
    end
    
    def vender(ip)
      result = false
      if !@encarcelado
        if self.existeLaPropiedad(ip)
          result = @ListaPropiedades.at(ip).vender(self)
          if(result)
            Diario.instance.ocurre_evento("Hemos vendido la propiedad " +
              @ListaPropiedades.at(ip).nombre+ " del jugador " + @nombre)
           @ListaPropiedades.delete_at(ip)
          end
        end
      end
      return result
    end
    
    def hipotecar(ip)
      result = false
      if !encarcelado
        if self.existeLaPropiedad(ip)
          propiedad = @ListaPropiedades.at(ip)
          result = propiedad.hipotecar(self)
          if(result)
            Diario.instance.ocurre_evento("El jugador " + @nombre +
              " hipoteca la propiedad " + propiedad.nombre)
          end
        end
      end
      return result
    end

    def cancelarHipoteca(ip)
      result = false
      if !@encarcelado
        if self.existeLaPropiedad(ip)
          propiedad = @ListaPropiedades.at(ip)
          cantidad = propiedad.getImporteCancelarHipoteca()
          if(self.puedoGastar(cantidad))
            result = propiedad.cancelarHipoteca(self)
            if(result)
              Diario.instance.ocurre_evento("El jugador " + @nombre +
                  " a cancelado la hipoteca de " + propiedad.nombre)
            end
          end
        end
      end
      return result
    end

    def getCasasMax()
      return @@CasasMax
    end

    def getHotelesMax()
      return @@HotelesMax
    end

    def enBancarrota
      return @saldo <= 0
    end

    def getPropiedades
      return @ListaPropiedades
    end

    def to_s
      res = "Jugador: " + @nombre + " saldo: " + @saldo.to_s 
      if(@ListaPropiedades != nil)
        res += "\nPropiedades:"
        @ListaPropiedades.each do |prop|
          res += "\n\t" + prop.nombre
          res += " casas: " + prop.numCasas.to_s
          res += " hoteles: " + prop.numHoteles.to_s
        end
      end
      return res
    end
    
  end
end