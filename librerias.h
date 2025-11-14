#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

void gotoxy(int x, int y){
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X=x;
	dWPos.Y=y;
	SetConsoleCursorPosition(hcon,dWPos);
}

enum MENU{OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6};
int opc=0, x=0, y=0;
const char usuarioid[]="12345";
const char contraid[]="56789";

struct Empleado{
	int id_empleado;
	char direccion[40];
	char email[20];
	char nombre[20];
	char telefono[12];
	char rol_registra[4];
	char rol_entrega[4];
};

struct Entrega{
	int id_entrega;
	int id_empleado;
	char estado[20];
	char id_paquete[10];
};

struct Paquete{
	char id_paquete[8];
	char id_cliente[4];
	char direccion_entrega[20];
	char nombre[20];
	char palabra_clave[10];
};

int tamestruc=10;
char text[]="";
int val=0, cont=0;
int *pval=&val, *pcont=&cont;


Empleado emp[]={100,"R�o Gandalla #463","juanito@gmail.com","Juanito P�rez","4442234000","1","1",
				101,"R�o Verde #342","marinela@gmail.com","Marinela Barcel","4442130500","1","1",
				102,"Vereda Gandalla #563","ayato@gmail.com","Ayato Kamisato","4442314060","1","0",
				103,"R�o Santiago #754","kaede@gmail.com","Kaede Shinamura","4442031500","0","0",
				104,"Ciudad Valles #758","padre@gmail.com","Padre Santos","4442003160","1","1",
				105,"Villa de Pozos #686","camelia@gmail.com","Camelia Yuki","4442000317","0","1",
				106,"16 de septiembre #078","fernando@gmail.com","Fernando VI","4442700381","1","0",
				107,"5 de mayo #575","chrome@gmail.com","Chrome Bad","4442003090","0","1",
				108,"Tlaxcala #234","suika@gmail.com","Suika Sinta","4442030100","1","0",
				109,"Juli�n carrillo #486","senku@gmail.com","Senku Nitche","4442301000","0","1"};

Entrega ent[]={68954,100,"Activo","PAQ123",
				24312,101,"Activo","PAQ124",
				34563,102,"Activo","PAQ125",
				48567,103,"Activo","PAQ126",
				94546,104,"Activo","PAQ127",
				15637,105,"Activo","PAQ128",
				93626,106,"Activo","PAQ129",
				23456,107,"Activo","PAQ130",
				77562,108,"Activo","PAQ131",
				53466,109,"Activo","PAQ132"};

#include "Librerias/prototipos.h"
#include "Librerias/menu.h"
#include "Librerias/validaciones.h"
#include "Librerias/decorarh.h"
#include "Librerias/estructuras.h"
#include "Librerias/archivo.h"
