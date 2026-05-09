function lernumero1(){
    let entrada1 = parseFloat(document.getElementById('entrada1').value);
    return entrada1;
}

function lernumero2(){
    let entrada2 = parseFloat(document.getElementById('entrada2').value);
    return entrada2;
}

function somar(){
    let resultado = lernumero1() + lernumero2();
    document.getElementById("resultado").textContent = resultado;
}

function dividir(){
    if(lernumero2() === 0){
        document.getElementById('resultado').innerText = "Divisão por zero";
    }else{
        let resultado = lernumero1() / lernumero2();
        document.getElementById('resultado').innerText = resultado;
    }


}
