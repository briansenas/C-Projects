require_relative 'respuestas.rb'
require_relative 'gestiones_inmobiliarias.rb'
require_relative 'salidas_carcel.rb'
require_relative 'operacion_inmobiliaria'
module CivitasRB
  class Controlador
    def initialize(juego,vista)
      @juego = juego
      @vista = vista
      @Respuestas = [Respuestas::SI, Respuestas::NO]
      @GestionesInmobiliarias = [GestionesInmobiliarias::VENDER,
        GestionesInmobiliarias::HIPOTECAR, GestionesInmobiliarias::CANCELAR_HIPOTECA,
        GestionesInmobiliarias::CONSTRUIR_CASA, GestionesInmobiliarias::CONSTRUIR_HOTEL,
        GestionesInmobiliarias::TERMINAR
      ]
      @SalidasCarcel = [SalidasCarcel::PAGANDO,SalidasCarcel::TIRANDO]
    end
    
   
    def juega
      @vista.setCivitasJuego(@juego)
      while !@juego.finalDelJuego()
        @vista.actualizarVista
        @vista.pausa
        operacion = @juego.siguientePaso
        @vista.mostrarSiguienteOperacion(operacion)
        if(operacion==Operaciones_juego::PASAR_TURNO)
          @vista.mostrarEventos()
        end
        if(!@juego.finalDelJuego())
          case operacion
          when Operaciones_juego::COMPRAR
            res = @vista.comprar()
            if(res==Respuestas::SI)
              @juego.comprar
            end
            @juego.siguientePasoCompletado(operacion)
          when Operaciones_juego::GESTIONAR
            @vista.gestionar()
            gestion = @GestionesInmobiliarias[@vista.getGestion]
            oper = OperacionInmobiliaria.new(gestion, @vista.getPropiedad)
            case gestion
            when GestionesInmobiliarias::VENDER
              @juego.vender(@vista.getPropiedad)
            when GestionesInmobiliarias::HIPOTECAR
              @juego.hipotecar(@vista.getPropiedad)
            when GestionesInmobiliarias::CANCELAR_HIPOTECA
              @juego.cancelarHipoteca(@vista.getPropiedad)
            when GestionesInmobiliarias::CONSTRUIR_CASA
              @juego.construirCasa(@vista.getPropiedad)
            when GestionesInmobiliarias::CONSTRUIR_HOTEL
              @juego.construirHotel(@vista.getPropiedad)
            when GestionesInmobiliarias::TERMINAR
              @juego.siguientePasoCompletado(operacion)
            end
          when Operaciones_juego::SALIR_CARCEL
            @vista.salirCarcel()
            @juego.siguientePasoCompletado(operacion)
          end
        else
          puts "JUEGO FINALIZADO... EL RANKING ES ="
          @juego.ranking.each do |jugador|
            puts jugador.to_s
          end
        end
      end
    end
  end
end
