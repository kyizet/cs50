function transitionEffects(){
	var x = document.getElementById("article1");
	var y = document.getElementById("article2");
	x.style.transitionDuration = "0.2s";
	y.style.transitionDuration = "0.2s";
}

function loadingY(){
	var y = document.getElementById("article2");
	y.style.transitionDuration = "0.5s";
	y.style.transform = "scale(2.5)";
	y.style.opacity = "0";
}


function loadingX(){
	var x = document.getElementById("article1");
	x.style.transitionDuration = "0.5s";
	x.style.transform = "scale(2.5)";
	x.style.opacity = "0";
}