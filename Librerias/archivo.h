void impresionEmp(Empleado registro){
	printf("%d\t",registro.id_empleado);
	printf("%s\t",registro.nombre);
	printf("%s\t",registro.direccion);
	printf("%s\t",registro.telefono);
	printf("%s\t",registro.email);
	printf("%s\t",registro.rol_registra);
	printf("%s\n",registro.rol_entrega);
}

void impresionEnt(Entrega registro){	
	printf("%d\t",registro.id_entrega);
	printf("%s\t",registro.estado);
	printf("%s\t",registro.id_paquete);
	printf("%d\n",registro.id_empleado);
}

void crearArchEmpleado(){
	setlocale(LC_CTYPE,"Spanish");
	FILE *arch=NULL;
	if(!(arch=fopen("Assets/empleado.xls","w"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	for(int i=0; i<tamestruc; i++){
		fprintf(arch,"%d\t",emp[i].id_empleado);
		fprintf(arch,"%s\t",emp[i].nombre);
		fprintf(arch,"%s\t",emp[i].direccion);
		fprintf(arch,"%s\t",emp[i].telefono);
		fprintf(arch,"%s\t",emp[i].email);
		fprintf(arch,"%s\t",emp[i].rol_registra);
		fprintf(arch,"%s\n",emp[i].rol_entrega);
	}
	fclose(arch);
}

void crearArchEntrega(){
	setlocale(LC_CTYPE,"Spanish");
	FILE *arch=NULL;
	if(!(arch=fopen("Assets/entrega.xls","w"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	for(int i=0; i<tamestruc; i++){
		fprintf(arch,"%d\t",ent[i].id_entrega);
		fprintf(arch,"%s\t",ent[i].estado);
		fprintf(arch,"%s\t",ent[i].id_paquete);
		fprintf(arch,"%d\n",ent[i].id_empleado);
	}
	fclose(arch);
}

void leerArchEmpleado(){
	FILE *arch=NULL;
	Empleado registro={};
	if(!(arch=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEmpleado();
		leerArchEmpleado();
	}
	printf("\n\n-------Registros en el archivo-------\n\n");
	while(!feof(arch)){
		fscanf(arch,"%d\t",&registro.id_empleado);
		fscanf(arch,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
		fscanf(arch,"%[^\t]\t",registro.direccion);
		fscanf(arch,"%s\t",registro.telefono);
		fscanf(arch,"%s\t",registro.email);
		fscanf(arch,"%s\t",registro.rol_registra);
		fscanf(arch,"%s\n",registro.rol_entrega);		
		impresionEmp(registro);
	}
	fclose(arch);
}

void leerArchEntrega(){
	FILE *arch=NULL;
	Entrega registro={};
	if(!(arch=fopen("Assets/entrega.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEntrega();
		leerArchEntrega();
	}
	printf("\n\n-------Registros en el archivo-------\n\n");
	while(!feof(arch)){
		fscanf(arch,"%d\t",&registro.id_entrega);
		fscanf(arch,"%[^\t]\t",registro.estado);
		fscanf(arch,"%s\t",registro.id_paquete);
		fscanf(arch,"%d\n",&registro.id_empleado);		
		impresionEnt(registro);
	}
	fclose(arch);
}

void agregarArchEmpleado(){
	setlocale(LC_CTYPE,"Spanish");
	FILE *arch=NULL;
	Empleado registro={};
	
	do{
		registro=agregaremp(registro);	
	}while(!(validaEmpleado(registro.id_empleado,registro.telefono,registro.email)));
	
	if(!(arch=fopen("Assets/empleado.xls","a+"))){
		printf("Error al intentar agregar registro en archivo");
		exit(1);
	}
	
	printf("\nRegistro agregado\n");

	fprintf(arch,"%d\t",registro.id_empleado);
	fprintf(arch,"%s\t",registro.nombre);
	fprintf(arch,"%s\t",registro.direccion);
	fprintf(arch,"%s\t",registro.telefono);
	fprintf(arch,"%s\t",registro.email);
	fprintf(arch,"%s\t",registro.rol_registra);
	fprintf(arch,"%s\n",registro.rol_entrega);

	fclose(arch);
}

void agregarArchEntrega(){
	setlocale(LC_CTYPE,"Spanish");
	FILE *arch=NULL;
	Entrega registro={};
	
	do{
		registro=agregarent(registro);
	}while(!(validaEntrega(registro.id_entrega,registro.id_paquete)));
	
	if(!(arch=fopen("Assets/entrega.xls","a+"))){
		printf("Error al intentar agregar regsitro en archivo");
		exit(1);
	}
	
	printf("\nRegistro agregado\n");

	fprintf(arch,"%d\t",registro.id_entrega);
	fprintf(arch,"%s\t",registro.estado);
	fprintf(arch,"%s\t",registro.id_paquete);
	fprintf(arch,"%d\n",registro.id_empleado);

	fclose(arch);
}

void buscarArchEmpleado(int opcion, const char text[], int id_registro){
	FILE *arch=NULL;
	Empleado registro={};
	bool existe=true;
	
	
	if(!(arch=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEmpleado();
		buscarArchEmpleado(opcion,text,id_registro);
	}
	
	printf("\n\n-------Registros en el archivo-------\n\n");
	while(!feof(arch)){
		fscanf(arch,"%d\t",&registro.id_empleado);
		fscanf(arch,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
		fscanf(arch,"%[^\t]\t",registro.direccion);
		fscanf(arch,"%s\t",registro.telefono);
		fscanf(arch,"%s\t",registro.email);
		fscanf(arch,"%s\t",registro.rol_registra);
		fscanf(arch,"%s\n",registro.rol_entrega);		
		switch(opcion){
			case OPC1:
				if(id_registro==registro.id_empleado){
					existe=false;
					impresionEmp(registro);
				}
			break;
			case OPC2:
				if(strcmp(text,registro.rol_entrega)==0){
					existe=false;
					impresionEmp(registro);
				}				
			break;
			case OPC3:				
				if(strcmp(text,registro.rol_registra)==0){
					existe=false;
					impresionEmp(registro);
				}				
			break;
			case OPC4:
				if(strcmp(text,registro.telefono)==0){
					existe=false;
					impresionEmp(registro);					
				}				
			break;
			case OPC5:				
				if(strcmp(text,registro.email)==0){
					existe=false;
					impresionEmp(registro);
				}
			break;			
		} 
	}
	
	if(existe){
		printf("No existe el registro :(\n");
	} 

	fclose(arch);
}

void buscarArchEntrega(int opcion,int id){
	FILE *arch=NULL;
	Entrega registro={};
	bool existe=true;
	
	if(!(arch=fopen("Assets/entrega.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEntrega();
		buscarArchEntrega(opcion,id);
	}
	
	printf("\n\n-------Registros en el archivo-------\n\n");
	
	while(!feof(arch)){
		fscanf(arch,"%d\t",&registro.id_entrega);
		fscanf(arch,"%[^\t]\t",registro.estado);
		fscanf(arch,"%s\t",registro.id_paquete);
		fscanf(arch,"%d\n",&registro.id_empleado);		
		//usar un if para hacer las b�squedas
		/*
		Num entrega
		estado
		*/
		switch(opcion){
			case OPC1:				
				if(id==registro.id_entrega){
					existe=false;
					impresionEnt(registro);
				}
			break;
			case OPC2:				
				if(strcmp(registro.estado,"Activo")==0){
					existe=false;
					impresionEnt(registro);
				}
			break;
			case OPC3:				
				if(strcmp(registro.estado,"En proceso")==0){
					existe=false;
					impresionEnt(registro);
				}
			break;
			case OPC4:				
				if(strcmp(registro.estado,"Entregado")==0){
					existe=false;
					impresionEnt(registro);
				}
			break;	
		}
		 
	}
	
	if(existe){
		printf("No existe el registro :(\n");
	} 

	fclose(arch);
}

void modificarEmpleado(int id_empleado,int opcion){
	setlocale(LC_CTYPE,"Spanish");
	Empleado registro={};
	FILE *arch1=NULL;
	FILE *arch2=NULL;
	bool encontrado=false;
	
	if(!(arch1=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEmpleado();
		modificarEmpleado(id_empleado,opcion);
	}
	if(!(arch2=fopen("Assets/copia.xls","a+"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	
	while(!feof(arch1)){
		fscanf(arch1,"%d\t",&registro.id_empleado);
		fscanf(arch1,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
		fscanf(arch1,"%[^\t]\t",registro.direccion);
		fscanf(arch1,"%s\t",registro.telefono);
		fscanf(arch1,"%s\t",registro.email);
		fscanf(arch1,"%s\t",registro.rol_registra);
		fscanf(arch1,"%s\n",registro.rol_entrega);		
		if(registro.id_empleado==id_empleado){
			encontrado=true;
			printf("\nDatos actuales del empleado\n\n");
			impresionEmp(registro);
			switch(opcion){
				case OPC1://direcci�n
				validaCadena("Direcci�n: ",registro.direccion,40);
				break;
				case OPC2://tel�fono
				validaTel(registro.telefono);
				break;
				case OPC3://email
				validaMail(registro.email);
				break;
				case OPC4://rol registra
				printf("\nRol registra:");
				if(rol(11)==true){
					strcpy(registro.rol_registra,"0");
				}else{
					strcpy(registro.rol_registra,"1");
				}
				break;
				case OPC5://rol entrega
				printf("\nRol  entrega:");
				if(rol(11)==true){
					strcpy(registro.rol_entrega,"0");
				}else{
					strcpy(registro.rol_entrega,"1");
				}
				break;
			}			
		}
		fprintf(arch2,"%d\t",registro.id_empleado);
		fprintf(arch2,"%s\t",registro.nombre);
		fprintf(arch2,"%s\t",registro.direccion);
		fprintf(arch2,"%s\t",registro.telefono);
		fprintf(arch2,"%s\t",registro.email);
		fprintf(arch2,"%s\t",registro.rol_registra);
		fprintf(arch2,"%s\n",registro.rol_entrega);
	}
	if(!encontrado){
		printf("\nNo existe el registro :(\n");
	}else{
		printf("\nRegistros actualizados\n");
	}
	fclose(arch1);
	fclose(arch2);
	remove("Assets/empleado.xls");
	rename("Assets/copia.xls","Assets/empleado.xls");
}

void modificarEntrega(int id_entrega,int opcion){
	setlocale(LC_CTYPE,"Spanish");
	Entrega registro={};
	FILE *arch1=NULL;
	FILE *arch2=NULL;
	bool encontrado=false;
	
	if(!(arch1=fopen("Assets/entrega.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEntrega();
		modificarEntrega(id_entrega,opcion);
	}
	if(!(arch2=fopen("Assets/copia.xls","a+"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	
	while(!feof(arch1)){
		fscanf(arch1,"%d\t",&registro.id_entrega);
		fscanf(arch1,"%[^\t]\t",registro.estado);
		fscanf(arch1,"%s\t",registro.id_paquete);
		fscanf(arch1,"%d\n",&registro.id_empleado);		
		if(id_entrega==registro.id_entrega){
			encontrado=true;
			printf("\nDatos actuales de la entrega\n\n");
			impresionEnt(registro);
			switch(opcion){
				case OPC1://en proceso
				if((strcmp(registro.estado,"En proceso")==0)||(strcmp(registro.estado,"Entregado")==0)){
					printf("No se puede modificar a este estado\n");
				}else{
					strcpy(registro.estado,"En proceso");
					printf("\nRegistros actualizados\n");
				}
				break;
				case OPC2://entregados
				if((strcmp(registro.estado,"Entregado")==0)||(strcmp(registro.estado,"Activo")==0)){
					printf("No se puede modificar a este estado");
				}else{
					strcpy(registro.estado,"Entregado");
					printf("\nRegistros actualizados\n");
				}
				break;
			}
		}
		fprintf(arch2,"%d\t",registro.id_entrega);
		fprintf(arch2,"%s\t",registro.estado);
		fprintf(arch2,"%s\t",registro.id_paquete);
		fprintf(arch2,"%d\n",registro.id_empleado);
	}
	if(!encontrado){
		printf("\nNo existe el registro :(\n");
	}
	fclose(arch1);
	fclose(arch2);
	remove("Assets/entrega.xls");
	rename("Assets/copia.xls","Assets/entrega.xls");
}

void eliminarEmpleado(int id_empleado){
	setlocale(LC_CTYPE,"Spanish");
	Empleado registro={};
	FILE *arch1=NULL;
	FILE *arch2=NULL;
	bool encontrado=false;
	bool respuesta=false;
	
	if(!(arch1=fopen("Assets/empleado.xls","r"))){
		printf("Error al intentar leer archivo");
		crearArchEmpleado();
		eliminarEmpleado(id_empleado);
	}
	if(!(arch2=fopen("Assets/copia.xls","a+"))){
		printf("Error al intentar a�dir al archivo");
		exit(1);
	}
	
	while(!feof(arch1)){
		fscanf(arch1,"%d\t",&registro.id_empleado);
		fscanf(arch1,"%[^\t]\t",registro.nombre);	//este es para que detecte los espacios al leer las celdas [^\t]
		fscanf(arch1,"%[^\t]\t",registro.direccion);
		fscanf(arch1,"%s\t",registro.telefono);
		fscanf(arch1,"%s\t",registro.email);
		fscanf(arch1,"%s\t",registro.rol_registra);
		fscanf(arch1,"%s\n",registro.rol_entrega);		
		if(id_empleado==registro.id_empleado){
			encontrado=true;
			printf("\nDatos actuales del empleado\n\n");
			impresionEmp(registro);
			respuesta=confirmacion();
			if(respuesta){
				printf("\n\nRegistro eliminado\n");
				continue;
			}			
		}
	
		fprintf(arch2,"%d\t",registro.id_empleado);
		fprintf(arch2,"%s\t",registro.nombre);
		fprintf(arch2,"%s\t",registro.direccion);
		fprintf(arch2,"%s\t",registro.telefono);
		fprintf(arch2,"%s\t",registro.email);
		fprintf(arch2,"%s\t",registro.rol_registra);
		fprintf(arch2,"%s\n",registro.rol_entrega);			
	}
	if(!encontrado){
		printf("\nNo existe el registro :(");
	}
	fclose(arch1);
	fclose(arch2);
	remove("Assets/empleado.xls");
	rename("Assets/copia.xls","Assets/empleado.xls");
}
