package br.com.workintech.api.services;

public class PasswordValidator {
    public static boolean isValid(String password) {
        if (password == null)
            throw new IllegalArgumentException("senha não pode ser nula.");


        int tamanho = password.length();
        if (tamanho < 6 || tamanho > 12)
            throw new IllegalArgumentException("tamanho inválido");

        boolean temMaiuscula = false;
        boolean temNumero = false;

        for (char c : password.toCharArray()) {
            if (Character.isUpperCase(c)) temMaiuscula = true;
            if (Character.isDigit(c)) temNumero = true;
        }

        if (!temMaiuscula) {
            throw new IllegalArgumentException("não possui letra maiuscula");
        }
        if (!temNumero) {
            throw new IllegalArgumentException("não possui número.");
        }
            return true;

    }
}