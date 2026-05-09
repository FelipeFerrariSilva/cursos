import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //Exercicio 1
        Scanner scanner = new Scanner(System.in);
        String resposta;
        do {
            try (FileWriter arquivo = new FileWriter("produtos.txt", true)) {
                System.out.println("Digte o nome do produto: ");
                String nome = scanner.nextLine();

                System.out.println("Digite o preco do produto: ");
                double preco = scanner.nextDouble();
                scanner.nextLine();

                arquivo.append("Nome: " + nome + ",Preço: " + preco + "\n");

                registrarLog("cadastrado", nome);
            } catch (IOException erro) {
                System.out.println("Erro na criacao do arquivo.");
            } catch (ArithmeticException erro) {
                System.out.println(erro.getMessage());
            }
            System.out.print("Deseja adcionar outro produto? (sim/nao): ");
            resposta = scanner.nextLine().toLowerCase();

        } while (resposta.equals("s") || resposta.equals("sim"));

        //Exercicio 2
        StringBuilder dadosArquivo = new StringBuilder();

        try (FileReader arquivo = new FileReader("produtos.txt")) {
            int caractere;
            while ((caractere = arquivo.read()) != -1) {
                dadosArquivo.append((char) caractere);
            }
        } catch (IOException erro) {
            System.out.println("Erro ao ler o arquivo: " + erro.getMessage());
        }

        String[] linhas = dadosArquivo.toString().split("\n");

        System.out.println("Produtos Cadastrados:");
        for (String linha : linhas) {
            String[] partes = linha.split(",");
            if (partes.length == 2) {
                String nome = partes[0].split(":")[1].trim();
                String preco = partes[1].split(":")[1].trim();
                System.out.println("Produto: " + nome + " - Preço: " + preco);
            }
        }

        //Exercicio 3
        StringBuilder conteudo = new StringBuilder();

        try (FileReader leitor = new FileReader("produtos.txt")) {
            int caractere;
            while ((caractere = leitor.read()) != -1) {
                conteudo.append((char) caractere);
            }
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
            return;
        }
        String texto = conteudo.toString();
        texto = texto.trim();
        if (texto.isEmpty()) {
            System.out.println("O arquivo está vazio. Total de palavras: 0");
        } else {
            String[] palavras = texto.split("\\s+");
            System.out.println("Total de palavras: " + palavras.length);
        }

        //Exercicio 5
        System.out.println("\nTarefas Existentes:");

        try (FileReader leitorTarefas = new FileReader("tarefas.txt")) {
            int caractere;
            StringBuilder conteudoTarefas = new StringBuilder();

            while ((caractere = leitorTarefas.read()) != -1) {
                conteudoTarefas.append((char) caractere);
            }

            String[] tarefas = conteudoTarefas.toString().split("\n");
            for (String tarefa : tarefas) {
                if (!tarefa.trim().isEmpty()) {
                    System.out.println(tarefa);
                }
            }
        } catch (IOException e) {
            System.out.println("Nenhuma tarefa encontrada ou erro ao ler o arquivo.");
        }

        String respostaTarefa;

        do {
            System.out.print("Digite uma nova tarefa: ");
            String novaTarefa = scanner.nextLine();

            try (FileWriter escritorTarefa = new FileWriter("tarefas.txt", true)) {
                escritorTarefa.write("- " + novaTarefa + "\n");
            } catch (IOException e) {
                System.out.println("Erro ao gravar tarefa: " + e.getMessage());
            }

            System.out.print("Deseja adicionar outra tarefa? (sim/nao): ");
            respostaTarefa = scanner.nextLine().toLowerCase();

        } while (respostaTarefa.equals("sim") || respostaTarefa.equals("s"));

        scanner.close();
        System.out.println("Tarefas atualizadas com sucesso!");
    }
    //Exercicio 4
    public static void registrarLog(String acao, String nomeProduto) {
        LocalDateTime agora = LocalDateTime.now();
        DateTimeFormatter formato = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        String dataHora = agora.format(formato);

        String linha = "[" + dataHora + "] Produto " + acao + ": " + nomeProduto + "\n";

        try (FileWriter log = new FileWriter("log.txt", true)) {
            log.write(linha);
        } catch (IOException e) {
            System.out.println("Erro ao escrever no log: " + e.getMessage());
        }
    }
}