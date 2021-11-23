import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { Register4Page } from './register4.page';

const routes: Routes = [
  {
    path: '',
    component: Register4Page
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class Register4PageRoutingModule {}
