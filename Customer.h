struct customer
{
    int cod;
    char name[50];
    int cpf;
    int age;
    int ofAge;
    struct customer *next,*prev;
};
typedef struct customer Customer;

struct sentC
{
    Customer *first;
    Customer *last;
};
typedef struct sentC SentinelC;

Customer *getMemoryC(Customer cli);
void registerCustomer(SentinelC *st, Customer cli);
void printCustomers(Customer *cli, SentinelC *sr);