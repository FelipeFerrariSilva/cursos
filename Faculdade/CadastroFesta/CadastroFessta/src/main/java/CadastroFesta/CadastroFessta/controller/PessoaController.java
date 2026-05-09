package CadastroFesta.CadastroFessta.controller;

import CadastroFesta.CadastroFessta.dto.CreatePessoaRequest;
import CadastroFesta.CadastroFessta.entity.Pessoa;
import CadastroFesta.CadastroFessta.repository.PessoaRepository;
import CadastroFesta.CadastroFessta.service.PessoaService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("pessoas")
public class PessoaController {

    private final PessoaService service;

    public PessoaController(PessoaService service){
        this.service = service;
    }

    @PostMapping
    public ResponseEntity<Pessoa> criar(@RequestBody CreatePessoaRequest req){
        Pessoa criado = service.criarPessoa(req.getNome(), req.getIdade());
        return ResponseEntity.status(201).body(criado);
    }

    @GetMapping
    public ResponseEntity<List<Pessoa>> listar(){
        return ResponseEntity.ok(service.listarPessoas());
    }
}
