package Aula040625;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        String dadosArquivo = "";
        ArrayList<Produto> produtos = new ArrayList<>();

        try(FileWriter arquivo = new FileWriter("produto.txt")) {

            arquivo.write("1;mouse;8.75\n");
            arquivo.append("2;teclado;5.50\n");

        }catch (IOException erro){
            System.out.printf("Erro na criacao do arquivo.");
        }catch (ArithmeticException erro){
            System.out.println(erro.getMessage());
        }
        try(FileReader arquivo = new FileReader("produto.txt")){
            int ascii = arquivo.read();

                while(ascii != -1){
                    dadosArquivo += (char)ascii;
                    System.out.println((char)ascii);
                    ascii = arquivo.read();
                }
            }catch (FileNotFoundException erro){
                System.out.println("Arquivo nao encontrado");
            }catch (IOException erro){
                System.out.println("Erro ao fechar arquivo");
            }

            String[] itens = dadosArquivo.split("\n");

            for (String item : itens) {
                String[] valores = item.split(";");

                int id =  Integer.valueOf(valores[0]);
                String nome = valores[1];
                double preco = Double.valueOf(valores[2]);

                Produto novoProduto = new Produto(id, nome, preco);
                produtos.add(novoProduto);
            }

            for (Produto p : produtos){
                System.out.println(p.toString());
            }
    }
}
// try(FileWriter arquivo = new FileWriter("produto.txt")) {
//            arquivo.write("Teste de escrita write\n");
//            arquivo.append("Teste de escrita append \n")
//                    .append("Teste de escrita append 2\n");
//        }catch (IOException erro){
//            System.out.printf("Erro na criacao do arquivo.");
//        }catch (ArithmeticException erro){
//            System.out.println(erro.getMessage());
//        }