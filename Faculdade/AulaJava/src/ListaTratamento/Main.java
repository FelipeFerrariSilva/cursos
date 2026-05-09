package ListaTratamento;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        IllegalAccessError erro = new IllegalAccessError("preço menor que zero!");
        Scanner leitor = new Scanner(System.in);

        try {
            System.out.println("Digite um nome: ");
            String nome = leitor.nextLine();
            System.out.println("Digite o preço: ");
            double preco = leitor.nextDouble();
                if(preco < 0){
                    throw  erro;
                }
            System.out.printf("Produto: %s - %f", nome, preco);
        }catch (IllegalArgumentException e){
            System.out.println(e.getMessage());
        } catch (InputMismatchException e) {
            System.out.println("Valor invalido!");
        }finally {
            System.out.println("Saindo...");
            leitor.close();
        }
    }
}