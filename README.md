# corewar

OCP ou Octet de codage des parametres :
* Les deux bits les plus a gauche decrivent le premier parametre
* Les deux suivants le second le second
* Les deux suivants le troisieme.
* Les deux derniers seront ignores et mis a 00.

Description des deux bits :
* 01 Signifie registre
* 11 Signifie adressage indirect
* 10 Signifie adressage direct

Suivant la valeur de l'octet de codage des parametres, on en deduira
la taille des parametres suivants :
* Un registre est code sur 1 octet. Le numero du registre est inscrit
* Un adressage direct est code sur 2 ou 4 octets selon les commandes. La valeur y est inscrit.
* Un adressage indirect est code sur 2 octets (la memoire fait 4 * 1024, aussi avec deux octets on peut faire les 4096 adresses possibles)

Details des commandes :
* sti : les adressages direct sont codes sur 2 octets
* and : les adressages direct sont codes sur 4 octets
* live : l'adressage direct fourni est code sur 4 octets
* zjmp : l'adressage direct fourni est code sur 2 octets

Les labels sont remplaces par leur adresse RELATIVE a la commande actuelle
lors de la compilation

Le compilateur de reference peut etre trouve a :
```
/sgoinfre/goinfre/corewar/asm
```

La machine virtuelle de reference peut etre trouvee a
```
/sgoinfre/goinfre/corewar/corewar
```

## TODO
Dans quoi stocker les nombres de nombre d'octets fixes ?
* Dans un type special t\_number comprenant un pointeur sur de la memoire allouee et la taille de lespace ?
* Dans un tableau de char passe en parametre avec la taille DEFINE ?
* Dans un type de donne grand sur lequel on fera des modulos ? (int ?) Auquel cas il faudra definir une taille maximum pour lespace. (surement la meilleure solution)
Faire attention a la taille des ints lors de lecriture
Faire attention a big/small endian
### asm
Compilateur de "Corewar ASM" .s vers du binaire .cor
Inclus : Essentiellement du parsing
### corewar
Machine virtuelle interpretant les fichiers .cor et les faisant combattre
Inclus : Affichage
