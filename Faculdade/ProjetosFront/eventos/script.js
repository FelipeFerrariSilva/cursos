const botao = document.getElementById('meuBotao');
const resposta = document.getElementById('resposta');
const eventos = document.getElementById('eventos');

botao.addEventListener('click', imprimir); /* colocar um metodo para ouvir uma acao, do mouse ou do teclado */

botao.addEventListener('mouseover', function(){   /* quando o mouse passa em cima */
    resposta.innerText = "Voce passou em min seu safado";
} )

botao.addEventListener('mouseout', function(){   /* quando o mouse sai da onde esta */
    resposta.innerText = "Sai daqui, nao volta";
})

botao.addEventListener('mouseover', function(){
    eventos.innerText = alert('VOCE FOI INVADIDO');
})

botao.addEventListener('mouseover', function(){
    eventos.innerText = alert('NAO TENTE FUGIR');
})

function imprimir(){
    resposta.innerText = "voce clicou no meu boneco";
}