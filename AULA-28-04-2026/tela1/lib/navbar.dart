import 'package:flutter/material.dart';

class Navbar extends StatefulWidget {
  const Navbar({super.key});

  @override
  State<Navbar> createState() => _NavbarState();
}

class _NavbarState extends State<Navbar> {
  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: Column(
        children: [
          Expanded(
            flex: 5,
            child: Container(
              width: double.infinity,
              color: Colors.amberAccent,
            ),
          ),

          Expanded(
            flex: 9,
            child: Container(
              width: double.infinity,
              color: Colors.purple,
            ),
          ),
        ],
      ),
    );
  }
}