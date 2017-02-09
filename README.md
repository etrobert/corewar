# corewar

OCP ou Octet de codage des parametres : \
Les deux bits les plus a gauche decrivent le premier parametre \
Les deux suivants le second le second \
Les deux suivants le troisieme. \
Les deux derniers seront ignores et mis a 00. \

01 Signifie registre \
11 Signifie adressage indirect \
10 Signifie adressage direct \

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
