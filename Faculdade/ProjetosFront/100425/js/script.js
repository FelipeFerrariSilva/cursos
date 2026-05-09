const botao = document.getElementById('add'); //adcionar dados
const entrada = document.getElementById('entrada');
const lista = document.getElementById('lista');

//array, lista, vetor
const itens = []; //colchetes
botao.addEventListener('click', function(){
    let valor = entrada.value
    itens.push(valor);
    entrada.value = "";
    console.log(itens);
    imprimir();
}
);

function imprimir(){
    lista.innerHTML = "";
    for(let i = 0; i < itens.length; i++){
        let li = document.createElement("li");
        li.textContent = itens[i];
        lista.appendChild(li);
    }
}
/*
section class="app"> <!-- Section e um bloco que separa-->
       <h2>Adcionar na Lista</h2>
       <input type="text" id="entrada" placeholder="item">
      <button id="add">Adcionar</button>

      <ul id="lista"></ul>
   </section>

//array, lista, vetor
//const itens = [];
//botao.addEventListener('click', function(){
//    let valorinput = entrada.value;
//    itens.push(valorinput); //passando o valor da entrada dentro do valor do input
//    console.log(itens);
//    atualizar();
//}
//);

//function atualizar(){
 lista.innerHTML = "";
  let li = document.createElement("li"); //criar um elemento
  li.textContent = "Deu certo"; // dentro de tags textuas, e um metodo de inserir texto
 lista.appendChild(li); // appendChild adcionei ele dentro da ul
}*/
