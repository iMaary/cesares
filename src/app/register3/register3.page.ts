import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register3',
  templateUrl: './register3.page.html',
  styleUrls: ['./register3.page.scss'],
})
export class Register3Page {

  constructor(private router: Router) { }

  next() {
    this.router.navigateByUrl('register3')
  }

  back() {
    this.router.navigateByUrl('register')
  }

}
