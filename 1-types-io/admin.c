#include <ctype.h>
#include <math.h>
#include <stdio.h>
int main() {
  char firstName[] = "Tayu";
  char lastName[] = "Lo";
  char gender = 'm';
  int birthYear = 1954;
  int birthMonth = 7;
  int birthDay = 20;
  char weekday[] = "Tuesday";
  int cScore = 50;
  int musicScore = 99;
  int medicineScore = 78;
  int meanScore = (musicScore + medicineScore + cScore) / 3.0;
  double stddiv =
      sqrt((pow(cScore - meanScore, 2) + pow(medicineScore - meanScore, 2) +
            pow(musicScore - meanScore, 2)) /
           3.0);
  int rank = 10;
  printf("%s $s\t %c\n%d-%d-%d \t %.3s\n", "C=%d\t Music=%d\t Medicinie=%d\n",
         firstName, lastName, toupper(gender), birthYear, birthMonth, birthDay,
         weekday);
  return 0;
}
