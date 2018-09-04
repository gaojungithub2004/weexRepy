/* globals alert */
const weexford = {
  show () {
    alert('Module weexford is created sucessfully ');
  }
};

const meta = {
  weexford: [{
    lowerCamelCaseName: 'show',
    args: []
  }]
};

function init (weex) {
  weex.registerModule('weexford', weexford, meta);
}

export default {
  init: init
};
