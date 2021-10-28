/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel;

/**
 *
 * @author brian
 */
public class HabitacionPanel extends javax.swing.JPanel {

    private Habitacion habitacion;
    
    public void setHabitacion(Habitacion hab){
        habitacion = hab;
        Número.setText(Integer.toString(habitacion.getNumero()));
        CamasIndividuales.setText(Integer.toString(habitacion.getCamasI()));
        CamasMatrimonio.setText(Integer.toString(habitacion.getCamasM()));
        if (habitacion instanceof HabitacionFamiliaNumerosa)
            Literas.setText(Integer.toString(((HabitacionFamiliaNumerosa)habitacion).getLiteras()));
        else
            Literas.setText("0");
        repaint();
    }
    
    /**
     * Creates new form HabitacionPanel
     */
    public HabitacionPanel() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        NúmeroLabel = new javax.swing.JLabel();
        CamasIndividualesLabel = new javax.swing.JLabel();
        CamasMatrimonioLabel = new javax.swing.JLabel();
        LiterasLabel = new javax.swing.JLabel();
        Número = new javax.swing.JTextField();
        CamasIndividuales = new javax.swing.JTextField();
        CamasMatrimonio = new javax.swing.JTextField();
        Literas = new javax.swing.JTextField();

        NúmeroLabel.setText("Número:");

        CamasIndividualesLabel.setText("Camas Individuales:");

        CamasMatrimonioLabel.setText("Camas de Matrimonio:");

        LiterasLabel.setText("Literas:");

        Número.setText("jTextField1");
        Número.setEnabled(false);

        CamasIndividuales.setText("jTextField1");
        CamasIndividuales.setEnabled(false);

        CamasMatrimonio.setText("jTextField1");
        CamasMatrimonio.setEnabled(false);

        Literas.setText("jTextField1");
        Literas.setEnabled(false);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(NúmeroLabel)
                    .addComponent(CamasIndividualesLabel)
                    .addComponent(CamasMatrimonioLabel)
                    .addComponent(LiterasLabel))
                .addGap(37, 37, 37)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Literas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(CamasMatrimonio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(CamasIndividuales, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Número, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(NúmeroLabel)
                    .addComponent(Número, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(CamasIndividualesLabel)
                    .addComponent(CamasIndividuales, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(CamasMatrimonioLabel)
                    .addComponent(CamasMatrimonio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(LiterasLabel)
                    .addComponent(Literas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField CamasIndividuales;
    private javax.swing.JLabel CamasIndividualesLabel;
    private javax.swing.JTextField CamasMatrimonio;
    private javax.swing.JLabel CamasMatrimonioLabel;
    private javax.swing.JTextField Literas;
    private javax.swing.JLabel LiterasLabel;
    private javax.swing.JTextField Número;
    private javax.swing.JLabel NúmeroLabel;
    // End of variables declaration//GEN-END:variables
}