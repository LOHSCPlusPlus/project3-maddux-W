#include <fstream>
using namespace std;


class Cereal {
  public:
  Cereal();
  void readCereal2(ifstream &cFile);
  void printCereal(ostream &out);
  void readCerealUser();
  double GetCalories();
  private:
  enum {MAX_CHAR_LEN = 500};
  char name[MAX_CHAR_LEN] = {' '};
  double Calories;
  double Protein;
  double Fat;
  double Sodium;
  double Fiber;
  double Carbs;
  double Sugar;
  double CupsPerServing;
};