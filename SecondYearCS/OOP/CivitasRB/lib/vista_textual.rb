#encoding:utf-8
require_relative 'operaciones_juego'
require_relative 'respuestas.rb'
require_relative 'gestiones_inmobiliarias.rb'
require_relative 'salidas_carcel.rb'
require_relative 'civitas_juego.rb'
require 'io/console'
module CivitasRB
  class VistaTextual
    
    def initialize()
      @iGestion = -1
      @iPropiedad = -1
      @juegoModel = nil
      @Respuestas = [Respuestas::SI, Respuestas::NO]
      @GestionesInmobiliarias = [GestionesInmobiliarias::VENDER,
        GestionesInmobiliarias::HIPOTECAR, GestionesInmobiliarias::CANCELAR_HIPOTECA,
        GestionesInmobiliarias::CONSTRUIR_CASA, GestionesInmobiliarias::CONSTRUIR_HOTEL,
        GestionesInmobiliarias::TERMINAR
      ]
      @SalidasCarcel = [SalidasCarcel::PAGANDO,SalidasCarcel::TIRANDO]
    end

    def mostrar_estado(estado)
      puts estado
    end

    
    def pausa
      print "Pulsa una tecla"
      STDIN.getch
      print "\n"
    end

    def lee_entero(max,msg1,msg2)
      ok = false
      begin
        print msg1
        cadena = gets.chomp
        begin
          if (cadena =~ /\A\d+\Z/)
            numero = cadena.to_i
            ok = true
          else
            raise IOError
          end
        rescue IOError
          puts msg2
        end
        if (ok)
          if (numero >= max)
            ok = false
          end
        end
      end while (!ok)

      return numero
    end



    def menu(titulo,lista)
      tab = "  "
      puts titulo
      index = 0
      lista.each { |l|
        puts tab+index.to_s+"-"+l
        index += 1
      }

      opcion = lee_entero(lista.length,
                          "\n"+tab+"Elige una opción: ",
                          tab+"Valor erróneo")
      return opcion
    end
    
    def salirCarcel
      arr = ["Pagando","Tirando"]
      opcion = menu("Elige la forma para intentar salir de la carcel",
      arr)
    return @SalidasCarcel[opcion]
    end

    def comprar
      arr = ["Si", "No"]
      opcion = menu("Deseas comprar la Propiedad?", arr)
      return @Respuestas[opcion]
    end

    def gestionar
      arr = ["Vender","Hipotecar","Cancelar_hipoteca","Construir_Casa","Construir_Hotel","Terminar"]
      opcion = menu("Deseas Gestionar su propiedad?", arr)
      @iGestion = opcion
      lista = @juegoModel.getJugador().getPropiedades()
      lista.each_with_index do |titulo,index|
        if titulo == @juegoModel.getCasillaActual.getTituloPropiedad()
          @iPropiedad = index
        end
      end
    end

    def getGestion
      return @iGestion
    end

    def getPropiedad
      return @iPropiedad
    end

    def mostrarSiguienteOperacion(operacion)
      self.mostrar_estado(operacion.to_s)
    end

    def mostrarEventos
      while(Diario.instance.eventos_pendientes)
        self.mostrar_estado(Diario.instance.leer_evento)
      end
    end

    def setCivitasJuego(civitas)
         @juegoModel=civitas
         self.actualizarVista
    end

    def actualizarVista
      puts "----------------------------------------"
      puts @juegoModel.getJugador().to_s
      puts @juegoModel.getCasillaActual.to_s
      puts "----------------------------------------"
    end

  end
end
