package Ex0905;

import aula290425.Pessoa;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args){

        ArrayList<String> x = new ArrayList<String>();

        x.add("Corsa");
        x.add("Uno");
        x.add("Kadette");
        x.add("Eclipse");

        int tamanho = x.size();

        for (int index=0; index<tamanho; index++){
            System.out.printf("Posição: %d - Valor: %s\n", index,x.get(index));
        }

        System.out.printf("Foi removido o: %s \n", x.get(2));

        x.remove("Kadette");

        tamanho = x.size();

        for (int index=0; index<tamanho; index++){
            System.out.printf("Posição: %d - Valor: %s\n", index,x.get(index));
        }
    }
}

