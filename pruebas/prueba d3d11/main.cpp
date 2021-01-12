#include <iostream>
#include <math.h>
#include <windows.h>
#include <math.h>

#define PI 3.14

#define KEY(x) (bool)GetAsyncKeyState(x)

float normalizeAngle(float angle);

int main()
{
	while (!KEY(VK_ESCAPE))
	{
		float angle = 0;

		std::cout << "Inserte un angulo en grados: ";
		std::cin >> angle;

		angle = angle * PI / 180; // pasar de grados a radianes

		std::cout << "Arctan del angulo: " << atan(angle);
		std::cout << "\n\n\n";
	}
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