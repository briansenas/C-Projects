module CivitasRB
  require_relative "tipo_sorpresa.rb"
  class Sorpresa
    attr_accessor :texto, :valor, :tipo
    #Constructores por defecto y con parametro asdfas
    def initialize(args)
      @texto = args.fetch(:nombre,"")
      @valor = args.fetch(:valor, -1)
      @tipo = args.fetch(:tipo, nil)
      @mazo = args.fetch(:mazo, nil)
      @tablero = args.fetch(:tablero, nil)
      if @tablero && @valor == -1
        @valor = @tablero.numCasillaCarcel
        @texto = "Ir_a_carcel"
        @tipo = TipoSorpresa::IRCARCEL
      end
      if @tablero && @valor != -1
         @texto = "Ir_a_casilla_" + @valor.to_s
         @tipo = TipoSorpresa::IRCASILLA
      end
      if @mazo
        @mazo.habilitarCartaEspecial(TipoSorpresa::SALIRCARCEL)
        @tipo = TipoSorpresa::SALIRCARCEL
        @texto = "Salir_carcel"
      end
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
      if self.jugadorCorrecto(act, todos)
        case @tipo
        when CivitasRB::TipoSorpresa::IRCARCEL
          aplicarAJugador_irCarcel(act,todos)
        when CivitasRB::TipoSorpresa::IRCASILLA
          aplicarAJugador_irACasilla(act,todos)
        when CivitasRB::TipoSorpresa::PAGARCOBRAR
          aplicarAJugador_pagarCobrar(act,todos)
        when CivitasRB::TipoSorpresa::PORCASAHOTEL
          aplicarAJugador_porCasaHotel(act,todos)
        when CivitasRB::TipoSorpresa::PORJUGADOR
          aplicarAJugador_porJugador(act,todos)
        else
          self.informe(act,todos)
        end       
      end
    end
    
    #Informamos al diario y le enviamos a la casilla adecuada.
    def aplicarAJugador_irCarcel(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        todos.at(act).encarcelar(@valor)
      end
    end
    
    #Informamos al diario, calculamos e informamos de posibles
    #Pasos por salida y por ultimo cambiamos la posicion del jugador
    def aplicarAJugador_irACasilla(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act, todos)
        origen = todos.at(act).numCasillaActual
        destino = @tablero.calcularTirada(origen, @valor)
        pos = @tablero.nuevaPosicion(origen, destino)
        todos.at(act).moverACasilla(pos)
        @tablero.getCasilla(pos).recibeJugador(act,todos)
      end
    end
    
    #Modificamos el saldo del jugador según el valor indicado
    def aplicarAJugador_pagarCobrar(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        todos.at(act).modificarSaldo(@valor)
      end
    end
    
    
    def aplicarAJugador_porCasaHotel(act,todos)
      if self.jugadorCorrecto(act, todos)
        self.informe(act,todos)
        arr = todos.at(act).getPropiedades();
        sum = 0
        for x in arr do
          sum += x.numCasas + x.numHoteles
        end
        todos.at(act).modificarSaldo(@valor*sum)
      end
    end
    
    def aplicarAJugador_porJugador(act,todos)
      if(self.jugadorCorrecto(act, todos))
        self.informe(act,todos)
        sorpresa_nueva = Sorpresa.new(:tipo => TipoSorpresa::PAGARCOBRAR,:valor => @valor*(-1),:nombre => "PAGARCOBRAR")
        todos.each_with_index do |jugador,index|
          if index==act
            jugador.modificarSaldo(sorpresa_nueva.valor*(-1)*(todos.length-1))
          else
            jugador.modificarSaldo(sorpresa_nueva.valor)
          end     
        end
      end
    end
    
    def aplicarAJugador_salirCarcel(act,todos)
      if(self.jugadorCorrecto(act, todos))
        self.informe(act,todos)
        tieneSC = faflse
        sorpresa_nueva = Sorpresa.new(:tipo => TipoSorpresa::SALIRCARCEL,:mazo => @mazo)
        todos.each do |jugador|
          if jugador.tieneSalvoconducto
            tieneSC = true
          end
        end
        if !tieneSC
          todos.at(act).obtenerSalvoConducto(sorpresa_nueva)
          self.salirDelMazo()
        end
      end
    end
    
    def salirDelMazo
      if(@tipo == TipoSorpresa::SALIRCARCEL)
        @mazo.inhabilitarCartaEspecial(self)
      end
    end
    
    def usada
      if @tipo == TipoSorpresa::SALIRCARCEL
        @mazo.habilitarCartaEspecial(self)
      end
    end
    
    def to_s
      return "Sorpresa: " + @texto +  " "
    end
    
  end
end