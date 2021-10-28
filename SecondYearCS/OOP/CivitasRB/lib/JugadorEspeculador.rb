module CivitasRB
  class JugadorEspeculador < Jugador
    def initialize(otro,fianza,factorEspeculador=2)
      super(otro)
      @FactorEspeculador = factorEspeculador
      @fianza = fianza
    end

    def pagaImpuesto(cantidad)
      result = false
      if(!super.encarcelado)
        result = self.paga(cantidad/@FactorEspeculador)
      end
      return result
    end

    def getCasasMax()
      return super.getCasasMax()*@FactorEspeculador
    end

    def getHotelesMax()
      return super.getHotelesMax()*@FactorEspeculador
    end

    def debeSerEncarcelado
      result = false
      if(super.encarcelado)
        result = true
      end
      if(super.tieneSalvoconducto())
        result = false
        super.perderSalvoconducto()
        Diario.instance.ocurre_evento("\t\nSe Libra de la Carcel\t\n")
      else
        puts "Quieres pagar la fianza?\n\t0-Si\n\t1-No"
        loop do
           numero = gets.to_i
           if numero >=0 && numero < 2
              break
          end
        end
        if(super.puedoGastar(@fianza) && numero==0)
          result = false
          super.paga(fianza)
          Diario.instance.ocurre_evento("\n\tNo Ha ido a Carcel, ya que ha pagado la fianza\n\t")
        end
      end
      return result
    end

  end
end
