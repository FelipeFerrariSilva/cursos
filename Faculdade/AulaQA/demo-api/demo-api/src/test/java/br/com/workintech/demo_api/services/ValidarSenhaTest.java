package br.com.workintech.demo_api.services;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ArgumentsSource;
import org.junit.jupiter.params.provider.ValueSource;

import static org.assertj.core.api.Assertions.*;

public class ValidarSenhaTest {

    @ParameterizedTest
    @ValueSource(strings ={"abcABC123", "ABC123!@#", "abc!@#123ACB"})
    public void deveTestarUmaSenhaValida(String senha){
        boolean resultado = ValidarSenha.validarSenha(senha);

        assertThat(resultado).isTrue();
    }

    @ParameterizedTest
    @ValueSource(strings ={"", "abc123", "ABCabc!@#", "ABC", "abafibuhvfakufbkefkafk"})
    public void deveTestarUmaSenhaInvalida(String senha){
        boolean resultado = ValidarSenha.validarSenha(senha);

        assertThat(resultado).isFalse();
    }

    public void deveTestarUmaSenhaCurta(){
        //CODIGO VAI AQUI

        assertThatCode(() -> ValidarSenha.validarSenha(""))
                .doesNotThrowAnyException();
    }
}