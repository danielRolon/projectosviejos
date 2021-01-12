class Line
{
	constructor(x, y, x2, y2)
	{
		this.x = x;
		this.y = y;
		this.x2 = x2;
		this.y2 = y2;
	}

	draw(ctx, color)
	{
		ctx.lineWidth = 5;
		ctx.beginPath();
		ctx.strokeStyle = color;
		ctx.moveTo(this.x, this.y);
		ctx.lineTo(this.x2, this.y2);
		ctx.stroke();
	}

	collision(other)
	{
		const uA = ((other.x2-other.x)*(this.y-other.y) - (other.y2-other.y)*(this.x-other.x)) / ((other.y2-other.y)*(this.x2-this.x) - (other.x2-other.x)*(this.y2-this.y));
		const uB = ((this.x2-this.x)*(this.y-other.y)   - (this.y2-this.y)*(this.x-other.x))   / ((other.y2-other.y)*(this.x2-this.x) - (other.x2-other.x)*(this.y2-this.y));
	
		return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) ? true : false;
	}
}

class Polygon
{
	constructor(lines = new Array(), x, y)
	{
		this.lines = lines;
		this.x = x;
		this.y = y;

		this.angle = 35;
	}

	hipotenuse(co, ca)
	{
		return Math.sqrt(co*co - ca*ca);
	}

	lineRepos(i)
	{
		var cLine = this.lines[i]; // Alias
		var line = new Line(cLine.x, cLine.y, cLine.x2, cLine.y2); // Copy line // new Line(cLine.x, cLine.y, cLine.x2, cLine.y2); 

		var co = cLine.x2;
		var ca = cLine.y2;

		line.x  = this.x + Math.cos(this.angle) * 25;//this.hipotenuse(co, ca);
		line.y  = this.y - Math.sin(this.angle) * 25;//this.hipotenuse(co, ca);
		line.x2 = this.x + 25 + Math.cos(this.angle + Math.PI/2) * 25;//this.hipotenuse(co, ca);
		line.y2 = this.y + 25 - Math.sin(this.angle + Math.PI/2) * 25;//this.hipotenuse(co, ca);

		return line;
	}

	draw(ctx, color)
	{this.angle+=0.1;
		for (let i = 0; i < this.lines.length; ++i)
		{
			this.lineRepos(i).draw(ctx, color);
		}
	}

	collision(other)
	{
		for (let i = 0; i < this.lines.length; ++i)
		{
			for (let j = 0; j < other.lines.length; ++j)
			{
				if (this.lineRepos(i).collision(other.lineRepos(j) ) )
					return true;
			}
		}

		return false;
	}
}