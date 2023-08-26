void deffuzifikasi(float aPredikat_notUsed, float aPredikat_kering, float aPredikat_basah, int z1, int z2, int z3){
float hasil;

hasil = ((aPredikat_notUsed * z1)+(aPredikat_kering * z2) + (aPredikat_basah * z3))/(aPredikat_notUsed + (aPredikat_kering) + (aPredikat_basah));
  return hasil;
}
