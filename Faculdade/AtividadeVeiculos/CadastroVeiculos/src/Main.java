import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Main {
    private static ArrayList<Veiculo> veiculos = new ArrayList<>();

    public static void main(String[] args) {
        carregarDados();

        Scanner scanner = new Scanner(System.in);
        int opcao;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Cadastrar Veículo");
            System.out.println("2. Listar Veículos");
            System.out.println("3. Atualizar Veículo");
            System.out.println("4. Remover Veículo");
            System.out.println("5. Realizar Manutenção");
            System.out.println("6. Sair");
            System.out.print("Opção: ");
            opcao = scanner.nextInt(); scanner.nextLine();

            switch (opcao) {
                case 1 -> cadastrarVeiculo(scanner);
                case 2 -> listarVeiculos();
                case 3 -> atualizarVeiculo(scanner);
                case 4 -> removerVeiculo(scanner);
                case 5 -> manutencaoVeiculo(scanner);
                case 6 -> salvarDados();
                default -> System.out.println("Opção inválida.");
            }
        } while (opcao != 6);

        scanner.close();
    }

    private static void cadastrarVeiculo(Scanner scanner) {
        System.out.print("Tipo (1-Carro, 2-Moto): ");
        int tipo = scanner.nextInt(); scanner.nextLine();

        System.out.print("Placa: ");
        String placa = scanner.nextLine();

        if (buscarVeiculo(placa) != null) {
            System.out.println("Erro: Placa já cadastrada.");
            return;
        }

        System.out.print("Marca: ");
        String marca = scanner.nextLine();

        System.out.print("Modelo: ");
        String modelo = scanner.nextLine();

        Veiculo v = (tipo == 1) ? new Carro(placa, marca, modelo) : new Moto(placa, marca, modelo);
        veiculos.add(v);
        v.veiculoCadastrado();
    }

    private static void listarVeiculos() {
        if (veiculos.isEmpty()) {
            System.out.println("Nenhum veículo cadastrado.");
            return;
        }

        for (Veiculo v : veiculos) {
            v.exibirDados();
        }
    }

    private static void atualizarVeiculo(Scanner scanner) {
        System.out.print("Placa do veículo a atualizar: ");
        String placa = scanner.nextLine();
        Veiculo v = buscarVeiculo(placa);

        if (v == null) {
            System.out.println("Veículo não encontrado.");
            return;
        }

        System.out.print("Nova Marca: ");
        String novaMarca = scanner.nextLine();

        System.out.print("Novo Modelo: ");
        String novoModelo = scanner.nextLine();

        v.setMarca(novaMarca);
        v.setModelo(novoModelo);
        System.out.println("Veículo atualizado com sucesso.");
    }

    private static void removerVeiculo(Scanner scanner) {
        System.out.print("Placa do veículo a remover: ");
        String placa = scanner.nextLine();

        Veiculo v = buscarVeiculo(placa);
        if (v != null) {
            veiculos.remove(v);
            System.out.println("Veículo removido com sucesso.");
        } else {
            System.out.println("Veículo não encontrado.");
        }
    }

    private static void manutencaoVeiculo(Scanner scanner) {
        System.out.print("Placa do veículo para manutenção: ");
        String placa = scanner.nextLine();

        Veiculo v = buscarVeiculo(placa);
        if (v instanceof OperacoesVeiculo) {
            ((OperacoesVeiculo) v).realizarManutencao();
        } else {
            System.out.println("Veículo não encontrado.");
        }
    }

    private static Veiculo buscarVeiculo(String placa) {
        for (Veiculo v : veiculos) {
            if (v.getPlaca().equalsIgnoreCase(placa)) {
                return v;
            }
        }
        return null;
    }

    private static void salvarDados() {
        try (FileWriter fw = new FileWriter("veiculos.txt")) {
            for (Veiculo v : veiculos) {
                String tipo = v instanceof Carro ? "Carro" : "Moto";
                fw.write(tipo + ";" + v.placa + ";" + v.marca + ";" + v.modelo + "\n");
            }
            System.out.println("Dados salvos com sucesso.");
        } catch (IOException e) {
            System.out.println("Erro ao salvar os dados: " + e.getMessage());
        }
    }

    private static void carregarDados() {
        try (FileReader fr = new FileReader("veiculos.txt")) {
            StringBuilder sb = new StringBuilder();
            int c;
            while ((c = fr.read()) != -1) {
                sb.append((char) c);
            }

            String[] linhas = sb.toString().split("\n");

            for (String linha : linhas) {
                String[] dados = linha.trim().split(";");
                if (dados.length == 4) {
                    Veiculo v = dados[0].equalsIgnoreCase("Carro")
                            ? new Carro(dados[1], dados[2], dados[3])
                            : new Moto(dados[1], dados[2], dados[3]);
                    veiculos.add(v);
                }
            }

        } catch (IOException e) {
            System.out.println("Arquivo não encontrado. Iniciando com lista vazia.");
        }
    }
}
