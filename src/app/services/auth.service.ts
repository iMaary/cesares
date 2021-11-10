import { AngularFirestore } from '@angular/fire/compat/firestore';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AuthService {

  isLoggedIn = false;

  constructor(
    public fireAuth: AngularFireAuth,
    public fireStore: AngularFirestore
    ) { }

  signIn(email: string, password: string) {
    return this.fireAuth.signInWithEmailAndPassword(email, password);
  }
  signUp(email: string, password: string) {
    return this.fireAuth.createUserWithEmailAndPassword(email, password);
  }
  saveDetails(data) {
    return this.fireStore.collection('users').doc(data.uid).set(data);
  }
  getDetails(data) {
    return this.fireStore.collection('users').doc(data.uid).valueChanges();
  }
}
