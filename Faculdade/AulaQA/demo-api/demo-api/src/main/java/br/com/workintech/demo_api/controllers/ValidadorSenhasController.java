package br.com.workintech.demo_api.controllers;

import br.com.workintech.demo_api.services.ValidarSenha;

import java.util.Scanner;

public class ValidadorSenhasController {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

        System.out.println("Digite sua senha: ");
        String senha = scanner.nextLine();


        if (ValidarSenha.validarSenha(senha)) {
            System.out.println(" Senha válida!");
        }else {
        System.out.println(" Senha inválida. A senha deve:");
        System.out.println("- Ter entre 6 e 12 caracteres");
        System.out.println("- Conter pelo menos 1 letra maiúscula");
        System.out.println("- Conter pelo menos 1 número");
        System.out.println("- Conter pelo menos 1 caractere especial");
    }

        scanner.close();
}
}