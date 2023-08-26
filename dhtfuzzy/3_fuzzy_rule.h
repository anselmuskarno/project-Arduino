

void fuzzyRule(){
//-----Fuzzy Rule1
FuzzyRuleAntecedent *dingin_kering_1 = new FuzzyRuleAntecedent();
dingin_kering_1->joinWithAND(dingin, kering);

FuzzyRuleConsequent *lampu_nyala1 = new FuzzyRuleConsequent();
lampu_nyala1 ->addOutput(nyala);

FuzzyRule *fuzzyRule1 = new FuzzyRule(1, dingin_kering_1, lampu_nyala1);
fuzzy->addFuzzyRule(fuzzyRule1);

//-----Fuzzy Rule2
FuzzyRuleAntecedent *dingin_normal_2 = new FuzzyRuleAntecedent();
dingin_normal_2 ->joinWithAND(dingin, normal);

FuzzyRuleConsequent *lampu_nyala2 = new FuzzyRuleConsequent();
lampu_nyala2 ->addOutput(nyala);

FuzzyRule *fuzzyRule2 = new FuzzyRule(2, dingin_normal_2, lampu_nyala2);
fuzzy->addFuzzyRule(fuzzyRule2);

//-----Fuzzy Rule3
FuzzyRuleAntecedent *dingin_basah_3 = new FuzzyRuleAntecedent();
dingin_basah_3 ->joinWithAND(dingin, basah);

FuzzyRuleConsequent *lampu_nyala3 = new FuzzyRuleConsequent();
lampu_nyala3 ->addOutput(nyala);

FuzzyRule *fuzzyRule3 = new FuzzyRule(3, dingin_basah_3, lampu_nyala3);
fuzzy->addFuzzyRule(fuzzyRule3);

//-----Fuzzy Rule4
FuzzyRuleAntecedent *hangat_kering_4 = new FuzzyRuleAntecedent();
hangat_kering_4 ->joinWithAND(hangat, kering);

FuzzyRuleConsequent *lampu_nyala4 = new FuzzyRuleConsequent();
lampu_nyala4 ->addOutput(nyala);

FuzzyRule *fuzzyRule4 = new FuzzyRule(4, hangat_kering_4, lampu_nyala4);
fuzzy->addFuzzyRule(fuzzyRule4);

//-----Fuzzy Rule5
FuzzyRuleAntecedent *hangat_normal_5 = new FuzzyRuleAntecedent();
hangat_normal_5 ->joinWithAND(hangat, normal);

FuzzyRuleConsequent *lampu_nyala5 = new FuzzyRuleConsequent();
lampu_nyala5 ->addOutput(nyala);

FuzzyRule *fuzzyRule5 = new FuzzyRule(5, hangat_normal_5, lampu_nyala5);
fuzzy->addFuzzyRule(fuzzyRule5);

//-----Fuzzy Rule6
FuzzyRuleAntecedent *hangat_basah_6 = new FuzzyRuleAntecedent();
hangat_basah_6 ->joinWithAND(hangat, basah);

FuzzyRuleConsequent *lampu_nyala6 = new FuzzyRuleConsequent();
lampu_nyala6 ->addOutput(nyala);

FuzzyRule *fuzzyRule6 = new FuzzyRule(6, hangat_basah_6, lampu_nyala6);
fuzzy->addFuzzyRule(fuzzyRule6);

//-----Fuzzy Rule7
FuzzyRuleAntecedent *panas_kering_7 = new FuzzyRuleAntecedent();
panas_kering_7->joinWithAND(panas, kering);

FuzzyRuleConsequent *lampu_mati7 = new FuzzyRuleConsequent();
lampu_mati7 ->addOutput(mati);

FuzzyRule *fuzzyRule7 = new FuzzyRule(7, panas_kering_7, lampu_mati7);
fuzzy->addFuzzyRule(fuzzyRule7);

//-----Fuzzy Rule8
FuzzyRuleAntecedent *panas_normal_8 = new FuzzyRuleAntecedent();
panas_normal_8->joinWithAND(panas, normal);

FuzzyRuleConsequent *lampu_mati8 = new FuzzyRuleConsequent();
lampu_mati8 ->addOutput(mati);

FuzzyRule *fuzzyRule8 = new FuzzyRule(8, panas_normal_8, lampu_mati8);
fuzzy->addFuzzyRule(fuzzyRule8);

//-----Fuzzy Rule9
FuzzyRuleAntecedent *panas_basah_9 = new FuzzyRuleAntecedent();
panas_basah_9->joinWithAND(panas, basah);

FuzzyRuleConsequent *lampu_mati9 = new FuzzyRuleConsequent();
lampu_mati9 ->addOutput(mati);

FuzzyRule *fuzzyRule9 = new FuzzyRule(9, panas_basah_9, lampu_mati9);
fuzzy->addFuzzyRule(fuzzyRule9);






  
}
