#include <stdio.h>
#include <stdlib.h>

int main()
{
	int color, tipo;
	char *colores[8]={"NEGRO", "ROJO", "VERDE", "AMARILLO", "AZUL", "MAGENTA", "CYAN", "BLANCO"};
	
for(tipo=0; tipo<=1; tipo++)
	for(color=30; color<=37; color++)
		printf("\033[%d;%dm%s%s \\033\[%d;%dm\n", tipo, color, colores[(color-30)], tipo?" (negrita)":"", tipo, color);

printf("\033[0m\nRESET \\033\[0m\n\n");

return 0;
}