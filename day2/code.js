var readline = require('readline');
var rl = readline.createInterface(
    {input : process.stdin, output : process.stdout, terminal : false});

var part1State = {
  map : [ 
          "00000",
          "01230", 
          "04560", 
          "07890", 
          "00000" 
        ],
  output : "",
  pos : [ 2, 2 ] // Start from '5'
};

var part2State = {
  map : [
          "0000000",
          "0001000",
          "0023400",
          "0567890",
          "00ABC00",
          "000D000",
          "0000000"
        ],
  output : "",
  pos : [ 3, 1 ] // Start from '5'
};

var directions = {
  'L' : [ 0, -1 ],
  'R' : [ 0, 1 ],
  'U' : [ -1, 0 ],
  'D' : [ 1, 0 ]
};

var processLine = function(state, line) {
  for (var i = 0; i < line.length; ++i) {
    var dir = directions[line[i]];
    var newpos = [ state.pos[0] + dir[0], state.pos[1] + dir[1] ];
    if (state.map[newpos[0]][newpos[1]] != 0) {
      state.pos = newpos;
    }
  }
  state.output += state.map[state.pos[0]][state.pos[1]];
};

rl.on('line', function(line) {
  processLine(part1State, line);
  processLine(part2State, line);
});

rl.on('close', function() {
  console.log("Part 1: " + part1State.output);
  console.log("Part 2: " + part2State.output);
});
