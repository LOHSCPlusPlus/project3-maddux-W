#include "ItemClass.h"
class CerealDB {
public:
CerealDB();
void readCereal();
void printArrayToScreen();
void printArrayToFile(const char fileName[]);
void addCereal();
void delCereal();
void CerealQuestion();
void cerealMenu();
private:
enum{MaxCereal = 500};
Cereal Cereals[MaxCereal];
int numCereal;
};