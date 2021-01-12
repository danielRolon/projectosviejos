#include <game/maths.h>

#define PI 3.14159

float degreesToRad(float degrees)
{
    return (degrees * 180 / PI);
}

float normalizeAngle(float angle)
{
	float PIx2 = PI*2;  // pi en 360°
	float piresult = 0; // se le suma pix2 cada iteracion

	bool done = false;  // done
	int count = 0;      // count

	if (angle >= 0)
	{
		while(!done)
		{
			if (piresult + PIx2 > angle)
			{
				done = true;
			}
			piresult += PIx2;
			count++;
		}

		angle = angle - PI * count;

		return angle;
	}
	else
	{
		angle = PIx2 + angle;

		return angle;
	}
}