import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register6',
  templateUrl: './register6.page.html',
  styleUrls: ['./register6.page.scss'],
})
export class Register6Page {

  constructor(private router: Router) { }

  next() {
    this.router.navigateByUrl('register3')
  }

  back() {
    this.router.navigateByUrl('register')
  }

}
