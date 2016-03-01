/*lsferreira programming */
var userChoice = prompt("Do you choose rock, paper or scissors?");
var computerChoice = Math.random();

if (computerChoice < 0.34) {
	computerChoice = "rock";}
	else if(computerChoice <= 0.67) {
	computerChoice = "paper";}
	else {
	computerChoice = "scissors";}

console.log("User: " + userChoice);
console.log("Computer: " + computerChoice);
console.log("");

var compare = function(userChoice, computerChoice) {
    if(userChoice === computerChoice) {
        return "tie";
    }
		else return "";
};

console.log(compare);
