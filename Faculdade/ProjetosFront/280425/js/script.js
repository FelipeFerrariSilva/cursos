const nome = document.getElementById('nome');
const idade = document.getElementById('idade');
const localNascimento = document.getElementById('localNascimento');
const telefone = document.getElementById('telefone');

const botao = document.getElementById('botao');


botao.addEventListener('click', function(){
    console.log(nome.value);
    console.log(idade.value);

    // Um objeto
    const obj = {
        nome: nome.value,
        idade: idade.value,
        localNascimento: localNascimento.value,
        telefone: telefone.value
    };

    transformaJson(obj);
}
);


function transformaJson(obj){
    let div = document.getElementById('conteudo');
    let p = document.createElement('p');

    // Stringify - converter o objeto em JSON
    let jsonObjeto = JSON.stringify(obj);
    p.textContent = jsonObjeto;
    div.appendChild(p);
}