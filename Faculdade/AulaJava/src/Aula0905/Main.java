package Aula0905;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args){

        ArrayList<String> x = new ArrayList<String>();

        x.add("Joao");
        x.add("Pedro");
        x.add("Lucas");

        int tamanho = x.size();

        for (int index=0; index<tamanho; index++){
            System.out.printf("Posição: %d - Valor: %s\n", index,x.get(index));
        }

        System.out.println(x.get(2));

        x.remove("Pedro");

        tamanho = x.size();

        for (int index=0; index<tamanho; index++){
            System.out.printf("Posição: %d - Valor: %s\n", index,x.get(index));
        }
    }
}
