package sasa;

public class AlunoGraduacao extends Aluno {
    public String trabalhoConclusao;

    @Override
    public void exibirDetalhes() {
        super.exibirDetalhes();
        System.out.printf("Trabalho de Conclusao" + trabalhoConclusao);
    }
}
