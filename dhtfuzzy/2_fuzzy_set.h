void fuzzySet () {

    // FuzzyInput Suhu
  FuzzyInput *suhu = new FuzzyInput(1);

  suhu->addFuzzySet(dingin);
  suhu->addFuzzySet(hangat);
  suhu->addFuzzySet(panas);
  fuzzy->addFuzzyInput(suhu);

  
  // FuzzyInput Kelembaban
  FuzzyInput *kelembaban = new FuzzyInput(2);

  kelembaban->addFuzzySet(kering);
  kelembaban->addFuzzySet(normal);
  kelembaban->addFuzzySet(basah);
  fuzzy->addFuzzyInput(kelembaban);

  FuzzyOutput *lampu = new FuzzyOutput(1);

  lampu->addFuzzySet(mati);
  lampu->addFuzzySet(nyala);
  fuzzy->addFuzzyOutput(lampu);
}
