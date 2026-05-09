function dados() {
    var x = document.getElementById("nome").value;
    document.getElementById("nomee").innerHTML = "Nome: " + x;
    var y = document.getElementById("cpf").value;
    document.getElementById("cpff").innerHTML = "CPF: " + y;
    var z = document.getElementById("data").value;
    document.getElementById("dataa").innerHTML = "Data: " + z;
  }

function corte(){
    var x = document.getElementById("corte").value;
    document.getElementById("cortee").innerHTML = "Serviço: " + x;
    valorcorte();
}

function cortebarba(){
    var x = document.getElementById("cortebarba").value;
    document.getElementById("cortebarbaa").innerHTML = "Serviço: " + x;
    valorcortebarba();
}

function barba(){
    var x = document.getElementById("barba").value;
    document.getElementById("barbaa").innerHTML = "Serviço: " + x;
    valorbarba();
}

function quinzenasim(){
    var z = document.getElementById("quinzenasim").value;
    document.getElementById("quinzenaa").innerHTML = "Atendimento quinzenal?: " + z;
    valordesconto();
}

function quinzenanao(){
    var z = document.getElementById("quinzenanao").value;
    document.getElementById("quinzenaaa").innerHTML = "Atendimento quinzenal?: " + z;
}

function valordesconto(){
    document.getElementById("valordescc").innerHTML = "Voce tem 10% de desconto";
    document.getElementById("valordesccc").innerHTML = "Se for corte fica 36,00";
    document.getElementById("valordescccc").innerHTML = "Se for corte e barba fica 54,00";
    document.getElementById("valordesccccc").innerHTML = "Se for barba fica 27,00";

}

function valorcorte(){
    document.getElementById("valorcc").innerHTML = "Valor: 40,00";
}

function valorcortebarba(){
    document.getElementById("valorcb").innerHTML = "Valor: 60,00";
}

function valorbarba(){
    document.getElementById("valorbb").innerHTML = "Valor: 30,00";
}