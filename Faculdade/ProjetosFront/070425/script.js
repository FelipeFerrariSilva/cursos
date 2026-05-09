const botao = document.getElementById('add'); //adicionar dados
const entrada =document.getElementById('entrada');
const lista =document.getElementById('lista');

//array, lista, vetor 
const itens = [];
botao.addEventListener('click',function (){
    let valorinput = entrada.value;
    itens.push(valorinput); // passando o valor da entrada dentro do valor do input
    console.log(itens);
    atualizar();
  }
);

function atualizar(){
    lista.innerHTML = "";
    let li = document.createElement("li"); // criar um elemento
    li.textContent = "Deu certo";
    lista.appendChild(li); // appendChild adicionei ele dentro da ul
}