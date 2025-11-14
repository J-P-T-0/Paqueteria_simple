void menuPrincipal(){
	setlocale(LC_CTYPE,"Spanish");
	do{
		system("color 84");
		x=25, y=5;
		system("cls");
		gotoxy(x,y);
		printf("1. Empleado");
		gotoxy(x,++y);
		printf("2. Entrega");
		gotoxy(x,++y);
		printf("3. Salir");
        gotoxy(x,++y);
        menu(22,5,1,3);
        system("cls");
        gotoxy(10,4);
        switch(opc){
            case OPC1:
                printf("Empleado\n");
                submenu1("1. Agregar", "2. Modificar", "3. Consultar", "4. Eliminar", "5. Regresar",1,5,1);
                break;
            case OPC2:
                printf("Entrega\n");
                submenu1("1. Agregar", "2. Consultar", "3. Modificar estado", "4. Regresar", "",1,4,2);
                break;
            case OPC3:
                printf("Hasta la vista baby");
                exit(0);
                break;
        }
	}while(opc!=3);
}

void menu(int x, int y, int inicio, int fin){
    char tecla='\0'; //es lo mismo que ' '
    opc=1;
    int car=62;
    gotoxy(x,y);
    printf("%c",car);
    do{
        if(kbhit()){
            tecla=getch();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),136);
            gotoxy(x,y);
            printf("%c",car);
            if(opc>inicio&&tecla==72){  //flecha arriba
                y--;
                opc--;
            }
            if(opc<fin && tecla==80){   //flecha abajo
                y++;
                opc++;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),132);
            gotoxy(x,y);
            printf("%c",car);
        }
    }while(tecla!=13);  //13-> enter
}

void submenu1(const char uno[], const char dos[], const char tres[], const char cuatro[], const char cinco[], int min, int max, int menua){
    setlocale(LC_CTYPE,"Spanish");
	do{
        system("color 84");
        x=25;
        y=5;
        system("cls");
        gotoxy(x,y);
        printf("%s",uno);
        gotoxy(x,++y);
        printf("%s",dos);
        gotoxy(x,++y);
        printf("%s",tres);
        gotoxy(x,++y);
        printf("%s",cuatro);
        gotoxy(x,++y);
        printf("%s",cinco);
        gotoxy(x,++y);
        menu(22,5,min,max);
        system("cls");
        gotoxy(10,4);
        switch(opc){
            case OPC1:
                printf("%s\n",uno);
                if(menua==1){
                	//printf("...");
                	agregarArchEmpleado();
                	fflush(stdin);
				}else if(menua==2){
					agregarArchEntrega();
					fflush(stdin);
				}
                system("pause");
                break;
            case OPC2:
                printf("%s\n",dos);
                if(menua==1){
                	if(empleado()==true){
                		submenu2("1. Dirección", "2. Teléfono", "3. Email", "4. Rol registra", "5. Rol entrega", "6. Regresar",1,6,1,2);
					}else{
						printf("No existe el id\n");
						system("pause");
					}
				}else if(menua==2){
                	submenu2("1. Número de entrega", "2. Estado", "3. Regresar", "", "", "",1,3,2,2);
				}
                break;
            case OPC3:
                printf("%s\n",tres);
                if(menua==1){
                	submenu2("1. Número de empleado", "2. Teléfono", "3. Email", "4. Rol registra", "5. Rol Entrega", "6. Regresar", 1,6,1,3);
				}else if(menua==2){
					if(entrega()==true){
						submenu2("1. En proceso", "2. Entregados", "3. Regresar", "", "","", 1,3,2,3);
						submenu1("1. Agregar", "2. Consultar", "3. Modificar estado", "4. Regresar", "",1,4,2);					
					}else{
						printf("No existe el id\n");
						system("pause");
					}					
				}
                break;
            case OPC4:
                if(menua==1){
                    if(empleado()==true){
                    	system("cls");
						eliminarEmpleado(val);
					}else{
						printf("No existe el id\n");
						system("pause");
					}
                }
                //system("pause");
                break;
            case OPC5:
                printf("%s\n",cinco);
                system("pause");
                break;
        }
    }while(opc!=max);
}

void submenu2(const char uno[], const char dos[], const char tres[], const char cuatro[], const char cinco[], const char seis[], int min, int max, int menua, int seccion){
    setlocale(LC_CTYPE,"Spanish");
	do{
        system("color 84");
        x=25;
        y=6;
        system("cls");
        if(menua==1){
            if(seccion==2){
                buscarArchEmpleado(1,"",val);
			}					
		}else if(menua==2){
			if(seccion==3){
				buscarArchEntrega(1,val);
			}			
		}
        gotoxy(x,y);
        printf("%s",uno);
        gotoxy(x,++y);
        printf("%s",dos);
        gotoxy(x,++y);
        printf("%s",tres);
        gotoxy(x,++y);
        printf("%s",cuatro);
        gotoxy(x,++y);
        printf("%s",cinco);
        gotoxy(x,++y);
        printf("%s",seis);
        gotoxy(x,++y);
        menu(22,6,min,max);
        system("cls");
        gotoxy(10,4);
        switch(opc){
            case OPC1:
                printf("%s\n",uno);
                if(menua==1){
                	if(seccion==2){
						modificarEmpleado(val,1);
					}else if(seccion==3){
						val=validaEntero("Número de empleado: ",4);
 						buscarArchEmpleado(1,"",val);
					}					
				}else if(menua==2){
					if(seccion==2){
						val=validaEntero("Id entrega: ",6);
						buscarArchEntrega(1,val);
					}else if(seccion==3){
						modificarEntrega(val,1);
					}
				}
                system("pause");
                break;
            case OPC2:
                printf("%s\n",dos);
                if(menua==1){
                	if(seccion==2){
 						modificarEmpleado(val,2);
					}else if(seccion==3){
						validaTel(text);
						buscarArchEmpleado(4,text,0);
					}
				}else if(menua==2){
					if(seccion==2){
						submenu3("1. Activo", "2. En proceso", "3. Entregados", "4. Regresar",1,4);
					}else if(seccion==3){
						modificarEntrega(val,2);
					}
                }
                opc=1;
                system("pause");
                break;
            case OPC3:
                printf("%s\n",tres);
                if(menua==1){
                	if(seccion==2){
 						modificarEmpleado(val,3);
					}else if(seccion==3){
						validaMail(text);
						buscarArchEmpleado(5,text,0);
					}
				}
                system("pause");
                break;
            case OPC4:
                printf("%s\n",cuatro);
                if(menua==1){
                	if(seccion==2){
 						modificarEmpleado(val,4);
					}else if(seccion==3){
						printf("Rol registra:");
						if(rol(7)==true){
							strcpy(text,"0");
						}else{
							strcpy(text,"1");
						}
						buscarArchEmpleado(3,text,0);
					}	
				}
                system("pause");
                break;
            case OPC5:
                printf("%s\n",cinco);
                if(menua==1){
                	if(seccion==2){
 						modificarEmpleado(val,5);
					}else if(seccion==3){
						printf("Rol entrega:");
						if(rol(7)==true){
							strcpy(text,"0");
						}else{
							strcpy(text,"1");
						}
						buscarArchEmpleado(2,text,0);
					}
				}
                system("pause");
                break;
            case OPC6:
                printf("%s\n",seis);
                system("pause");
                break;
        }
    }while(opc!=max);
}

void submenu3(const char uno[], const char dos[], const char tres[], const char cuatro[], int min, int max){
    setlocale(LC_CTYPE,"Spanish");
	do{
        system("color 84");
        x=25;
        y=5;
        system("cls");
        gotoxy(x,y);
        printf("%s",uno);
        gotoxy(x,++y);
        printf("%s",dos);
        gotoxy(x,++y);
        printf("%s",tres);
        gotoxy(x,++y);
        printf("%s",cuatro);
        gotoxy(x,++y);
        menu(22,5,min,max);
        system("cls");
        gotoxy(10,4);
        switch(opc){
            case OPC1:
                printf("%s\n",uno);
                buscarArchEntrega(2,0);
                system("pause");
                break;
            case OPC2:
                printf("%s\n",dos);
                buscarArchEntrega(3,0);
                system("pause");
                break;
            case OPC3:
                printf("%s\n",tres);
                buscarArchEntrega(4,0);
                system("pause");
                break;
            case OPC4:
                printf("%s\n",cuatro);
//                system("pause");
                break;
        }
    }while(opc!=max);
}
