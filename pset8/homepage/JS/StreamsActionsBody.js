function playPause1(){
	var video = document.getElementById("dota2Video");
	if(video.paused){
		video.play();
	}else {
		video.pause();
	}
}
function playPause2() {
	var video = document.getElementById("wowVideo");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
function playPause3() {
	var video = document.getElementById("csgoVideo");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
function playPause4() {
	var video = document.getElementById("fortniteVideo");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
function playPausevideoDotaTwo1() {
	var video = document.getElementById("dotaTwo1");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
function playPausewow1() {
	var video = document.getElementById("wow1");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
function playPauseCsgo1() {
	var video = document.getElementById("csgo1");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
function playPauseFortnite1() {
	var video = document.getElementById("fortnite1");
  if (video.paused) {
    video.play();
  } else {
    video.pause();
  }
}
$("document").ready(function(){
	$("#dropArrow1").on("click",function(){
		$("#dotaTwo1Content").slideToggle();
	});
	$("#dropArrow2").on("click",function(){
		$("#wow1Content").slideToggle();
	});
	$("#dropArrow3").on("click",function(){
		$("#csgo1Content").slideToggle();
	});
	$("#dropArrow4").on("click",function(){
		$("#fortnite1Content").slideToggle();
	});
});
function articleOneTransition(){
	var x = document.getElementById("articleOne");
	x.style.transitionDuration = "0.2s";
}
function articleTwoTransition(){
	var x = document.getElementById("articleTwo");
	x.style.transitionDuration = "0.2s";
}

function articleThreeTransition(){
	var x = document.getElementById("articleThree");
	x.style.transitionDuration = "0.2s";
}

function articleFourTransition(){
	var x = document.getElementById("articleFour");
	x.style.transitionDuration = "0.2s";
}