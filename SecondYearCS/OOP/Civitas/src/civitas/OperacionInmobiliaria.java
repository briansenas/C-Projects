package civitas;

public class OperacionInmobiliaria {
    private int numPropiedad;
    private GestionesInmobiliarias gestion;
    
    public OperacionInmobiliaria(GestionesInmobiliarias gest, int ip){
        this.numPropiedad = ip;
        this.gestion = gest;
    }
    
    public GestionesInmobiliarias getGestion(){
        return this.gestion;
    }
    
    public int GetNumPropiedad(){
        return this.numPropiedad;
    }
    
}
