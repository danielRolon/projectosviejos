class EntSys
{
	constructor()
	{
		this.systems = Array();
		this.cntEnt = 0;
	}

	update()
	{
		for (let i = 0; i < this.systems.length; ++i)
		{
			this.systems[i].update();
		}
	}

	addEnt()
	{
		return ++this.cntEnt;
	}

	remEnt(idEnt)
	{
		// Buscar todos los componentes con el id y eliminarlos
	}

	addSys(system)
	{
		this.systems.push(system);
	}

	addCmp(component, idEnt)
	{
		for (let i = 0; i < this.systems.length; ++i)
		{
			let system = this.systems[i];

			if (component.type == system.type)
			{
				system.components.push(component);
				return component;
			}
		}
	}

	remCmp(type, idEnt)
	{
		for (let i = 0; i < this.systems.length; ++i)
		{
			let system = this.systems[i];

			if (type == system.type)
			{
				for (let j = 0; j < system.components.length; ++j)
				{
					if (system.components[j].idEnt == idEnt)
					{
						system.components.splice(j, 1);
					}
				}
			}
		}
	}

	getCmp(type, idEnt)
	{
		for (let i = 0; i < this.systems.length; ++i)
		{
			let system = this.systems[i];

			if (type == system.type)
			{
				for (let j = 0; j < system.components.length; ++j)
				{
					let cmp = system.components[j];

					if (cmp.idEnt == idEnt)
					{
						return cmp
					}
				}
			}
		}
	}


}