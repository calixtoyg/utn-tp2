
typedef struct {
    int id;
    char name[25];
    char lastName[15];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;
void swap(int *, int *);
int getEntero(int *,char [], char [], int ,int, int);
int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int reintentos);
static int getI(int* );
static float getF(float *);
static char getC(char *);
int getChar(char *, char msg[], char msgError[], char minChar, char maxChar, int reintentos);
int isLetter(char c[]);
void getString(char input[], char msg[]);
int getStringLettersOnly(char *input, char *mensaje, int cant, int tries);
int getFreeSpace(eEmployee[],int);
int initEmployees(eEmployee *, int);
int isValidMenu(int n,int min, int max);
int addEmployee(eEmployee[], int len, int id, char name[],char lastName[],float salary,int sector);
void printEmployees(eEmployee *, int);
void sortBySectorLastnameAndName(eEmployee *employee, int size, int order);
int findEmployeeById(eEmployee employee[],int elements, int id);
int removeEmployee(eEmployee* list, int range,int id);
int averageSalaries(eEmployee* list, int range);
int employeesAboveAverage(eEmployee* list,int range);
void toUpperLastNameAndName(eEmployee employee[], int cant);
int modifyEmployee(eEmployee[],int range, int id, char name[],char lastName[],float salary,int sector);