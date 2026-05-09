import 'package:flutter/material.dart';
import 'package:tela1/navbar.dart';

class NavbarSceen extends StatefulWidget {
  const NavbarSceen({super.key});

  @override
  State<NavbarSceen> createState() => _NavbarSceen();
}

class _NavbarSceen extends State<NavbarSceen>{
  @override
  Widget build(BuildContext context){
    return Scaffold(
      drawer: Navbar(),
      appBar: AppBar(
        backgroundColor: Colors.blueAccent,
        foregroundColor: Colors.white,
        title: Center(child: Text("Exemplo NavBar"),),
      ),
    );
  }
}