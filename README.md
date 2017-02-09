# corewar

OCP ou Octet de codage des parametres :
* Les deux bits les plus a gauche decrivent le premier parametre
* Les deux suivants le second le second
* Les deux suivants le troisieme.
* Les deux derniers seront ignores et mis a 00.

<<<<<<< HEAD
* 01 Signifie registre
* 11 Signifie adressage indirect
* 10 Signifie adressage direct
=======
01 Signifie registre\n
11 Signifie adressage indirect \
10 Signifie adressage direct \
>>>>>>> de3a084df2364e33702c2a5dce9cd8f61e06c7da

Le compilateur de reference peut etre trouve a :
```
/sgoinfre/goinfre/corewar/asm
```

La machine virtuelle de reference peut etre trouvee a
```
/sgoinfre/goinfre/corewar/corewar
```

## TODO
Faire attention a la taille des ints lors de lecriture
Faire attention a big/small endian
### asm
Compilateur de "Corewar ASM" .s vers du binaire .cor
Inclus : Essentiellement du parsing
### corewar
Machine virtuelle interpretant les fichiers .cor et les faisant combattre
Inclus : Affichage
