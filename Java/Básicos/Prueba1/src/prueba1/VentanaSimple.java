package prueba1;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 *
 * @author dflores
 */
public class VentanaSimple extends JFrame{
    public VentanaSimple()
    {
        setBounds(50,50,500,500);
        
        JLabel l = new JLabel("Escribe tu nombre: ");
        JTextField nombre = new JTextField("                                    ");
        JButton button = new JButton("Saludo");
        JLabel saludo = new JLabel();
        setLayout(new FlowLayout());
        
        add(l);
        add(nombre);
        add(button);
        add(saludo);
        
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nombre.getText();
                saludo.setText("Hola " + name);
            }
        });
        
        setVisible(true);
    }
    public static void main(String[] args)
    {
       VentanaSimple v = new VentanaSimple();
    }
}
