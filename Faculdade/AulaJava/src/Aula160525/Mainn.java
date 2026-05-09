package Aula160525;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Mainn {
    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        System.out.println("Digite o primeiro numero: ");
        try {
            int valor = leitor.nextInt();

            if (valor < 0) {
                throw new ValorMenorQue0Exception();
            }

            System.out.println("Obrigado!!");

        } catch (InputMismatchException erro) {
            System.out.println("Valor invalido!!");
        } catch (ValorMenorQue0Exception erro) {

            System.out.println(erro.getMessage());

        } finally {  //Mostra a mensagem mesmo tendo erros
            System.out.println("Saindo....");
        }
    }
}

// do{
//
// }while (true);

//Scanner leitor = new Scanner(System.in);
//
//        System.out.println("Digite o primeiro numero: ");
//        try{
//            int n1 = leitor.nextInt();
//
//            System.out.println("Obrigado pelo valor digitado!!");
//
//        }catch (InputMismatchException erro){
//            System.out.println("Valor invalido!!");
//        }catch (ArithmeticException erro){
//            System.out.println("Dividiu por 0!!");
//        }catch (Exception erro){   //Mais generico
//            System.out.println("Deu erro!!");
//        }finally {  //Mostra a mensagem mesmo tendo erros
//            System.out.println("Saindo....");
//        }