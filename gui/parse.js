
// This is the module to process the stdout data.
module.exports = function (data) {
  // Initialize command and data variables.
  var command
  var data
  // Extract the actual stuff from the data.
  [command, data] = data.split(':')
  
  // Run the appropriate function for the command.
  Events[command](data)
}


var Events = {}

// Ouputs a comment from the engine.
Events.COMMENT = (data) => {
  console.log(data)
  Board.$data.status = data
}

// Delete the ready.
Events.READY = (data) => {
  Board.$data.ready = true
}

// Add the values to the appropriate place on the board.
Events.VALUE = (data) => {
  // Initialize the variables for the square
  var location
  var value

  // Grab, the variables from the event data.
  [location, value] = JSON.parse(data)
  console.log(data)

  // Set the board appropriately.
  Board.$data.squares[location].value = value
}
