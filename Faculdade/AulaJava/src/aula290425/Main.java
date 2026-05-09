package aula290425;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        int[] x = new int[3];

        x[0] = 50;

        for (int index = 0; index < 3; index++) {
            System.out.println("Index: " + index);
            System.out.println("Valor: " + x[index]+"\n");
        }


        Pessoa[] y = new Pessoa[3];

        y[0] = new Pessoa("Joao");
        y[1] = new Pessoa("a");
        y[2] = new Pessoa("p");


        for (int index = 0; index < 3; index++) {
            System.out.println("Index: " + index);
            System.out.println("Valor: " + y[index].nome+"\n");
        }

        ArrayList<String> nomes = new ArrayList<>();
        System.out.println(nomes.size());
        nomes.add("Joao");
        nomes.add("10");
        System.out.println(nomes.size());

        for (int index = 0; index < nomes.size(); index++) {
            System.out.println("Index: " + index);
            System.out.println("Valor: " + nomes.get(index)+"\n");
        }

    }
}
