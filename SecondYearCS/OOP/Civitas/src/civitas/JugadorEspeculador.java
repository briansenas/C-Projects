package civitas;

import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JOptionPane;


public class JugadorEspeculador extends Jugador {

    private int FactorEspeculador = 2;
    private Scanner in;
    private float fianza;
    
  
    
    public JugadorEspeculador(Jugador otro,float fianza) {
        super(otro);
        this.fianza = fianza;
        in = new Scanner (System.in);
    }
        
    @Override
     boolean pagaImpuesto(float cantidad){
        boolean result = false;
        if(!encarcelado){
            result = this.paga(cantidad/FactorEspeculador);
        }
        return result;
    }
     
     @Override
     protected int getCasasMax(){
         return super.getCasasMax()*FactorEspeculador;
     }
     
     @Override
     protected int getHotelesMax(){
         return super.getHotelesMax()*FactorEspeculador;
     }
    
      /**
     * @brief verifica si el jugador debe ser Encarcelado o No, y si posee SalvoConducto
     * @return verdadero/falso
     */
    @Override
    protected boolean debeSerEncarcelado(){
        boolean result = false;
        int numero = -1;
        if(encarcelado){
            result = true;
        }
        if(this.tieneSalvoconducto()){
            result = false;
            super.perderSalvoconducto();
            Diario.getInstance().ocurreEvento("\n\tSe Libre de la Cárcel\n\t");
        }else{
            //Ahora que estamos utilizando GUI
        numero = JOptionPane.showConfirmDialog(null, "¿Quieres comprar la calle actual?", "Compra", JOptionPane.YES_NO_OPTION);
        }
        if(super.puedoGastar(fianza) && numero == 0 ){
                result = false;
                super.paga(fianza);
                Diario.getInstance().ocurreEvento("\n\tNo Ha ido a Carcel, ya que ha pagado la fianza\n\t");
        }
        return result;
    }
}
