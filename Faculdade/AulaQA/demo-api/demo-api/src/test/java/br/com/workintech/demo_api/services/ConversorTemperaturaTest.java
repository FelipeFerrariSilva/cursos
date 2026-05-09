package br.com.workintech.demo_api.services;

import org.junit.jupiter.api.Test;
import static org.assertj.core.api.Assertions.*;

public class ConversorTemperaturaTest {

    @Test
    public void converterParaCelsius(){
        ConversorTemperatura conv = new ConversorTemperatura();
        double resultado = conv.celsius(37.8);

        assertThat(resultado)
                .isNotNegative()
                .isEqualTo(100.04);
    }

    @Test
    public void converterParaFahrenheit(){
        ConversorTemperatura conv = new ConversorTemperatura();
        double resultado = conv.fahrenheit(100.04);

        assertThat(resultado)
                .isNotNegative()
                .isEqualTo(37.8);
    }
}
