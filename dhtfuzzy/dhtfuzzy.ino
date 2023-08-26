#include <Fuzzy.h>

Fuzzy *fuzzy = new Fuzzy();
//FuzzyInput Suhu
FuzzySet *dingin       = new FuzzySet{0, 0, 30, 35};
FuzzySet *hangat       = new FuzzySet{30, 35, 38, 40};
FuzzySet *panas        = new FuzzySet{38, 40, 45, 45};

//FuzzyInput Kelembaban
FuzzySet *kering       = new FuzzySet{0, 0, 40, 45};
FuzzySet *normal       = new FuzzySet{40, 45, 80, 100};
FuzzySet *basah        = new FuzzySet{80, 100, 130, 130};

// FuzzyOutput
FuzzySet *mati         = new FuzzySet(0, 0, 1, 1);
FuzzySet *nyala        = new FuzzySet(1, 1, 2, 2);
 


#include "2_fuzzy_set.h"
#include "3_fuzzy_rule.h"
int suhu = 24;
int kelembaban = 22;

void setup() {
  Serial.begin(9600);
 fuzzySet ();
 fuzzyRule();  
}

void loop()
{
fuzzy->setInput(1, suhu);
fuzzy->setInput(2, kelembaban);
fuzzy->fuzzify();
float fuzzyLogic = fuzzy->defuzzify(1);
Serial.print("defuzzifikasi: ");
Serial.println(fuzzyLogic);
Serial.println("");

}
