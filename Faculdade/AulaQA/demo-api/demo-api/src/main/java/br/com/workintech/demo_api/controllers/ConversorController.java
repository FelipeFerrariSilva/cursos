package br.com.workintech.demo_api.controllers;

import br.com.workintech.demo_api.services.ConversorTemperatura;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ConversorController {

    @GetMapping("/")
    public double converterParaF(){
        ConversorTemperatura conv = new ConversorTemperatura();
        return conv.celsius(37.8);

    }

    public double converterParaC(){
        ConversorTemperatura conv = new ConversorTemperatura();
        return conv.fahrenheit(100.04);
    }
}
