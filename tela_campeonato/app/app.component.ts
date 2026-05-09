import { Component } from '@angular/core';
import { ReservaComponent } from './reserva/reserva.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [ReservaComponent],
  template: '<app-reserva></app-reserva>',
  styles: [],
})
export class AppComponent {}
