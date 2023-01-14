#include <stdio.h>
#include <pic14/pic12f675.h>

/* Inicialización de perifericos y MCU
Configuración ** deshabilitar reset y watchdog timer con macros */ 
typedef unsigned int word;
word __at 0x2007 __CONFIG =  (_MCLRE_OFF & _WDTE_OFF & _BODEN_OFF); 

void delay(unsigned inttiempo); // Acá se define la función del tiempo de espera

void main(void) 				// Función principal 
{
	// **Condiciones en registros
	TRISIO = 0b00000000; 		// pines como salidas 
	GPIO = 0b00100000;   		// terminales en 0
	ANSEL = 0;			// Canales analogicos como Dig
	CMCON = 0x07;			    
	unsigned int time1 = 150;   // Tiempo de espera antes de apagar la configuración de los leds

	
	while (1)
	{	
		unsigned int counter = 1;	// se define contador
		while (1)
		{
			if (GP5 == 0x01){     // contador para que sostenga un  número 
				counter ++;
				if (counter == 7){  //número aleatorio entre 1 y 6
					counter = 0;
					counter ++;
				}	
			} else { if (GP5 == 0x00){ // Al presionar bottón se configura la salida de los leds
				if (counter == 1){      
					GP1 = ~GP1;
					delay(time1);		// Llamada a condición de espera
					GPIO = 0x20;
					
					//// Para mostrar el dos, tres, cuatro, cinco y seis en la configuración de leds
				
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


