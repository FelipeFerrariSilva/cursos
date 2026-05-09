package br.com.workintech.api.services;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

public class PasswordValidatorTest {
    @ParameterizedTest
    @ValueSource(strings ={"abcABC123", "ABC123!@#", "abc!@#123ACB"})
    public void deveTestarUmaSenhaValida(String password){
        boolean resultado = PasswordValidator.isValid(password);

        assertThat(resultado).isTrue();
    }

    @Test
    public void deveTestarSenhaEmBranco(){
        assertThatThrownBy(() -> PasswordValidator.isValid(null))
            .isInstanceOf(IllegalArgumentException.class)
                .hasMessageContaining("senha não pode ser nula");
    }

    @ParameterizedTest
    @ValueSource(strings ={"Abc12", "a", "1", "Abc123456qwew", "ieugfuywrfykubdkuhrefvauyvfeuyv12asdD"})
    public void deveTestarSenhaComTamanhoInvalido(String password){
        assertThatThrownBy(() -> PasswordValidator.isValid(password))
        .isInstanceOf(IllegalArgumentException.class)
                .hasMessageContaining("tamanho inválido");
    }
}
