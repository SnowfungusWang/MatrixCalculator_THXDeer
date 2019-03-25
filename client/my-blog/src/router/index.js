import Vue from 'vue'
import Router from 'vue-router'
import Login from '../views/login/index';
import Hello from '../components/HelloWorld';
import photos from '../views/photos/index';

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'Login',
      component: Login
    },
    {
      path: '/hello',
      name: 'hello',
      component: Hello
    },
    {
      path: '/photo',
      name: 'photo',
      component: photos
    }
  ]
})
