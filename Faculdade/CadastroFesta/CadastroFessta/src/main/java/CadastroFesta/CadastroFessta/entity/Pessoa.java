package CadastroFesta.CadastroFessta.entity;

import jakarta.persistence.*;

@Entity
@Table(name = "pessoas")
public class Pessoa {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String nome;
    private int idade;

    public Pessoa() {}

    public Pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public Long getId() { return id;}
    public String getNome() { return nome;}
    public void setNome(String nome) { this.nome = nome;}
    public int getIdade() { return idade;}
    public void setIdade(int idade) { this.idade = idade;}
}
