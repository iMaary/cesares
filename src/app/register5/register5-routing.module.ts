import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { Register5Page } from './register5.page';

const routes: Routes = [
  {
    path: '',
    component: Register5Page
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class Register5PageRoutingModule {}
