$("document").ready(function(){
	$("#unicorn").on("click", function(){
		$("#heartsContent").fadeIn(function(){
			setTimeout(function() { $("#heartsContent").fadeOut() }, 00);
		});
	});
});
$("document").ready(function(){
	$("#dropDown1").on("click",function(){
		$("#content1").slideToggle("2000");
	});
});
$("document").ready(function(){
	$("#dropDown2").on("click",function(){
		$("#content2").slideToggle("2000");
	});
});
$("document").ready(function(){
	$("#dropDown3").on("click",function(){
		$("#content3").slideToggle("2000");
	});
});
