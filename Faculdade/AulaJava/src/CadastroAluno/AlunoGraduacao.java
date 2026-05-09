public class AlunoGraduacao extends Aluno {
    private String trabalhoConclusao;

    public AlunoGraduacao(String nome, String matricula, double nota, String trabalhoConclusao) {
        super(nome, matricula, nota);
        this.trabalhoConclusao = trabalhoConclusao;
    }

    public String getTrabalhoConclusao() {
        return trabalhoConclusao;
    }

    public void setTrabalhoConclusao(String trabalhoConclusao) {
        this.trabalhoConclusao = trabalhoConclusao;
    }

    @Override
    public void exibirDetalhes() {
        super.exibirDetalhes();
        System.out.println("Trabalho de Conclusão: " + trabalhoConclusao);
    }
}
