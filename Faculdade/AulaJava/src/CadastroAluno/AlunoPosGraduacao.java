public class AlunoPosGraduacao extends Aluno {
    private String orientador;

    public AlunoPosGraduacao(String nome, String matricula, double nota, String orientador) {
        super(nome, matricula, nota);
        this.orientador = orientador;
    }

    public String getOrientador() {
        return orientador;
    }

    public void setOrientador(String orientador) {
        this.orientador = orientador;
    }

    @Override
    public void exibirDetalhes() {
        super.exibirDetalhes();
        System.out.println("Orientador: " + orientador);
    }
}
