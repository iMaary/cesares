import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register2',
  templateUrl: './register2.page.html',
  styleUrls: ['./register2.page.scss'],
})
export class Register2Page {

  constructor(private router: Router) { }

  next() {
    this.router.navigateByUrl('register3')
  }

  back() {
    this.router.navigateByUrl('register')
  }

}
