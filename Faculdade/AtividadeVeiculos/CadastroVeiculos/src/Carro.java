public class Carro extends Veiculo implements OperacoesVeiculo {

    public Carro(String placa, String marca, String modelo) {
        super(placa, marca, modelo);
    }

    @Override
    public void exibirDados() {
        System.out.println("[CARRO] Placa: " + placa + " | Marca: " + marca + " | Modelo: " + modelo);
    }

    @Override
    public void realizarManutencao() {
        System.out.println("Manutenção feita no carro com placa " + placa);
    }
}
