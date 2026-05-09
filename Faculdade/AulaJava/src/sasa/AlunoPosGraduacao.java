package sasa;

public class AlunoPosGraduacao extends Aluno {
    public String orientador;

    @Override
    public void exibirDetalhes() {
        super.exibirDetalhes();
        System.out.printf("Orientador" + orientador);
    }
}
