// Daiga Leitāne dl25036

document.addEventListener('DOMContentLoaded', 

//getting elements
function () { 
var genre = document.getElementById('genre-list'); 
var language = document.getElementById('language-list'); 
var rating = document.getElementById('rating-list'); 
var runtime = document.getElementById('runtime-list'); 
var yearFrom = document.getElementById('year-from'); 
var yearTo = document.getElementById('year-to'); 
var button = document.querySelector('.btn-primary'); 
var movieList = document.getElementById('movie-list'); 

list(); 
//clicking the button runs the function
button.onclick = filter; 

var sortRadios = document.getElementsByName('sort-order'); 
for (var i = 0; i < sortRadios.length; i++) { 
    sortRadios[i].onchange = filter; 
} 
show(movies); 

function list() { 
    var g = []; 
    var l = []; 
    var r = []; 
    //loops through movies and splits movies using a comma, trims extra space and adds only if it wasnt previously added
    for (var i = 0; i < movies.length; i++) { 
        var movie = movies[i]; 
        var mg = movie.Genre.split(','); 
        
        for (var j = 0; j < mg.length; j++) { 
            var mgt = mg[j].trim(); 
            if (g.indexOf(mgt) === -1) g.push(mgt); } 
            
        var ml = movie.Language.split(','); 

        for (var j = 0; j < ml.length; j++) { 
            var mlt = ml[j].trim(); 
            
            if (l.indexOf(mlt) === -1) l.push(mlt); } 
            if (movie.Rated && movie.Rated !== 'N/A') { 
                if (r.indexOf(movie.Rated) === -1) r.push(movie.Rated); 
            } 
        } 
//creates the options for users to choose
for (var i = 0; i < g.length; i++) genre.add(new Option(g[i], g[i])); 
for (var i = 0; i < l.length; i++) language.add(new Option(l[i], l[i])); 
for (var i = 0; i < r.length; i++) rating.add(new Option(r[i], r[i])); 

} 

function filter() { 
    var from = parseInt(yearFrom.value); 
    var to = parseInt(yearTo.value); 

    if (from && to && from > to) { alert('Year range is wrong'); return; }
    if (from < 1900) { alert('Starting year is wrong'); return; } 
    if (to > 2026) { alert('End year is wrong'); return; }
    // storing movies that have been filtered
    var check = []; 

    for (var i = 0; i < movies.length; i++) { 
        var m = movies[i]; if (genre.value && m.Genre.indexOf(genre.value) === -1) continue; 

        if (language.value && m.Language.indexOf(language.value) === -1) continue;

        if (rating.value && m.Rated !== rating.value) continue; 
        if (runtime.value) {
            //converting into minutes for easier comparison
             var mins = parseInt(m.Runtime) || 0; 
            if (runtime.value === 'short' && mins > 90) continue; 
            if (runtime.value === 'medium' && (mins <= 90 || mins > 150)) continue; 
            if (runtime.value === 'long' && mins <= 150) continue; 
        } 
        
        if (from && m.Year < from) continue; 
        if (to && m.Year > to) continue;
        // adding a movie that has passed all of the filters
        check.push(m); 

    } 

        var sort = null; 
        // for cycle checks which 'radio' is selected and then sorts according to that
        for (var i = 0; i < sortRadios.length; i++) { 
            if (sortRadios[i].checked) sort = sortRadios[i].value; 
        } 

            if (sort === 'title-asc') check.sort(function (a, b) { return a.Title.localeCompare(b.Title); }); 
            if (sort === 'title-desc') check.sort(function (a, b) { return b.Title.localeCompare(a.Title); }); 
            if (sort === 'year-asc') check.sort(function (a, b) { return a.Year - b.Year; }); 
            if (sort === 'year-desc') check.sort(function (a, b) { return b.Year - a.Year; }); 
            show(check); 
        } 
//for displaying movies
function show(arr) { 
    movieList.innerHTML = ''; 
    //if nothing is found
    if (arr.length === 0) { 
        movieList.innerHTML = '<p>No movies found</p>'; return; 
    } 
        //for cycle loops through all of the movies and displays them
        for (var i = 0; i < arr.length; i++) { 
            var m = arr[i]; 
            movieList.innerHTML += 
            '<div class="col-md-3 mb-4">' + 
            '<div class="card h-100">' + 
            '<img src="' + m.Poster + 
            '" class="card-img-top">' + 
            '<div class="card-body">' + 
            '<h5>' + m.Title + '</h5>' + 
            '<p>' + m.Year + '</p>' + 
            '<p>' + m.Genre + '</p>' + 
            '<p>' + m.Language + '</p>' + 
            '<p>' + m.Runtime + '</p>' +
            '</div></div></div>'; 
        } 
    } 
});
