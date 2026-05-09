public abstract class Veiculo {
    protected String placa;
    protected String marca;
    protected String modelo;

    public Veiculo(String placa, String marca, String modelo) {
        this.placa = placa;
        this.marca = marca;
        this.modelo = modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void veiculoCadastrado() {
        System.out.println("Veículo cadastrado com sucesso");
    }

    public abstract void exibirDados();
}
