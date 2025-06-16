#Arduino-merjenje-temperature

OPIS: S to napravo bomo lahko merili temperaturo z dvema različnima NTC uporoma, zato, da vemo bolj natančno kakšna je približna vrednost in kakšno odstopanje. Za referenco bomo uporabili DEWE 43A in TP-202 senzor, kar je najbolj natančna naprava, ki jo imamo za merjenje temperature in bomo, zato primerjali izmerjeno temperaturo z NTC upori z temperaturo, ki jo je izmeril DEWE 43A. Upora bomo povezali preko žice, da bo lahko odmaknjena od ostalih komponent za bolj natančno merjenje. Da pa bomo videli kakšna je temperatura bomo v program Arduino IDE napisali takšo kodo, da nam bo na našem LCD zaslonu izpisovalo temperaturo za oba NTC upora isto časno in v pravilnih enotah.

KOSOVNICA:
1x Arduino UNO R3,
2x NTC upora,
2x upora med 1kE in 100kE
Žičke,
1x perfBoard,
2x pleksi ploščica velikosti 10x14 cm,
1x LCD 16x2 zaslon,
8x vijaki,
18x matic,
27x distančnikov

SLIKA VEZALNE SHEME IZ EASYEDA IN SLIKA VEZJA:
![image](https://github.com/user-attachments/assets/726aa355-66f8-4086-b216-40c8238b7304)
![image](https://github.com/user-attachments/assets/e833f1a1-2881-43de-90af-26cccf32a283)
https://github.com/user-attachments/assets/7fdafb73-2ac7-44a1-8fd7-e4426ec53358


Komentar: Prvi termistor je bolj natančen kot drugi termistor. Razlogov zato je lahko več, eni izmed njih so lahko nenatančna kalibracija ter površno merjenje. Definitivno bi lahko izboljšala kalibracijo obeh termistorjev saj največja izmerjena napaka pri prvem termistorju je +4/-4 stopinje celzija pri drugem pa +6,2/-6,2 stopinj celzija. To pomeni, da naprava ni dovolj zanesljiva da bi jo lahko uporabljali za vsakdanjo uporabo. Ohišje bi lahko tudi bilo nadgrajeno v 3D printano škatlo, da skrije vse žice, ki sva jih uporabila in zmanjšala bi se možnost, da katera od žic izgubi kontakt, ker bi jo lahko kdo butnil. Za kalibracijo sva uporabila od ToolCrafta napravo za vroči zrak je pa težava, ker ni pihal po obeh termistorjih ter TP-202 senzorju enakomerno zato so bila velika odstopanja in bi bila potrebna izboljšava, kar se tiče umerjanja. Sva pa uporabila tudi led katerega smo se samo dotaknili z konicami termistorjev ter konico TP-202 senzorja.
