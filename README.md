# OOP_TRECIA_UZDUOTIS
OOP_ANTRA_UZDUOTIS tesinys

----------------------
V1.1 versija
----------------------
Idiegimas:
  * git clone https://github.com/henrikasz1/OOP_TRECIA_UZDUOTIS.git
  * cd OOP_TRECIA_UZDUOTIS/ (arba nueikite i aplanka butent siuo pavadinimu)
 
Patobulinimai:

  * Struct pakeista i Class
  
Pataisyta:

  * Vietoje rand() (considered harmful) naudojami <random> bibliotekos irankiai
  
      random_device rd;
      mt19937 mt(rd());
      uniform_int_distribution<int> dist(1,10);
  
Programos spartos skaiciavimai:
  *Naudojama antra strategija su stable_partition algoritmu, konteineris - std::vector
  
  *Struktura
  
  | Studentu kiekis |   Laikas   |
  |-----------------|------------|
  |    100000(100k) |  4090.93ms |
  |   1000000(1mln) |  43545.9ms |
