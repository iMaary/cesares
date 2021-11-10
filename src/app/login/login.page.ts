import { AuthService } from './../services/auth.service';
import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.page.html',
  styleUrls: ['./login.page.scss'],
})
export class LoginPage implements OnInit {

  public email: string;
  public password: string;

  constructor(
    private router: Router,
    private authService: AuthService
    ) { }

  ngOnInit() {
  }

  login(){
    this.authService.signIn(this.email, this.password).then(res=>{
      console.log(res);
      if(res.user.uid){
        // eslint-disable-next-line @typescript-eslint/no-shadow
        this.authService.getDetails({uid:res.user.uid}).subscribe(res=>{
          console.log(res);
          // eslint-disable-next-line @typescript-eslint/dot-notation
          alert('Welcome '+ res['name']);
        },err=>{
          console.log(err);
        });
        this.router.navigateByUrl('home');
      }
    },err=>{
      alert(err.message);
      console.log(err);
    });
  }
  signUp(){
    this.authService.signUp(this.email, this.password).then(res=>{
      if(res.user.uid){
        const data = {
          email:this.email,
          password:this.password,
          uid:res.user.uid
        };
        this.authService.saveDetails(data).then(res2=>{
         alert('Account Created!');
        },err=>{
          console.log(err);
        });
      }
    },err=>{
      alert(err.message);

      console.log(err);
    });
  }

}
