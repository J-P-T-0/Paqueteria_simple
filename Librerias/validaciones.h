int validaEntero(const char mensaje[],int tam){
	char numaux[tam]="";
	int num=0;
	bool inicio=true;

		printf("%s",mensaje);
		fgets(numaux,tam,stdin);
		strtok(numaux, "\n");
		fflush(stdin);
		for(int i=0; i<strlen(numaux); i++){
			if(numaux[i]==' '||isalpha(numaux[i])||numaux[i]=='\n'||numaux[i]=='&'){
				break;
			}
			if(i==(strlen(numaux)-1)){
				num=atoi(numaux);
			}
		}

	
	return num;
}

void validaTel(char tel[]){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera=true;
		
	while(bandera){
		printf("Tel�fono: ");
		fgets(tel, 15, stdin);
		strtok(tel,"\n");
		fflush(stdin);
		
		if(strlen(tel)>10||strlen(tel)<10){ 	//esto es para medir tama�o
			printf("\nTama�o incorrecto, tiene que ser de 10\n");
			continue;	//hace que no se ejecute lo que est� abajo y hace que se reinicie el ciclo
		}
				
		for(int i=0; i<strlen(tel);i++){
			if(isalpha(tel[i]) || iscntrl(tel[i])||tel[i]=='&'||ispunct(tel[i])||isspace(tel[i])){
				break;
			}
			if(i==(strlen(tel)-1)){		//si todav�a no llega al tama�o de la cadena
				bandera=false;
			}
		}
		
	}
}

void validaMail(char mail[]){
	SetConsoleCP(1252);	//STDIN codificaci�n de windows 1252 para la entrada de acentos
	SetConsoleOutputCP(1252);	//STDOUT para la salida de acentos
	bool bandera=true;

	while(bandera){
		printf("Email: ");
		fgets(mail, 20, stdin);
		strtok(mail,"\n");
		fflush(stdin);
				
		for(int i=0; i<strlen(mail);i++){
			if(iscntrl(mail[i])||mail[i]=='&'||isspace(mail[i])){
				break;
			}
			if(i==(strlen(mail)-1)){		//si todav�a no llega al tama�o de la cadena
				bandera=false;
			}
		}
		
	}
}

void validaCadena(const char mensaje[], char cadena[], int tam){
	SetConsoleCP(1252);	//STDIN codificaci�n de windows 1252 para la entrada de acentos
	SetConsoleOutputCP(1252);	//STDOUT para la salida de acentos
	
	printf("%s",mensaje);
	fgets(cadena, tam, stdin);
	strtok(cadena,"\n");
	fflush(stdin);
}

bool empleado(){
	system("cls");
    bool inicio=true;
    bool valore=false;
    FILE *arch=NULL;
	Empleado registro={};
	int id=0;


		val=validaEntero("N�mero de empleado: ",4);
		
		if(!(arch=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
			crearArchEmpleado();
		empleado();
		}
		
		while(!feof(arch)){
			fscanf(arch,"%d\t",&registro.id_empleado);
			fscanf(arch,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
			fscanf(arch,"%[^\t]\t",registro.direccion);
			fscanf(arch,"%s\t",registro.telefono);
			fscanf(arch,"%s\t",registro.email);
			fscanf(arch,"%s\t",registro.rol_registra);
			fscanf(arch,"%s\n",registro.rol_entrega);
			
			if(val==registro.id_empleado){
				*pval=val;
				inicio=false;
				valore=true;
				break;
			}
		}
		
		fclose(arch);
	
    return valore;
}

bool entrega(){
	system("cls");
    bool inicio=true;
    bool valore=false;
    FILE *arch=NULL;
	Entrega registro={};
	int id=0;
	
		val=validaEntero("N�mero de entrega: ",6);
		
		if(!(arch=fopen("Assets/entrega.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEntrega();
			entrega();
		}
		
		while(!feof(arch)){
			fscanf(arch,"%d\t",&registro.id_entrega);
			fscanf(arch,"%[^\t]\t",registro.estado);
			fscanf(arch,"%s\t",registro.id_paquete);
			fscanf(arch,"%d\n",&registro.id_empleado);
			
			if(val==registro.id_entrega){
				*pval=val;
				inicio=false;
				valore=true;
				break;
			}
		}
		
		fclose(arch);
			
    return valore;
}

bool confirmacion(){
	printf("\n�Desea eliminar el registro?\n");
	system("color 84");
    x=25;
    y=8;
    gotoxy(x,y);
    printf("S�");
    gotoxy(x,++y);
    printf("No");
	menu(22,8,1,2);
	if(opc==1){
		return true;
	}else{
		return false;
	}
}

bool validaEmpleado(int id_empleado,const char text2[],const char text3[]){
	FILE *arch=NULL;
	Empleado registro={};
	bool existe=true;
	
	if(!(arch=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEmpleado();
		validaEmpleado(id_empleado,text2,text3);
	}
	while(!feof(arch)){
		fscanf(arch,"%d\t",&registro.id_empleado);
		fscanf(arch,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
		fscanf(arch,"%[^\t]\t",registro.direccion);
		fscanf(arch,"%s\t",registro.telefono);
		fscanf(arch,"%s\t",registro.email);
		fscanf(arch,"%s\t",registro.rol_registra);
		fscanf(arch,"%s\n",registro.rol_entrega);		
		
		//modificar para aceptar nums
		if(registro.id_empleado==id_empleado){
			printf("\nId empleado repetido\n");
			existe=false;
			break;
		}			

		if(strcmp(text2,registro.telefono)==0){
			printf("\nTel�fono repetido\n");
			existe=false;
			break;				
		}				

		if(strcmp(text3,registro.email)==0){
			printf("\nEmail repetido\n");
			existe=false;
			break;
		}
	}
	fclose(arch);
	return existe;
}

bool validaEntrega(int id_entrega,const char id_paquete[]){
	FILE *arch=NULL;
	Entrega registro={};
	bool existe=true;
	
	if(!(arch=fopen("Assets/entrega.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEntrega();
		validaEntrega(id_entrega,id_paquete);
	}
	while(!feof(arch)){
		fscanf(arch,"%d\t",&registro.id_entrega);
		fscanf(arch,"%[^\t]\t",registro.estado);
		fscanf(arch,"%s\t",registro.id_paquete);
		fscanf(arch,"%d\n",&registro.id_empleado);			

		if(registro.id_entrega==id_entrega){
			printf("\nId de entrega repetido\n");
			existe=false;
			break;				
		}				

		if(strcmp(id_paquete,registro.id_paquete)==0){
			printf("\nId de paquete repetido\n");
			existe=false;
			break;
		}
		 
	}
	fclose(arch);
	return existe;
}

int numrand(int min, int max){
	srand(time(NULL));
	return min+rand()% max;
}

bool rol(int yi){
	system("color 84");
    x=25;
    y=yi;
    gotoxy(x,y);
    printf("0");
    gotoxy(x,++y);
    printf("1");
	menu(22,yi,1,2);
	if(opc==1){
		return true;
	}else{
		return false;
	}
}

void usuario(){
	bool bandera=true;
	char usu[10]="";
	while(bandera){
		system("cls");
		printf("\nUsuario: ");
		fgets(usu,10,stdin);
		strtok(usu,"\n");
		fflush(stdin);
		if(strcmp(usu,usuarioid)==0){
			bandera=false;
		}else{
			printf("\nUsuario incorrecto\n");
			system("pause");
		}
	}
}

void contrasenia(){
	bool bandera=true;
	char contra[6]="";
	while(bandera){
		system("cls");
		printf("\nContrase%ca: ",164);
		for(int i=0; i<5;i++){
			contra[i]=getch();
			printf("*");
		}
		if(strcmp(contra,contraid)==0){
			bandera=false;
			printf("\n");
			system("pause");
		}else{
			printf("\nContrase%ca incorrecta\n",164);
			system("pause");
		}
	}
	system("cls");
}

int selectEmp(){
	FILE *arch=NULL;
	int counter=0, id=0, num=0;
	Empleado idsemp[1000]={};
	Empleado registro={};
	
	if(!(arch=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEmpleado();
		selectEmp();
	}
	
	while(fscanf(arch,"%d\t",&idsemp[counter].id_empleado)==1){
		//printf("%d\t",idsemp[counter].id_empleado);
		fscanf(arch,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
		fscanf(arch,"%[^\t]\t",registro.direccion);
		fscanf(arch,"%s\t",registro.telefono);
		fscanf(arch,"%s\t",registro.email);
		fscanf(arch,"%s\t",registro.rol_registra);
		fscanf(arch,"%s\n",registro.rol_entrega);
		counter++;
	}
		
	id=numrand(1,counter-1);
	num=idsemp[id].id_empleado;
	
	fclose(arch);

	return num;
}
