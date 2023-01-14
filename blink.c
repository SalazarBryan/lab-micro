//#include <pic14/pic12f683.h>
#include <pic14/pic12f675.h>
//#define _LEGACY_HEADERS
//#define _MCLRE_OFF 0x3FDF
//#define _WDTE_OFF 0x3FF7  

#define LOOP?WAIT?LIMIT 100 

// Inicialización de perifericos y MCU
// Configuración ** deshabilitar reset y watchdog timer con macros
typedef unsigned int word;
word __at 0x2007 __CONFIG =  (_MCLRE_OFF & _WDTE_OFF & _BODEN_OFF); 

void delay(unsigned inttiempo); // Acá se define la función del tiempo de espera

void main(void) // Función principal para la ejecución de acciones
{
	// ** Establecimiento de las condiciones en registros
	TRISIO = 0b00000000; // Poner todos los pines como salidas 
	GPIO = 0b00100000;   // Poner pines en bajo; terminales en 0
	ANSEL = 0;			 // Canales analogicos como E/S digitales
	CMCON = 0x07;			 // Apagar comparadores
	unsigned int time1 = 400;   // Tiempo de espera antes apagar
	unsigned int time = 100;

	// Loop forever
	while (1)
	{	
		unsigned int counter = 1;	
		while (1){
			  if (GP5 == 0x01){ // Hacemos el contador para que retire numero aleatorio
				counter ++;
				if (counter == 6){
					counter = 1;
					counter ++;
					GP0 = ~GP0;
					GP1 = ~GP1;
					GP2 = ~GP2;
					GP4 = ~GP4;
				}	
			  } else { if (GP5 == 0x00){
				
				if (counter == 1){
					GP1 = ~GP1;
					delay(time1);
					GPIO = 0x20;
					
				} if (counter == 2){
					GP2 = ~GP2;
					delay(time1);
					GPIO = 0x20;
					
				} if (counter == 3){
					GP2 = ~GP2;
					GP1 = ~GP1;
					delay(time1);
					GPIO = 0x20;
					
				} if (counter == 4){
					GP0 = ~GP0;
					GP2 = ~GP2;
					delay(time1);
					GPIO = 0x20;
					
				} if (counter == 5){
					GP0 = ~GP0;
					GP1 = ~GP1;
					GP2 = ~GP2;
					delay(time1);
					GPIO = 0x20;
					
				} if (counter == 6){
					GP0 = ~GP0;
					GP2 = ~GP2;
					GP4 = ~GP4;
					delay(time1);
					GPIO = 0x20;
				}
			  }
			}
		}
	}
}

void delay(unsigned int tiempo) // Función para imprimir delay
{
	unsigned int i;
	unsigned int j;

	for (i = 0; i < tiempo; i++)
		for (j = 0; j < 1275; j++)
			;
}

