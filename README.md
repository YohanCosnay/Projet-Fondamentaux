**Name :** Yohan COSNAY, Mohamed GHAIBOUCHE & Theo GILLOT
**Git :** https://github.com/YohanCosnay/Projet-Fondamentaux.git

**Question 1.1**
    Pour ce pas s'auto-inclure et evite des problèmes de compilation

**Question 1.2**
    On obtient de définition multiple des fonctions / variables du fichier inclus

**Question 1.3**
    Cela permet de recompiler uniquement les fichiers necessaire (ici seulement alertes.c), donc de compiler plus rapidement.


**Question 4.3**
    Le fichier stats.d contient l'ensemble des chemins des dependances de stats.o
    Contenue : 
        build/stats.o: src/stats.c include/stats.h include/config.h
        include/stats.h:
        include/config.h:


**Question 5.2**
    Seul le fichier alertes.c est recompilé


**Question 5.4**
    Lorsque l'on utilise make apres avoir modifie le fichier config.h, make recompile tous les .o
    Si on enleve l'option -MMD -MP, make ne recompile pas car config.h n'as pas de .c associé, ce qui empeche make de voir qu'il a changé