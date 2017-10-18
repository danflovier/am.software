import java.util.Scanner;

/**
 *
 * @author dflores
 */
public class Prueba1 {
    // Atributos
    protected int edad;
    protected String nombre;
    
    // Constructor
    public Prueba1(int edad, String nombre)
    {
        this.edad = edad;
        this.nombre = nombre;
    }
    
    // Funciones
    public int getEdad()
    {
        return edad;
    }
    
    protected void printName()
    {
     System.out.println("Mi nombre es: " + nombre);
    }
    
    // Main
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);    
        System.out.println("Escribe tu nombre: ");
        String nombre = s.nextLine();
        System.out.println("Escribe tu edad: ");
        int edad = s.nextInt();
        Prueba1 ejemplo = new Prueba1(20, nombre);
        ejemplo.printName();
        System.out.println();
        System.out.println("Mi edad es: " + ejemplo.getEdad());
    }
    
}