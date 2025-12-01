// Daiga Leitāne dl25036

// Task 1

function actionlog() {
  const useractions = [];
  
  return function(actiondescription) {
    useractions.push(actiondescription);
    return [...useractions];
  };
}

// Task 2

const english = ['hello', 'goodbye', 'cat', 'dog', 'house', 'car', 'book', 'water', 'friend', 'food', 'sun', 'moon', 'tree', 'city', 'time'];
const latvian = ['čau', 'attā', 'kaķis', 'suns', 'māja', 'mašīna', 'grāmata', 'ūdens', 'draugs', 'ēdiens', 'saule', 'mēness', 'koks', 'pilsēta', 'laiks'];
const regex = /^([\p{L}]+)([.,!?;:]+)?$/u;


// Translate  word

function translateword(word, reverseDirection = false) {
    const source = reverseDirection ? latvian : english;
    const target = reverseDirection ? english : latvian;

    const lower = word.toLowerCase();
    const index = source.findIndex(sw => sw.toLowerCase() === lower);

    return index !== -1 ? target[index] : `?${word}?`;
}


// Translate text

function translatetext(text, reverseDirection = false) {
    const tokens = text.split(/(\s+)/);

    return tokens
        .map(token => {
            if (/^\s+$/.test(token)) return token;

            const match = token.match(regex);
            if (match) {
                const [, word, punctuation = ""] = match;
                return translateword(word, reverseDirection) + punctuation;
            }

            return translateword(token, reverseDirection);
        })
        .join('');
}


// EN -> LV and LV -> EN

const translations = {
    enlv: 'en-lv',
    lven: 'lv-en'
};

function translatedword(word, direction = translations.enlv) {
    let source, target;

    switch (direction.toLowerCase()) {
        case translations.enlv:
            source = english;
            target = latvian;
            break;
        case translations.lven:
            source = latvian;
            target = english;
            break;
        default:
            source = english;
            target = latvian;
    }

    const lower = word.toLowerCase();
    const index = source.findIndex(w => w.toLowerCase() === lower);

    return index !== -1 ? target[index] : `?${word}?`;
}


// Translate text with direction EN↔LV

function direction(text, direction = translations.enlv) {
    const tokens = text.split(/(\s+)/);

    return tokens
        .map(token => {
            if (/^\s+$/.test(token)) return token;

            const match = token.match(regex);
            if (match) {
                const [, word, punctuation = ""] = match;
                return translatedword(word, direction) + punctuation;
            }

            return translatedword(token, direction);
        })
        .join('');
}

// Examples

const log = actionlog();
console.log(log("User has clicked a button"));

console.log(translateword("cat"));
console.log(translateword("suns", true));
console.log(translateword("rainbow"));

console.log(translatetext("hello friend"));
console.log(translatetext("hello friend!"));
console.log(translatetext("čau draugs", true));

console.log(translateword("car", translations.enlv));
console.log(translateword("mašīna", translations.lven));

console.log(direction("hello friend", translations.enlv));
console.log(direction("čau, draugs", translations.lven));
console.log(direction("hello cucumber", translations.enlv));
