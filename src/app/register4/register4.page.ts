import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register4',
  templateUrl: './register4.page.html',
  styleUrls: ['./register4.page.scss'],
})
export class Register4Page {

  constructor(private router: Router) { }

  next() {
    this.router.navigateByUrl('register3')
  }

  back() {
    this.router.navigateByUrl('register')
  }

}
