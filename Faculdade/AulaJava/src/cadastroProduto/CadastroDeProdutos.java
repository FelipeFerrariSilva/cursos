//import java.util.ArrayList;
//import java.util.Scanner;
//
//public class CadastroDeProdutos {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        ArrayList<Produto> listaDeProdutos = new ArrayList<>();
//
//        while (true) {
//            System.out.println("\n=== Menu de Cadastro de Produtos ===");
//            System.out.println("1. Cadastrar produto");
//            System.out.println("2. Listar produtos");
//            System.out.println("3. Excluir produto");
//            System.out.println("4. Sair");
//            System.out.print("Escolha uma opção: ");
//            int opcao = scanner.nextInt();
//            scanner.nextLine(); // Limpa buffer
//
//            switch (opcao) {
//                case 1:
//                    System.out.print("Nome do produto: ");
//                    String nome = scanner.nextLine();
//
//                    System.out.print("Preço do produto: ");
//                    double preco = scanner.nextDouble();
//
//                    System.out.print("Quantidade: ");
//                    int quantidade = scanner.nextInt();
//
//                    Produto novoProduto = new Produto(nome, preco, quantidade);
//                    listaDeProdutos.add(novoProduto);
//                    System.out.println("Produto cadastrado com sucesso!");
//                    break;
//
//                case 2:
//                    System.out.println("\n=== Lista de Produtos ===");
//                    if (listaDeProdutos.isEmpty()) {
//                        System.out.println("Nenhum produto cadastrado.");
//                    } else {
//                        for (int i = 0; i < listaDeProdutos.size(); i++) {
//                            System.out.println((i + 1) + ". " + listaDeProdutos.get(i));
//                        }
//                    }
//                    break;
//
//                case 3:
//                    if (listaDeProdutos.isEmpty()) {
//                        System.out.println("Nenhum produto para excluir.");
//                    } else {
//                        System.out.println("\n=== Produtos Cadastrados ===");
//                        for (int i = 0; i < listaDeProdutos.size(); i++) {
//                            System.out.println((i + 1) + ". " + listaDeProdutos.get(i));
//                        }
//
//                        System.out.print("Digite o número do produto que deseja excluir: ");
//                        int indice = scanner.nextInt();
//
//                        if (indice >= 1 && indice <= listaDeProdutos.size()) {
//                            Produto removido = listaDeProdutos.remove(indice - 1);
//                            System.out.println("Produto \"" + removido.getNome() + "\" removido com sucesso!");
//                        } else {
//                            System.out.println("Índice inválido.");
//                        }
//                    }
//                    break;
//
//                case 4:
//                    System.out.println("Saindo...");
//                    scanner.close();
//                    return;
//
//                default:
//                    System.out.println("Opção inválida. Tente novamente.");
//            }
//        }
//    }
//}
