package Aula300525;

public abstract class Animal {
    public String nome;
    public int idade;

    public abstract void fazersom();

    public void comer(){
        System.out.println("Comendo");
    }
}
