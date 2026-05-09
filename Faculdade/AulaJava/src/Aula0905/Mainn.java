package Aula0905;

import aula290425.Pessoa;

import java.util.*;

public class Mainn {
    public static void main(String[] args) {

        ArrayList<String> x = new ArrayList<String>();

        x.add("Joao");
        x.add("Pedro");
        x.add("Lucas");

        int tamanho = x.size();

        for (int index = 0; index < tamanho; index++) {
            String nome = x.get(index);

            System.out.println(nome);
        }

        for (String valor : x){
            System.out.println(valor);
        }

        System.out.println("SET");

        Set<String> y = new HashSet<String>();

        y.add("João");
        y.add("Pedro");
        y.add("Lucas");
        y.add("Jose");

        for (String valor: y){
            System.out.println(valor);
        }

        System.out.println("MAP");

        Map<String, Pessoa> pessoas = new HashMap<>();

        pessoas.put("123456", new Pessoa("Joao"));
        pessoas.put("53456", new Pessoa("Paulo"));
        pessoas.put("653", new Pessoa("Pedro"));

        for (Pessoa p : pessoas.values()){
            System.out.println(p.nome);
        }
    }
}
