import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register5',
  templateUrl: './register5.page.html',
  styleUrls: ['./register5.page.scss'],
})
export class Register5Page {

  constructor(private router: Router) { }

  next() {
    this.router.navigateByUrl('register3')
  }

  back() {
    this.router.navigateByUrl('register')
  }

}
