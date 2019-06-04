let add = (a, b) => a + b;
add(7, 6);

type person = {
  name: string,
  age: int,
  height: int,
};

let personA = {name: "Agata", age: 19, height: 170};
let personB = {name: "Tomek", age: 21, height: 190};
let personC = {name: "Piotr", age: 93, height: 160};

let showInfo = ({name, age, height}) => {
  print_endline({j|Name: $name,Age: $age,Height: $height|j});
};

showInfo(personA);

let peronList = [personA, personB, personC];



let myQuestion:Question.question = {
  text: "Czy Ala ma kota",
  answers: [{id: A, text: "Tak"}, {id: B, text: "Nie"},{id: C, text: "Nie wiem"},{id:D,text:"Żadne z powyższych"}],
  correctAnswer:A
};
let check = (Answer.answer,myQuestion.correctAnswer)=>{

}