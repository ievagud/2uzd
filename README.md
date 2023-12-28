# pirmasProjektas

# **v1.1**

||Nuskaitymas|Rūšiavimas|Išskirstymas|Vargšiukų išvedimas|Kietakų išvedimas|
|-------------|-------------|-------------|-------------|-------------|-------------|
|100tūkst.||||||
|V1.0|2.32|0.59|0.15|0.33|0|
|V1.1|1.41|0.11|0.04|0.15|0|
|1mln.||||||
|V1.0|18.07|6.08|1.24|2.25|0|
|V1.1|14.46|1.31|0.36|1.58|0|
|100tūkst. O1||||||
|V1.0|1.18|0.39|0.08|0.14|0|
|V1.1|1.51|0.12|0.04|0.22|0|
|1mln. O1||||||
|V1.0|13.65|4.33|0.92|1.58|0|
|V1.1|17.32|1.40|0.36|1.92|0|
|100tūkst. O2||||||
|V1.0|1.24|0.37|0.09|0.15|0|
|V1.1|1.32|0.14|0.04|0.15|0|
|1mln. O2||||||
|V1.0|13.29|4.31|0.82|1.57|0|
|V1.1|14.62|1.35|0.35|1.63|0|
|100tūkst. O3||||||
|V1.0|1.25|0.35|0.09|0.15|0|
|V1.1|1.35|0.14|0.04|0.15|0|
|1mln. O3||||||
|V1.0|13.33|4.30|0.84|1.57|0|
|V1.1|14.50|1.27|0.38|1.62|0|

V1.1 (naudojant class Studentas ir list konteinerį) veikia greičiau nei V1.0 (naudojant Studentas struktūrą, vector konteinerį ir studentų skirstymo algoritmus). Tačiau pritaikius flag'us O1, O2, O3 V1.1 sulėtėja visose atliekamose funkcijose. V1.0 naudojant flag'us pagreitėja. Palyginus V1.1 ir V1.0 veikimą pritaikant flag'us, failo nuskaitymas ir vargšiukų išvedimas į failą V1.1 yra lėtesnis palyginus su V1.0, bet studentų rūšiavimas ir išskirstymas į grupes V1.1 vyksta greičiau nei V1.0. Kadangi failo nuskaitymas yra daugiausiai laiko trunkanti funkcija, efektyviausia būtų naudoti V.1.0 su O2 flag'u.


# **v1.2**

v1.2 atsiranda įvedimo ir išvedimo (input/output) operatoriai. Įvedimo operatorius panaudojamas vietoje funkcijos įvesk. Išvedimo - spausdinant kiekvieną studentą spausdintiLentele funkcijoje. Rule of three: yra destruktorius (destructor), kopijavimo kontruktorius (copy constructor) ir priskyrimo operatorius (copy assignment operator).

# **v1.5**

v1.5 realizuota abstrakti klasė Zmogus, bandant kurti jos objektą, gauname klaidą: cannot declare variable 'humanObject' to be of abstract type 'Zmogus'

<img width="591" alt="image" src="https://github.com/ievagud/2uzd/assets/144427953/414e78a2-0c68-45dc-ae7c-051a212d79dc">

Taip pat yra klasė Studentas, kuri yra išvestinė (derived) iš klasės Zmogus.

# **v3.0**

v3.0 sukurti setup.exe ir ProgramInstallSetup.msi failai. Instaliavus programą, ją galima paleisti iš Start Menu arba darbalaukio. Per setup.exe failą taip pat galima tvarkingai išinstaliuoti programą.  

# Naudojimosi instrukcija

Vartotojui norint naudotis programa, jis turi atsisiųsti ProgramInstallSetup.msi ir setup.exe failus, bei instaliuoti programą, atidarius setup.exe. Vartotojas turi pasirinkti, kur bus instaliuojama programa. Kur vartotojas pasirinks instaliuoti programą, ten pat bus saugomi sugeneruoti failai. Jei bus norima naudoti programą failams nuskaityti, nuskaitomi failai turės būti laikomi toje pačioje vietoje, kur buvo instaliuota programa. Instaliavus, vartotojas gali paleisti programą iš darbalaukio arba iš Start Menu. Paleidus programą, vartotojas turi 3 pasirinkimus:

**1 Pasirinkimas**

Spausti 1, jei norite nuskaityti duomenis iš failų ir atlikti skaičiavimus (atlikti funkcijų veikimo laiko matavimus). Pasirinkus šį kelią, vartotojo prašoma pasirinkti dar kartą:

- Spausti 1, jei norite sugeneruoti failus, juos nuskaityti ir atlikti laiko skaičiavimus. Vartotojui pasirinkus šį variantą,  jis turi pasirinkti pagal ką rūšiuoti rezultatus (1 - pagal vardą, 2 - pagal pavardę, 3 - pagal galutinį balą). Tuomet sugeneruojami 2 studentų failai: 1000.txt, 10000.txt.. Po to jie yra nuskaitomi, išskirstomi pagal studentų pažymius į kitus du naujus failus kietakai.txt ir vargšiukai.txt. Kiekvienam pradiniam failui sukuriama po du vargšiukų ir kietakų failus.

- Spausti 2, jei norite nuskaityti jau egzistuojančius failus ir atlikti laiko skaičiavimus. Tuomet vartotojo prašoma įvesti failų pavadinimus, kuriuos norės nuskaityti. Galima įvesti kelis failus. Įvedimas baigiasi, kai vartotojas vietoje failo pavadinimo įveda 0. Taip pat reikia įvesti pagal ką norima rūšiuoti galutinius rezultatus (1 - pagal vardą, 2 - pagal pavardę, 3 - pagal galutinį balą). Tuomet vyksta įvestų failų nuskaitymas, išskirstymas pagal pažymius, naujų failų (vargšiukai, kietakai) sukūrimas.

**2 Pasirinkimas**
  
Spausti 2, jei norite įvesti duomenis ranka. Vartotojui paspaudus 2, reikia įvesti studento vardą, pavardę, tuomet pasirinkti ar sugeneruoti namų darbų ir egzamino pažymius atsitiktinai (1), ar jie bus įvedami ranka (0). Baigus įvesti vieno studento duomenis, galima vesti kito studento duomenis arba įvesti 0 ir tuomet įvedimas baigiasi. Toliau vartotojo prašoma pasirinkti su kuo skaičiavus išspausdinti galutinį pažymį, su vidurkiu (1), su mediana (2). Galiausiai išspausdinama lentelė  su studento duomenimis.

**3 Pasirinkimas**

Spausti 3, jei norite nuskaityti failą ir išspausdinti duomenis ekrane. Paspaudus 3, vartotojo prašoma įvesti failo, kurį nori nuskaityti pavadinimą. Tuomet reikia pasirinkti su kuo skaičiuoti galutinį balą: su vidurkiu (1), su mediana (2). Galiausiai  įvestas failas yra nuskaitomas ir išspausdinamas ekrane.

