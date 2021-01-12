const PhysicsType = "Physics";


class PhyCmp
{
	constructor(idEnt)
	{
		this.x = 0;
		this.y = 0;
		this.vx = 0;
		this.vy = 0;
		this.w = 0;
		this.h = 0;
		this.idEnt = idEnt;
		this.type = PhysicsType;
	}
}

class PhySys
{
	constructor()
	{
		this.components = Array();
		this.type = PhysicsType;
	}

	update()
	{
		for (let i = 0; i < this.components.length; ++i)
		{
			let cmp = this.components[i];

			cmp.x += cmp.vx;
			cmp.y += cmp.vy;
		}
	}

	/*addCmp(idEnt)
	{
		let phyCmp = new PhyCmp(idEnt);
		this.components.push(phyCmp);
		return phyCmp;
	}

	remCmp(idEnt)
	{
		for (let i = 0; i < this.components.length; ++i)
		{
			if (this.components[i].idEnt == idEnt)
			{
				this.components.splice(i, 1);
			}
		}
	}

	getCmp(idEnt)
	{
		for (let i = 0; i < this.components.length; ++i)
		{
			if (this.components[i].idEnt == idEnt)
			{
				return this.components[i];
			}
		}	
	}*/
}