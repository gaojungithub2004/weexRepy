import Vue from 'vue';

import weex from 'weex-vue-render';

import Weexford from '../src/index';

weex.init(Vue);

weex.install(Weexford)

const App = require('./index.vue');
App.el = '#root';
new Vue(App);
