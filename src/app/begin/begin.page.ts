import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-begin',
  templateUrl: './begin.page.html',
  styleUrls: ['./begin.page.scss'],
})
export class BeginPage {

  constructor(private router: Router) { }

  init() {
    this.router.navigateByUrl('register')
  } 

}
