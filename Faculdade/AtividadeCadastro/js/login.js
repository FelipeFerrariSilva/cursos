//login com validação
const entrar = document.getElementById('entrar');

entrar.addEventListener('click', function(){
    let login = document.getElementById('login').value;
    let senha = document.getElementById('senha').value;

    //memoria local
    const usuarioCadastrados = JSON.parse(localStorage.getItem("usuarios")) || []; //texto para objetos usando JSON

    let usuarioEncontrado = usuarioCadastrados.find(
        u => u.usuario === login && u.senha === senha
        //function (){}
        //() => {}
    );
    if(usuarioEncontrado){
        localStorage.setItem("userLogado", login);
        window.location.href = "dashboard.html";
    }else{
        document.getElementById('mensagem').textContent = "Login ou senha incorretos"; 
    }
}
);