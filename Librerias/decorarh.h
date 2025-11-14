void portada(){
    int aux=0;
    FILE *archivo=fopen("Assets/portada.txt","r");
    for(int i=0; i<26;i++){
        for(int j=0; j<50; j++){
            fscanf(archivo,"%d\t",&aux);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),aux);
            printf("%c",178);
        }
        printf("\n");
    }
    fclose(archivo);
}

void datos(){
    setlocale(LC_CTYPE,"Spanish");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    gotoxy(70,10);
    printf("Universidad Polit�cnica de San Luis Potos�");
    gotoxy(70,11);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("Programaci�n I Lenguaje C");
    gotoxy(70,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("Proyecto Final Paqueter�a");
    gotoxy(70,13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("M�dulo 2");
    gotoxy(70,14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("Julieta Palacio Torres");
    gotoxy(70,15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("Matr�cula: 183485");
    gotoxy(70,16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    printf("Presione cualquier tecla para comenzar...");
    getchar();
}
