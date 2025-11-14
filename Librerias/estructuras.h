void imprimirEmpleado(){
	setlocale(LC_CTYPE,"Spanish");
	printf("\n\n-----------------Empleados-----------------\n\n");
	for(int i=0; i<tamestruc; i++){
		printf("\nId empleado: %d",emp[i].id_empleado);
		printf("\tNombre: %s",emp[i].nombre);
		printf("\tDirección: %s",emp[i].direccion);
		printf("\tTeléfono: %s",emp[i].telefono);
		printf("\tEmail: %s",emp[i].email);
		printf("\tRol registra: %s",emp[i].rol_registra);
		printf("\tRol entrega: %s",emp[i].rol_entrega);
	}
}

void imprimirEntrega(){
	setlocale(LC_CTYPE,"Spanish");
	printf("\n\n-----------------Entregas-----------------\n\n");
	for(int i=0; i<tamestruc; i++){
		printf("\nId entrega: %d",ent[i].id_entrega);
		printf("\tEstado: %s",ent[i].estado);
		printf("\tId paquete: %s",ent[i].id_paquete);
		printf("\tId empleado: %d",ent[i].id_empleado);
	}
}

Empleado agregaremp(Empleado registro){
	
	registro.id_empleado=numrand(100,899);
	printf("Id empleado: %d\n",registro.id_empleado);
	validaCadena("Nombre: ",registro.nombre,20);
	validaCadena("Dirección: ",registro.direccion,40);
	validaTel(registro.telefono);
	validaMail(registro.email);
	system("cls");
	printf("Rol registra:");
	if(rol(0)==true){
		strcpy(registro.rol_registra,"0");
	}else{
		strcpy(registro.rol_registra,"1");
	}
	printf("\n\nRol  entrega:");
	if(rol(3)==true){
		strcpy(registro.rol_entrega,"0");
	}else{
		strcpy(registro.rol_entrega,"1");
	}

	fflush(stdin);
	
	return registro;
}

Entrega agregarent(Entrega registro){
	registro.id_entrega=numrand(10000,89999);
	printf("Id entrega: %d\n",registro.id_entrega);
	strcpy(registro.estado,"Activo");
	printf("Estado: %s\n",registro.estado);
	sprintf(registro.id_paquete, "PAQ%d", numrand(100,899));
	printf("Id paquete: %s\n",registro.id_paquete);
	registro.id_empleado=selectEmp();
	printf("Id empleado: %d\n",registro.id_empleado);
	
	return registro;
}
