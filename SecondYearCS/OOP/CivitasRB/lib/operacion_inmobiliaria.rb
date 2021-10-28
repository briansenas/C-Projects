module CivitasRB
  class OperacionInmobiliaria
    def initialize(gest,ip)
      @numPropiedad = ip
      @gestion = gest
    end
    
    def getGestion
      return @gestion
    end
    
    def getNumPropiedad
      return @numPropiedad
    end
  end
end
