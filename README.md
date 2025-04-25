1. Program został napisany przyśpieszonym algorytmem Verleta bada abstrakcyjne zjawisko manipulacją masy ziemii i pokazania ruchu księżyca w stosunku do tej masy.

   
2.kontrolować tak naprawdę można wszystkie parametry uwzględnione w programie, lecz do pliku config dla użytkownika zostało dodane ustawianie kroku czasowego, długości symulacji i o ile masa ziemii ma się zmniejszać w każdym kroku czasowym, czyli to na czym polegał główny zamysł symulacji.



3.
![Zrzut ekranu 2023-06-22 205353](https://github.com/IS-UMK/project-JonaszPocwiardowski/assets/118118608/9196d3b8-a0f7-4fef-983e-8ecf9f2440ff)
![Zrzut ekranu 2023-06-22 205542](https://github.com/IS-UMK/project-JonaszPocwiardowski/assets/118118608/40292140-8186-4e3c-8f8a-1b3cef796147)
![Zrzut ekranu 2023-06-22 205847](https://github.com/IS-UMK/project-JonaszPocwiardowski/assets/118118608/b28ac345-7187-4de2-9d31-148fbeb9f6f3)
![Zrzut ekranu 2023-06-22 205929](https://github.com/IS-UMK/project-JonaszPocwiardowski/assets/118118608/1317a030-f118-4278-b751-ee9017f9fa40)
![Zrzut ekranu 2023-06-22 205737](https://github.com/IS-UMK/project-JonaszPocwiardowski/assets/118118608/9b73daaa-6e66-4c6a-9ab7-c1462c5b8192)


4.
-stdio.h
-math.h
-stdlib.h



5. na początku ustawiamy w pliku config interesujące nas parametry, zapisujemy plik, kod naszego programu włączamy w jakimś środowisku posiadającym kompilator języka C, kompilujemy i uruchamiamy nasz program, w folderze w którym znajdował się plik z kodem powstanie nowy plik tekstowy posiadający wszystkie nasze dane, od położenia poprzez prędkość i energię.
Osobiście korzystałem z aplikacji Gnuplot aby stworzyć wykresy, po uruchomieniu aplikacji ustawiamy nasz folder z plikiem tekstowym jaka folder z którego gnuplot będzie brał dane, tak aby podać sam tytuł pliku a nie całą ścieżkę do niego, i pozostało nam jedynie wpisać komendy.
Przykłady komend:
plot "Wyniki.txt" u ($4-$2):($5-$3) t "Księżyc względem ziemii" w l
plot "Wyniki.txt" u 2:3 t "Ziemia" w l, "Wyniki.txt" u 4:5 t "Księżyc" w l
plot "Wyniki.txt" u 2:3 t "Ziemia" w l
plot "Wyniki.txt" u 4:5 t "Księżyc" w l





























[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/6duO5yRa)
# Projekt
### Celem jest zbudowanie programu symulującego działanie układu dynamicznego na potrzeby badań naukowych 
Takim układem może być np.
1. Układ Lindenmayera.
2. Automat komórkowy.
3. Układ równań różniczkowych.

### Program składa się z czterech plików: 
1. Kod źródłowy.
2. Konfiguracyjny.
3. Wyjściowy.
4. Readme.

### Zawartość pliku Readme
Tutaj znajduje się dokumentacja programu, a w niej:
1. Definicja problemu badawczego: opis badanego zjawiska, co chcielibyśmy się
   dowiedzieć.
2. Rozwiązanie problemu: trafne rozwiązanie techniczne, tj. pomysł na program,
  po co został on zbudowany, jakie parametry możemy kontrolować, niezawodność,
  przyjazność w użytkowaniu i atrakcyjność wizualna.
3. Przykład użycia wraz z rzutami ekranu działania programu.
4. Lista dodatkowych bibliotek.
5. Opis krok po kroku, jak skompilować i uruchomić program.

### Działanie programu
Program po sczytaniu konfiguracji z pliku konfiguracyjnego przechodzi do
wykonywania symulacji. Symulacja graficzna może być dostępna w konsoli bądź
wyłączona na życzenie użytkownika. Rezultat działania symulacji jest zapisywany
do pliku wyjściowego. Jakie dane tam umieścicie zależy od Was. 

### Ocenianie
1. Definicja problemu badawczego i trafność proponowanego rozwiązania: 40%.
2. Złożoność (program oparty o listy, drzewa będzie rozpatrywany jako o wyższej
   złożoności niż tablice; w przypadku tablic wymagana notacja wskaźnikowa): 40%.
3. Zgodność organizacji kodu z wytycznymi zawartymi w repozytorium
   MP-2021-JPRO-INTRO: 10%.
4. Publiczna prezentacja projektu: 10%.


