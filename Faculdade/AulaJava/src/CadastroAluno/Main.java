import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Crud crud = new Crud();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1 - Cadastrar aluno");
            System.out.println("2 - Editar aluno");
            System.out.println("3 - Listar alunos");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            if (opcao == 1) {
                crud.cadastrarAluno();
            } else if (opcao == 2) {
                crud.editarAluno();
            } else if (opcao == 3) {
                crud.listarAlunos();
            } else if (opcao == 4) {
                break;
            } else {
                System.out.println("Opção inválida.");
            }
        }

        scanner.close();
    }
}
