# Text Format

_________________________________________________________________________________________________________________________________
 ro - description 
 
* Pentru center am folosit cea mai lunga linie din fisier si am adaugat spatii la inceputul
liniilor mai mici ca sa le centrez. Am aflat diferenta dintre (lungimea randului maxim si lungimea randului 
curent) / 2  si am mutat textul la dreapta  cu acea diferenta /2 si completez locul liber cu spatii. 

* Pentru align_left am parcurs matricea si daca avem la inceput de rand spatii , mutam textul la stanga .

* Pentru align_right mutam textul de pe fiecare linie din matrice in dreapta cu diferenta intre lungimea randului maxim 
si lungimea liniei curente, punem spatii pe locurile libere.

* La paragrafe verificam ca linia dinainte sa fie un newline si mutam inceputul paragrafului cu "lungime_tab" spatii mai incolo , inlocuind locul gol cu spatii.

* Pentru liste am facut pentru bullet , alfabetica si cele numerotate:
la bullet am mutat textul in dreapta  ca primele caractere sa fie  caracter special si spatiu
la alfabetica am mutat textul in dreapta ca primele caractere sa fie litera , caracter special si spatiu 
la numerotata fac numarul sir de caractere cu itoa , il pun in buffer si urmatorul caracter va fi cel 
special , apoi spatiu si cu \0 inchid bufferul. Apoi am alipit la buffer textul original si dupa care copiez
din buffer in original.

*La liste am facut un bubble sort  ca sa imi sorteze alfabetic sau invers , apoi am apelat functia liste. 

*Pentru Justify aliniez la stanga cum se cere , apoi cand gasesc un spatiu daca randul meu inca nu are
lungimea dorita mai adaug un spatiu si apoi trec peste spatiul ala de l-am adaugat si il caut pe urmatorul.

*Mainul parcurge matricea de comenzi si vede ce e pe prima pozitie si aplica operatia respectiva
apoi verifica sa avem parametrii obligatorii si daca avem parametri optionali aplicand operatia in consecinta.
_____________________________________________________________________________________________________________________
