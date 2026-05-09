package Aula300525;

public class Main {
    public static void main(String[] args) {

        Cachorro bob = new Cachorro();
        bob.nome = "Bob";
        bob.idade =  10;
        bob.raca = "Vira Lata";

        System.out.println("Nome do Cachorro:"+ bob.nome + "\nIdade:" + bob.idade +"\nRaça:"+ bob.raca);
        bob.fazersom();

        bob.comer();
    }
}
