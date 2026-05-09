package br.com.workintech.demo_api.services;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class ConversorTemperatura {

    public double celsius(double c){
        double result = (c * 9 / 5) + 32;
        return new BigDecimal(result).setScale(2, RoundingMode.HALF_UP).doubleValue();

    }

    public double fahrenheit(double f){
        double result = (f - 32) * 5 / 9;
        return new BigDecimal(result).setScale(2, RoundingMode.HALF_UP).doubleValue();
    }
}
