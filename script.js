// Daiga leitāne dl25036

//storing all books
var books = [];

document.addEventListener('DOMContentLoaded',

function () { 
var form = document.getElementById('book-form'); 
var bookList = document.getElementById('book-list'); 
var sort = document.getElementById('sort'); 
var genreRadios = document.getElementsByName('genre-filter'); 

//selected genre filter, deafult
var currentGenre = 'All'; 

//when 'radio' button changes, currentGenre is updated and show() refreshes the list
for (var i = 0; i < genreRadios.length; i++) { 
    genreRadios[i].onchange = function () { 
        currentGenre = this.value; 
        show(); 
    }; 
} 

sort.onchange = show; 

//form submission
form.onsubmit = function (e) { 
    e.preventDefault(); 

    var ok = true; 
    var yearNow = new Date().getFullYear(); 

	// gets values from input, trims extra spaces
    var cover = document.getElementById('cover').value.trim(); 
    var title = document.getElementById('title').value.trim(); 
    var author = document.getElementById('author').value.trim(); 
    var genre = document.getElementById('genre').value; 
    var input = document.getElementById('year').value; 
    var year = parseInt(input); 

	//clears previous error messages
    var errors = document.querySelectorAll('.error'); 
    for (var i = 0; i < errors.length; i++) errors[i].textContent = ''; 

    if (!cover) { 
        document.getElementById('cover-error').textContent = 'Add cover image'; 
        ok = false; 
	// checks if there is and image extension
    } else if (!/\.(jpg|jpeg|png|gif|svg)$/i.test(cover)) { 
        document.getElementById('cover-error').textContent = 'URL needs to be an image'; 
        ok = false; 
    } 
	//checks if there are any input errors
    if (!title) { 
        document.getElementById('title-error').textContent = 'Title is required'; 
        ok = false; 
    } 

    if (!author) { 
        document.getElementById('author-error').textContent = 'Author is required'; 
        ok = false; 
    } 

    if (!genre) { 
        document.getElementById('genre-error').textContent = 'Select a genre'; 
        ok = false; 
    } 
    if (!input) { 
        document.getElementById('year-error').textContent = 'Year is required'; 
        ok = false; 
    } else if (isNaN(year)) { 
        document.getElementById('year-error').textContent = 'Year must be a number'; 
        ok = false; 
    } else if (year < 1500 || year > yearNow) { 
        document.getElementById('year-error').textContent = 'Year must be between 1500 and ' + yearNow; 
        ok = false; 
    } 
	// if there is an error, function stops
    if (!ok) return; 
	// book is added to the array
    books.push({ 
        id: Date.now(), 
        cover: cover, 
        title: title, 
        author: author, 
        genre: genre, 
        year: year, 
        date: new Date().toISOString() 
    }); 
	// clears from inputs and displays books
    form.reset(); 
    show(); 
}; 
//finds book by id and removes it
window.removeBook = function (id) { 
    for (var i = 0; i < books.length; i++) { 
        if (books[i].id === id) { 
            books.splice(i, 1); 
            break; 
        } 
    } 
    show(); 
}; 

function show() { 
    bookList.innerHTML = ''; 

    if (books.length === 0) { 
        bookList.innerHTML = '<p>No books in collection</p>'; 
        return; 
    } 

    var arr = books; 

    if (currentGenre !== 'All') { 
        arr = []; 
        for (var i = 0; i < books.length; i++) { 
            if (books[i].genre === currentGenre) arr.push(books[i]); 
        } 
    } 

    var s = sort.value; 
	//locale compare for text
    if (s === 'title-asc') arr.sort(function (a, b) { return a.title.localeCompare(b.title); }); 
    if (s === 'title-desc') arr.sort(function (a, b) { return b.title.localeCompare(a.title); }); 
    if (s === 'year-asc') arr.sort(function (a, b) { return a.year - b.year; }); 
    if (s === 'year-desc') arr.sort(function (a, b) { return b.year - a.year; }); 
    if (s === 'date-asc') arr.sort(function (a, b) { return new Date(a.date) - new Date(b.date); }); 
    if (s === 'date-desc') arr.sort(function (a, b) { return new Date(b.date) - new Date(a.date); }); 

    for (var i = 0; i < arr.length; i++) { 
        var b = arr[i]; 
        var d = new Date(b.date).toLocaleString(); 
		// converts into readable text
        bookList.innerHTML += 
        '<div>' + 
        '<img src="' + b.cover + '">' + 
        '<h3>' + b.title + '</h3>' + 
        '<p>Author: ' + b.author + '</p>' + 
        '<p>Genre: ' + b.genre + '</p>' + 
        '<p>Year: ' + b.year + '</p>' + 
        '<p>Added: ' + d + '</p>' + 
        '<button onclick="removeBook(' + b.id + ')">Remove</button>' + 
        '</div>'; 
    } 
} 
});
