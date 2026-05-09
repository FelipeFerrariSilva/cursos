package devdojo;

public class Aula02TiposPrimitivos {
    public static void main(String[] args) {
        // Guardam na memoria algo simles = int,double,float,char,byte,short,long e boolean

        int age = (int) 10000000000L; //entre parenteses forca o int a ter uma variavel do tipo long
        long numeroGrande = 100000L;
        double salarioDouble = 2000.0D;
        float salarioFloat = 2500.0F;
        byte salarioByte = 127;
        short salarioShort = 32000;
        boolean verdadeirou = true;
        boolean falso = false;
        char caractere = '\u0041';


        String nome = "MAJINNN";
        System.out.println(age); //aspas duplas vai me dar o nome da variavel
        System.out.println("A idade é " + age + " anos");
        System.out.println(falso);
        System.out.println("char: "+caractere);
        System.out.println("oi safada voce viu o " + nome);

    }
}
