# OOP_TRECIA_UZDUOTIS
OOP_ANTRA_UZDUOTIS tesinys

[Senesniu versiju changelog](https://github.com/henrikasz1/OOP_TRECIA_UZDUOTIS/blob/master/README.md)
----------------------
V1.1 versija
----------------------
Idiegimas:

  `git clone https://github.com/henrikasz1/OOP_TRECIA_UZDUOTIS.git`
  
  `cd OOP_TRECIA_UZDUOTIS/ (arba nueikite i aplanka butent siuo pavadinimu)`
 
Patobulinimai:

  * Struct pakeista i Class
  
Pataisyta:

  * Vietoje rand() (considered harmful) naudojami < random > bibliotekos irankiai
  
           random_device rd;
      
           mt19937 mt(rd());
      
           uniform_int_distribution<int> dist(1,10);
  
Programos spartos skaiciavimai:

   * Naudojama antra strategija su stable_partition algoritmu, konteineris - std::vector
  
  
  
  ------------------------------------------------------------------------------------------
   * Struktura                            
 
  | Studentu kiekis |   Laikas   |         
  |-----------------|------------|          
  |    100000(100k) |  4090.93ms |          
  |   1000000(1mln) |  43545.9ms |          
  
  * Klase
  
  | Studentu kiekis |   Laikas   |
  |-----------------|------------|
  |    100000(100k) |  3905.98ms |
  |   1000000(1mln) |  40512.9ms |
  
  * Klase su flag 01
  
  | Studentu kiekis |   Laikas   |
  |-----------------|------------|
  |    100000(100k) |  3437.27ms |
  |   1000000(1mln) |  38653.6ms |
  
  * Klase su flag 02
  
  | Studentu kiekis |   Laikas   |
  |-----------------|------------|
  |    100000(100k) |  3421.64ms |
  |   1000000(1mln) |  36279.3ms |
  
  * Klase su flag 03
  
  | Studentu kiekis |   Laikas   |
  |-----------------|------------|
  |    100000(100k) |  3406.02ms |
  |   1000000(1mln) |  33722.7ms |
  
--------------------------------------------------------------------------------------------

Isvada:
 * Laikas naudojant struktura ir klase yra panasus, skirtumai labai minimalus, taciau naudojant klase, programos kodas tapo daug lengviau skaitomas ir koreguojamas
 * Galime pastebeti, kad naudojant flag'us, programos sparta padideja, geriausi rezultatai isgauti naudojant 03 flag'a (zinoma, tai taip pat priklauso ir nuo kompiliatoriaus)
  
