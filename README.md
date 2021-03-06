# corewar

42 project asking us to make a champion, assembler and virtual machine
for the game Core War.

## Subject Intro

### The assembler
This is the program that will compile your champions and translate
them from the language you will write them in (assembly language) into “Bytecode”.Bytecode
is a machine code, which will be directly interpreted by the virtual
machine.

### The virtual machine
It’s the “arena” in which your champions will be executed.
It offers various functions, all of which will be useful for
the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes;
we are asking you for a gladiator fight, not a one-man show simulator.

### The champion
This one is a special case. Later, in the championship, you will
need to render a super powerful champion, who will scare the staff team to death.
However, rendering this kind of champion is serious work. And since, for now, we
are mostly interested in your capacity to create Corewar’s other programs
(i.e. the assembler and virtual machine),
your current champion will only need to prove to
us that you can write bits and pieces of Corewar ASM.
This means that the champion you should render for this project only needs
to scare the bejesus out of a neurasthenic hedgehog.

## Compiling

```make setup && make```

## Usage

### corewar
```./corewar/corewar [-v N] [-dump N] [-g] [-a] [-h] [-c][-f <filename>] [[-n N] <champion>.cor] ...```

### asm
```./asm/asm <champion>.s```

## Example
```
./asm/asm champions/mowgli.s &&
./asm/asm champions/vampire.s &&
./corewar/corewar champions/mowgli.cor champions/vampire.cor
```

## General infos (French)

Tableau regroupant toutes les infos sur l'encodage :
```
https://docs.google.com/spreadsheets/d/1pFwSCne-mh-u5ZLsjZS8VI9QvecYk-gWTyNaPstjpLE/edit#gid=0'
```

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

ATTENTION : lors d'un depassement du la valeur 9223372036854775807 ou -9223372036854775808 l'asm de zaz cap respectivement a 2147483647 (FFFFFFFF) et 0, alors que nous on continue l'overflow. Faire comme lui ou non?

### Header

Meme si la taille du nom donne est inferieure a PROG\_NAME\_LENGTH, PROG\_NAME\_LENGTH octets sont reserves pour l'ecriture du nom. Les octets supplementaires sont mis a 0.

Meme chose pour le commentaire.

Si la taille est trop longue, une erreur de parsing sera affichee :
"Champion name too long (Max length 128)"

### corewar
Machine virtuelle interpretant les fichiers .cor et les faisant combattre
Inclus : Affichage

Lorsquon traite un process :
- S'il est en attente on decremente lattente
- Sinon s'il vient de finir son attente on lit les params en fct de lop saved
- Sinon s'il a fini son instruction precedente on lit lopcode le stocke et en deduit le temps dattente

Verifier lordre des instructions de la boucle principale pour coller a la
machine de reference.

Bug quand fichier non valide

Que faire quand on demande doperer sur un registre non existant ?

Quand une instruction utilise un registre non existant elle est skip mais consomme toujours son tems dattente et ensuite on passe a apres ses instructions

ATTENTION COMPLEXE : Si un processus effectue une instrucion et que dans un meme tour un autre processus ecrit a lendroit du prochain op\_code est ce quon considere lop code quil y avait avant ou apres ?
Reponse : apres

le carry aussi est copie lors dun fork

apply_sti : verifier overflow
