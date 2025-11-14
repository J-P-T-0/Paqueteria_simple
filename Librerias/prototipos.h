//menu.h
void menuPrincipal();
void menu(int, int, int, int);
void submenu1(const char[], const char[], const char[], const char[], const char[], int, int, int);
void submenu2(const char[], const char[], const char[], const char[], const char[], const char[], int, int, int,int);
void submenu3(const char[], const char[], const char[], const char[], int, int);

//validaciones.h
int validaEntero(const char[],int);
//float validaFlotante(const char[]);
void validaCadena(const char[], char[], int);
void validaTel(char[]);
void validaMail(char[]);
bool empleado();
bool entrega();
bool confirmacion();
int numrand(int,int);

bool validaEmpleado(int,const char[],const char[]);
bool validaEntrega(int,const char[]);

bool rol(int);

void usuario();
void contrasenia();

int selectEmp();

//decorar.h
void portada();
void datos();

//estructuras.h
void imprimirEmpleado();
void imprimirEntrega();
Empleado agregaremp(Empleado);
Entrega agregarent(Entrega);

//archivo.h
void impresionEmp(Empleado);
void impresionEnt(Entrega);

void crearArchEmpleado();
void crearArchEntrega();

void leerArchEmpleado();
void leerArchEntrega();

void agregarArchEmpleado();
void agregarArchEntrega();

void buscarArchEmpleado(int,const char[],int);
void buscarArchEntrega(int,int);

void modificarEmpleado(int,int);
void modificarEntrega(int,int);

void eliminarEmpleado(int);
