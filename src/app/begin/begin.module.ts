import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { BeginPageRoutingModule } from './begin-routing.module';

import { BeginPage } from './begin.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    BeginPageRoutingModule
  ],
  declarations: [BeginPage]
})
export class BeginPageModule {}
