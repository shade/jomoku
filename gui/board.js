var Board = new Vue({
  el: '#gomoku',
  data: {
    squares: [],
    thinking: false,
    ready: false,
    status: ''
  }
})

AI = true
'.'.repeat(225).split('').map(() => {
  Board.squares.push({
    active: false,
    value: '',
    black: false,
    white: false,
    evaluated: false
  })
})

Board.activate = function (sq, me) {
  if (sq.active) return
  sq.active = true
  sq[(Board.$data.thinking?'black':'white')] = true 
  Board.$data.thinking = !Board.$data.thinking
  sendBoardState()
}


Board.clear = ()  => {
  Board.$data.squares.forEach(i => {
    i.active = false
    i.white = false
    i.black = false
    i.evaluated = false
    i.value = ''
  })
}



function sendBoardState() {
  // Create the boardstate an array of strings.
  var stateArr = Board.$data.squares.map((sq) => {
    return (sq.active
    ? (sq.white
      ? 'O'
      : 'X')
    : '0')
  })

  // Add the newline to submit the thing.
  stateArr.push('\n')

  // Send the board state to the engine.
  engine.stdin.write(stateArr.join(''))
}






































