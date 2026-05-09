package br.com.workintech.demo_api.controllers;

import br.com.workintech.demo_api.services.Calculator;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class CalculatorController {

    @GetMapping("/")
    public int addNumber(){
        Calculator calc = new Calculator();
        return calc.add(2,2);



    }
}
