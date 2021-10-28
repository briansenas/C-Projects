require_relative 'sorpresa.rb'
require_relative 'tipo_sorpresa.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'tipo_casilla.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
module CivitasRB
  class Casilla
    attr_accessor :nombre, :tituloPropiedad
    def initialize(args)
      args = defaults.merge(args)
      @nombre = args[:nombre]
      @importe = args[:importe]
      @carcel = args[:carcel]
      @sorpresa = args[:sorpresa]
      @tituloPropiedad = args[:tituloPropiedad]
      @mazo = args[:mazo]
      @tipo = args[:tipo]
      if @tituloPropiedad != nil
        @nombre = @tituloPropiedad.nombre
        @tipo = TipoCasilla::CALLE
      end
      if @importe != 0
        @tipo = TipoCasilla::IMPUESTO        
      end
      if @carcel != 0
        @tipo = TipoCasilla::JUEZ
      end
      if @mazo != nil
        @tipo = TipoCasilla::SORPRESA
      end
      if @tipo == nil
        @tipo = TipoCasilla::DESCANSO
      end
    end
    
    def defaults
      {:nombre => "", :importe => 0, :carcel => 7,
        :mazo => nil, :sorpresa => nil, :tipo => nil, :tituloPropiedad => nil
      }
    end
    
    def jugadorCorrecto(act,todos)
      act >=0 && act < todos.length
    end
    
    def to_s
     res = "\nCasilla: " + @nombre
     if(@tituloPropiedad != nil)
       res += " con: " + "\n 1- precioCompra: " + @tituloPropiedad.precioCompra.to_s +
         "\n 2- precioEdificación: " + @tituloPropiedad.precioEdificar.to_s +
         "\n 3- AlquilerBase: " + @tituloPropiedad.alquilerBase.to_s
     end
     return res
    end
    
    #Informar al diario de la ocurrencia 
    def informe(act,todos)
      if self.jugadorCorrecto(act,todos)
        Diario.instance.ocurre_evento("Jugador: " + 
                    todos.at(act).nombre + self.to_s)
      end
    end
    
    #LLamar al metodo paga impuesto de la clase jugador
    def recibeJugador_impuesto(act,todos)
      if self.jugadorCorrecto(act,todos)
        self.informe(act,todos)
        todos.at(act).pagaImpuesto(@importe)
      end
    end
    
    #Encarcelar al jugador 
    #Pre-Condicion, asegurar que la instancia esta bien
    #inicializada en la clase tablero. (sorpresa!=nil)
    def recibeJugador_juez(act,todos)
      if self.jugadorCorrecto(act,todos)
        self.informe(act,todos)
        todos.at(act).encarcelar(@carcel)
      end
    end
    
    def recibeJugador_calle(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        jugadorActual = todos.at(act)
        if !@tituloPropiedad.tienePropietario
          if jugadorActual.puedeComprarCasilla
            @tituloPropiedad.tramitarAlquiler(jugadorActual)
          end
        end
      end
    end
    
    def recibeJugador_sorpresa(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        sorpresa = @mazo.siguiente()
        sorpresa.aplicarAJugador(act,todos)
      end
    end
    
    def recibeJugador(act,todos)
      case @tipo
      when TipoCasilla::CALLE
        recibeJugador_calle(act,todos)
      when TipoCasilla::IMPUESTO
        recibeJugador_impuesto(act,todos)
      when TipoCasilla::JUEZ
        recibeJugador_juez(act,todos)
      when TipoCasilla::SORPRESA
        recibeJugador_sorpresa(act,todos)
      else
        self.informe(act,todos)
      end
    end

    def getTituloPropiedad
      return @tituloPropiedad
    end
  end
end
