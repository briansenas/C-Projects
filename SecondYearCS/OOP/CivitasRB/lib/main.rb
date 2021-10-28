  require_relative 'vista_textual.rb'
  require_relative 'civitas_juego.rb'
  require_relative 'dado.rb'
  require_relative 'controlador.rb'
module CivitasRB
  vista = VistaTextual.new
  jugadores = ["Brian"]
  juego = CivitasJuego.new(jugadores)
  Dado.instance.setDebug(true)
  control = Controlador.new(juego,vista)
  control.juega
end