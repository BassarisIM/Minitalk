*This project has been created as part of the 42 curriculum by sohollar.*

## Description :
Ce projet consiste a creer et utiliser une connexion entre deux programme : un serveur et un client.
le client doit pouvoir envoyer un message sous la forme d'une chaine de caractere au serveur, comprenant les caracteres de la tables ascii etendue (emojis compris), que le serveur doit etre en mesure d'afficher rapidement et sans perdre de signaux (donc de bits).

## Instructions :
executer le programme ainsi :
- compiler avec `make all`, ou separement `make client` et `make server`
- demarrer avec le serveur avec `./server`
- demarrer le client avec `./client` <PIDSERVER> <message>

## Ressources :

### Sites web :
	https://creatorsarea.fr/tutoriels/comment-utiliser-les-signaux-unix/quest-ce-quun-signal-unix-et-comment-les-utiliser
	https://creatorsarea.fr/tutoriels/comment-utiliser-les-signaux-unix/manipulation-des-signaux-unix

### My very helpful neighbour :
Debug help and explanations about sigaction usage

### IA :
Chatgpt pour m'expliquer la logique globale du projet et les notions a mobiliser pour me diriger vers la bonne documentation.

## Description du programme et NON utilisation d'une variable globale :

Les signaux echanges entre les programmes ne pouvant etre que SIGUSR1 et SIGUSR2, seules 2 informations differentes peuvent etre envoyees.
Donc, on ne peut envoyer le donnees que bit par bit.
Chaque fois que le client envoie un bit au serveur, il attend un signal retour du serveur pour envoyer la suite. Une fois le signal retour traite, la variable globale est modifiee, donnant l'autorisation d'envoyer le bit suivant.

J'ai essaye de simplement utiliser la fonction `pause()`, mais son execution n'etait pas encore assez rapide pour empecher les croisements de signaux.
L'utilisation d'un flag contenu dans une variable est alors indispensable. Bien qu'elle ait besoin d'exister a la fois dans mon main, et dans la fonction handler, il m'a suffit de la declarer statique en debut de fichier, et non dans une fonction, pour qu'elle remplisse son office sans avoir beosin d'etre globale.
