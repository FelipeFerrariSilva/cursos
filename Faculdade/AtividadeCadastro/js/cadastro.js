//criação de registro

const botao = document.getElementById('btnCadastrar');
//const listaUsuario = [];
botao.addEventListener('click',function(){
    listaUsuario = JSON.parse(localStorage.getItem("usuarios")) || [];
    const usuario = {
        usuario: document.getElementById('login').value,
        senha: document.getElementById('senha').value
   };

   const indexEditar = document.getElementById("indexEditado").value;
   if (indexEditar !== ""){
        listaUsuario[indexEditar] = usuario;
        document.getElementById("indexEditado").value = "";
   }else{
        listaUsuario.push('usuario');
   }
   // console.log(usuario);

   //criar lista de usuarios
   listaJson = JSON.stringify(listaUsuario);
   localStorage.setItem("usuarios",listaJson);
   usuario: document.getElementById('login').value = '';
   senha: document.getElementById('senha').value = '';
   listar();
});

function listar(){
    const usuarioCadastrados = JSON.parse(localStorage.getItem("usuarios")) || []; //  || SE
    let tabela = document.getElementById('lista_usuario');
    tabela.innerHTML = "";
    usuarioCadastrados.forEach((usuario, index) => {
        let linha = document.createElement('tr');
        linha.innerHTML = `
        <td>${usuario.usuario}</td>
        <td>${usuario.senha}</td>
        <td>
            <button onclick="editarUsuario(${index})">Editar</button>
            <button onclick="excluirUsuario(${index})">Excluir</button>
        </td>
        `;

        tabela.appendChild(linha);
    });
}

function editarUsuario(index){
    const usuarioCadastrados = JSON.parse(localStorage.getItem("usuarios")) || [];
    //usuarios cadastrados
    const objUsuario = usuarioCadastrados[index];
    document.getElementById("login").value = objUsuario.usuario;
    document.getElementById("senha").value = objUsuario.senha;
    document.getElementById("indexEditado").value = index;
    listar();

}

function excluirUsuario(index){
    const usuarioCadastrados = JSON.parse(localStorage.getItem("usuarios")) || [];
    usuarioCadastrados.splice(index,1); //exclui elemento valor
    listaJson = JSON.stringify(usuarioCadastrados); // traduz JSON
    localStorage.setItem("usuarios", listaJson); //Subscreve antigo
    listar();
}
listar();
