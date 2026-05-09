import java.util.ArrayList;
import java.util.Scanner;

public class Crud {
    private ArrayList<Aluno> alunos;
    private Scanner scanner;

    public Crud() {
        alunos = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public void cadastrarAluno() {
        System.out.print("Tipo de aluno (1 - Graduação | 2 - Pós-Graduação): ");
        int tipo = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Nome: ");
        String nome = scanner.nextLine();

        System.out.print("Matrícula: ");
        String matricula = scanner.nextLine();

        System.out.print("Nota: ");
        double nota = scanner.nextDouble();
        scanner.nextLine();

        if (tipo == 1) {
            System.out.print("Trabalho de Conclusão: ");
            String tcc = scanner.nextLine();
            AlunoGraduacao ag = new AlunoGraduacao(nome, matricula, nota, tcc);
            alunos.add(ag);
        } else if (tipo == 2) {
            System.out.print("Orientador: ");
            String orientador = scanner.nextLine();
            AlunoPosGraduacao apg = new AlunoPosGraduacao(nome, matricula, nota, orientador);
            alunos.add(apg);
        } else {
            System.out.println("Tipo inválido.");
        }
    }

    public void editarAluno() {
        System.out.print("Digite a matrícula do aluno que deseja editar: ");
        String mat = scanner.nextLine();
        boolean encontrado = false;

        for (Aluno aluno : alunos) {
            if (aluno.getMatricula().equals(mat)) {
                encontrado = true;

                System.out.print("Novo nome: ");
                aluno.setNome(scanner.nextLine());

                System.out.print("Nova nota: ");
                aluno.setNota(scanner.nextDouble());
                scanner.nextLine();

                if (aluno instanceof AlunoGraduacao) {
                    System.out.print("Novo trabalho de conclusão: ");
                    ((AlunoGraduacao) aluno).setTrabalhoConclusao(scanner.nextLine());
                } else if (aluno instanceof AlunoPosGraduacao) {
                    System.out.print("Novo orientador: ");
                    ((AlunoPosGraduacao) aluno).setOrientador(scanner.nextLine());
                }
                break;
            }
        }

        if (!encontrado) {
            System.out.println("Aluno não encontrado.");
        }
    }

    public void listarAlunos() {
        if (alunos.isEmpty()) {
            System.out.println("Nenhum aluno cadastrado.");
        } else {
            for (Aluno aluno : alunos) {
                aluno.exibirDetalhes();
                System.out.println("------------");
            }
        }
    }
}
