import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { Register6PageRoutingModule } from './register6-routing.module';

import { Register6Page } from './register6.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    Register6PageRoutingModule
  ],
  declarations: [Register6Page]
})
export class Register6PageModule {}
