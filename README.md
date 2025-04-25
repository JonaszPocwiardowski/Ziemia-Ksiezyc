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
