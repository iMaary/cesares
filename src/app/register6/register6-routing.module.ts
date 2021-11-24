import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { Register6Page } from './register6.page';

const routes: Routes = [
  {
    path: '',
    component: Register6Page
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class Register6PageRoutingModule {}
