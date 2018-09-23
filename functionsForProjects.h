
typedef struct {
    int id;
    char name[25];
    char lastName[15];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;
void swap(int *, int *);
int isOneDigitNumber(int n);
void bubbleSort(int [], int );
void printArray(int [], int );
int getEntero(int *,char [], char [], int ,int, int);
int getFloat(float *pFloat, char msg[], char msgError[], int min, int max, int reintentos);
static int getI(int* );
static float getF(float *);
static char getC(char *);
int getChar(char *, char msg[], char msgError[], char minChar, char maxChar, int reintentos);
int isLetter(char c[]);
void getString(char input[], char msg[]);
int getStringLetras(char input[], char mensaje[], int cant);
int getFreeSpace(eEmployee[],int);
int initEmployees(eEmployee *, int);
int alta(eEmployee[], int);
int isRepeated(eEmployee[], int,int);
int isValidMenu(int n);
int isInit(int flag);
int addEmployee(eEmployee[], int len, int id, char name[],char lastName[],float salary,int sector);