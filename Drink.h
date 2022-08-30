struct drink
{
    int cod;
    char name[50];
    float ml;
    float price;
    int stock;
    int alchoolic;
    struct drink *next,*prev;
    
};
typedef struct drink Drink;

struct sent
{
    Drink *first;
    Drink *last;
};
typedef struct sent SentinelD;

Drink *getMemoryD(Drink dr);
void registerDrink(SentinelD *st, Drink dr);
void printDrinks(Drink *dr, SentinelD *sr);
void buyDrinks(SentinelD *st, Drink *dr, int cod);
void sellDrinks(SentinelD *st, Drink *dr, Customer cli, int cod);