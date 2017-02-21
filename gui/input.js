// Start the Rust Engine
var parse = require('./parse')
var spawn = require('child_process').spawn;
var engine = spawn('./engine.exe')

engine.stdout.on('data', function (data) {
  data += ''
  data.split('\n').filter(i => i).forEach(parse)
})
