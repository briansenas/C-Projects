require_relative 'jugador.rb'
require_relative 'gestor_estados.rb'
require_relative 'mazo_sorpresa.rb'
require_relative 'CasillaDescanso.rb'
require_relative 'CasillaSorpresa.rb'
require_relative 'CasillaCalle.rb'
require_relative 'CasillaImpuesto.rb'
require_relative 'CasillaJuez.rb'
require_relative 'SorpresaPagarCobrar.rb'
require_relative 'SorpresaJugadorEspeculador.rb'
require_relative 'SorpresaIrCasilla.rb'
require_relative 'SorpresaPorCasaHotel.rb'
require_relative 'SorpresaPorJugador.rb'
require_relative 'SorpresaSalirCarcel.rb'
require_relative 'SorpresaIrCarcel.rb'
require_relative 'titulo_propiedad.rb'
require_relative 'diario.rb'
require_relative 'dado.rb'
require_relative 'tablero.rb'
require_relative 'operaciones_juego.rb'
module CivitasRB
  class CivitasJuego
   
    def initialize(args)
      @jugadores = Array.new 
      args.each do |n|
        @jugadores << Jugador.new(n)
      end
      @indiceJugadorActual = Dado.instance.quienEmpieza(@jugadores.length)
      @gestorEstados = Gestor_estados.new
      @estado = @gestorEstados.estado_inicial
      @mazo = MazoSorpresa.new
      @@tabSize = 6
      self.inicializaTablero
      self.inicializaMazoSorpresa
    end
    
   
    
    #Estoy mas perdido que estefania
    def inicializaTablero
     @tablero = Tablero.new(@@tabSize)
     i = 1
     loop do
       if(i==3 ||i == 13 ||i == 18)
         @tablero.anadeCasilla(CasillaSorpresa.new(@mazo,"Sorpresa"))
       elsif(i==6)
         #nothing
       elsif(i==8)
         @tablero.anadeCasilla(CasillaImpuesto.new( 0.15*1000,"Impuesto"))
       elsif(i==11)
         @tablero.anadeCasilla(CasillaDescanso.new("Parking"))
       elsif(i==16)
         @tablero.anadeJuez()
       elsif(i==20)
         break
       else
         @tablero.anadeCasilla(CasillaCalle.new(TituloPropiedad.new("Calle"+ i.to_s,25+i*25,0.5+i*0.1,40+i*5,40+i*20,60+i*5),"CasillaCalle"))
       end
       i+=1
     end
    end
    
    def inicializaMazoSorpresa
      @mazo.alMazo(SorpresaIrCasilla.new(@tablero,10,"IrCasilla"))
      @mazo.alMazo(SorpresaIrCasilla.new(@tablero,3,"IrCasilla"))
      @mazo.alMazo(SorpresaJugadorEspeculador.new("ConvertirAJugadorMafioso",300))
      @mazo.alMazo(SorpresaJugadorEspeculador.new("ConvertirAJugadorEntrepeneu",150))
      @mazo.alMazo(SorpresaIrCarcel.new(@tablero,"IrACarcelPringao"))
      @mazo.alMazo(SorpresaIrCarcel.new(@tablero,"IrACarcelPringao2"))
      @mazo.alMazo(SorpresaPagarCobrar.new(75,"PagarCobrar"))
      @mazo.alMazo(SorpresaSalirCarcel.new(@mazo,"PorChivato"))
      @mazo.alMazo(SorpresaSalirCarcel.new(@mazo,"ErrorPapeleo"))
      @mazo.alMazo(SorpresaPorCasaHotel.new(10,"APagarImpuesto"))
      @mazo.alMazo(SorpresaPorCasaHotel.new(10,"ErrorImpuesto"))
      @mazo.alMazo(SorpresaPorJugador.new(30,"HasGanadoAlPoker"))
      @mazo.alMazo(SorpresaPorJugador.new(-30,"HasPerdidoAlPoker"))
    end
    
    def contabilizarPasosPorSalida(jugadorActual)
      while @tablero.getPorSalida > 0
        jugadorActual.pasaPorSalida
      end
    end
    
    def pasarTurno()
      @indiceJugadorActual += 1
      if(@indiceJugadorActual >= @jugadores.length)
        @indiceJugadorActual = 0;
      end
    end
    
    #Ni zorra de lo que hay que hacer aqui, me he inventado
    #EL atributo estado y bueno ahi va 
    def siguientePasoCompletado(operacion)
      @estado = @gestorEstados.siguiente_estado(@jugadores[@indiceJugadorActual], @estado, operacion)
    end
    
    #Para implementar este hay que implementarlos en la 
    #clase jugador ( Verificar si funciona allí )
    def construirCasa(ip)
      @jugadores[@indiceJugadorActual].construirCasa(ip)
    end
    
    def construirHotel(ip)
      @jugadores[@indiceJugadorActual].construirHotel(ip)
    end
    
    def vender(ip)
      @jugadores[@indiceJugadorActual].vender(ip)
    end
    
    def hipotecar(ip)
      @jugadores[@indiceJugadorActual].hipotecar(ip)
    end

    def cancelarHipoteca(ip)
      @jugadores[@indiceJugadorActual].cancelarHipoteca(ip)
    end
    
    def salirCarcelPagando()
      @jugadores[@indiceJugadorActual].salirCarcelPagando()
    end
    
    def salirCarcelTirando()
      @jugadores[@indiceJugadorActual].salirCarcelTirando()
    end
    
    #Me he inventado el bucle for, igual tengo suerte
    def finalDelJuego()
      for player in @jugadores do
        if ( player.enBancarrota() )
          return true
        end
      end
      return false
    end
    
    def ranking
      return @jugadores.sort.reverse #Ni idea si funcionará o no, tengo fé
    end
    
    def avanzaJugador()
      jugadorActual = @jugadores.at(@indiceJugadorActual)
      posicionActual = jugadorActual.numCasillaActual
      tirada = Dado.instance.tirar
      posicionNueva = @tablero.nuevaPosicion(posicionActual, tirada)
      casilla = @tablero.getCasilla(posicionNueva)
      self.contabilizarPasosPorSalida(jugadorActual)
      jugadorActual.moverACasilla(posicionNueva)
      casilla.recibeJugador(@indiceJugadorActual,@jugadores)
      self.contabilizarPasosPorSalida(jugadorActual)
    end
    
    def siguientePaso()
      jugadorActual = @jugadores.at(@indiceJugadorActual)
      operacion = @gestorEstados.operaciones_permitidas(jugadorActual, @estado)
      if(operacion==Operaciones_juego::PASAR_TURNO)
        self.pasarTurno
        self.siguientePasoCompletado(operacion)
      end
      if(operacion==Operaciones_juego::AVANZAR)
        self.avanzaJugador
        self.siguientePasoCompletado(operacion)
      end
      return operacion
    end
    
    def comprar()
      jugadorActual = @jugadores.at(@indiceJugadorActual)
      numCasillaActual = jugadorActual.numCasillaActual
      casilla = @tablero.getCasilla(numCasillaActual)
      titulo = casilla.tituloPropiedad
      result = jugadorActual.comprar(titulo)
      return result
    end

    def getJugador
      return @jugadores.at(@indiceJugadorActual)
    end

    def getCasillaActual
      numCasillaActual =  @jugadores.at(@indiceJugadorActual).numCasillaActual
      return @tablero.getCasilla(numCasillaActual)
    end

  end
end
