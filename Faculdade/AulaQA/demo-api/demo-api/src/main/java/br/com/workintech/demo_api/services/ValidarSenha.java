package br.com.workintech.demo_api.services;

public class ValidarSenha {
    public static boolean validarSenha(String senha) {
        return senha.matches("^(?=.*[A-Z])(?=.*\\d).{6,12}$");
    }
}