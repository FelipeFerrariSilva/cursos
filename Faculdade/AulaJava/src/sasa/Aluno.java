package sasa;

public class Aluno {
    public String nome;
    public String matricula;
    public double nota;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public double getNota() {
        return nota;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }

    public void exibirDetalhes(){
        System.out.printf("Nome" + nome);
        System.out.printf("Matricula" + matricula);
        System.out.printf("Nota" + nota);
    }
}

//import java.io.Serializable;
//
//public class Produto implements Serializable {
//    private String nome;
//    private double preco;
//    private int quantidade;
//
//    public Produto(String nome, double preco, int quantidade) {
//        this.nome = nome;
//        this.preco = preco;
//        this.quantidade = quantidade;
//    }
//
//    public String getNome() {
//        return nome;
//    }
//
//    public double getPreco() {
//        return preco;
//    }
//
//    public int getQuantidade() {
//        return quantidade;
//    }
//
//    @Override
//    public String toString() {
//        return "Produto: " + nome + " | Preço: R$" + preco + " | Quantidade: " + quantidade;
//    }
//}
