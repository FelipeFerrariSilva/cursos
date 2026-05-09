//import java.io.*;
//import java.util.ArrayList;
//import java.util.List;
//
//public class ProdutoManager {
//    private List<Produto> produtos;
//    private final String ARQUIVO = "produtos.txt";
//
//    public ProdutoManager() {
//        produtos = new ArrayList<>();
//        carregarProdutos();
//    }
//
//    public void adicionarProduto(Produto p) {
//        produtos.add(p);
//        salvarProdutos();
//    }
//
//    public List<Produto> listarProdutos() {
//        return produtos;
//    }
//
//    public void salvarProdutos() {
//        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(ARQUIVO))) {
//            oos.writeObject(produtos);
//        } catch (IOException e) {
//            System.out.println("Erro ao salvar produtos: " + e.getMessage());
//        }
//    }
//
//    public void carregarProdutos() {
//        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(ARQUIVO))) {
//            produtos = (List<Produto>) ois.readObject();
//        } catch (FileNotFoundException e) {
//            // Primeira execução, arquivo ainda não existe
//        } catch (Exception e) {
//            System.out.println("Erro ao carregar produtos: " + e.getMessage());
//        }
//    }
//}
