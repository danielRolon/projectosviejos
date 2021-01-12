var xMouse = 0;
var yMouse = 0;

var colorCol = "#FF0000";
var colorNor = "#0000FF";

var colorLine = colorNor;

var canvas = document.getElementById('canvas');
var ctx    = canvas.getContext('2d');

canvas.onmousemove = function () {
    xMouse = window.event.clientX;
    yMouse = window.event.clientY;
}

var lines =
[
	new Line(0, 0, 25, 25),
	new Line(25, 25, 0, 50),
	new Line(0, 50, -25, 25),
	new Line(-25, 25, 0, 0)
]

var polygon = new Polygon(lines, 50, 50);
var polygon2 = new Polygon(lines, 50, 50);

function init()
{
	console.log("init");
	loop();
}

function loop()
{
	//update
	canvas.width = canvas.width;

	//draw
	polygon.draw(ctx, colorLine);
	polygon2.draw(ctx, colorNor);

	//move polygon
	polygon.x = xMouse;
	polygon.y = yMouse;

	if (polygon.collision(polygon2)) colorLine = colorCol;
	else 					         colorLine = colorNor;

	//loop
	requestAnimationFrame(loop);
}