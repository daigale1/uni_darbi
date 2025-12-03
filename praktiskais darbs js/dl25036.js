// Daiga Leitāne dl25036

// Task 1 
function actionlog() {
  const actions = [];
  
  return function(action) {
    actions.push(action);
    return [...actions];
  };
}

// Task 2 

const english = ['hello', 'goodbye', 'cat', 'dog', 'car', 'website', 'homework', 'friend', 'food', 'programming', 'computer'];
const latvian = ['čau', 'attā', 'kaķis', 'suns', 'mašīna', 'mājaslapa', 'mājasdarbs', 'draugs', 'ēdiens', 'programmēšana', 'dators'];

// Translate a word
function translateword(word, from = 'en', to = 'lv') {
  const source = from === 'en' ? english : latvian;
  const target = to === 'lv' ? latvian : english;
  
  const lowercase = word.toLowerCase();
  const index = source.findIndex(sourceWord => sourceWord.toLowerCase() === lowercase);
  
  return index !== -1 ? target[index] : `?${word}?`;
}

// Translate text
function translatetext(text, from = 'en', to = 'lv') {
  return text.split(' ').map(word => {

    if (/[.,!?;:]$/.test(word)) {
      const fullword = word.slice(0, -1); 
      const punctuation = word.slice(-1);
      return translateword(fullword, from, to) + punctuation;
    }
    
    return translateword(word, from, to);
  }).join(' ');
}

// Examples
const logger = actionlog();
console.log(logger("User clicked button"));

console.log(translateword("cat")); 
console.log(translateword("Cat")); 
console.log(translateword("rainbow")); 

console.log(translatetext("Hello friend!")); 
console.log(translatetext("Hello cat, goodbye dog.", 'en', 'lv')); 

console.log(translateword("kaķis", 'lv', 'en')); 
console.log(translatetext("Čau draugs!", 'lv', 'en'));
