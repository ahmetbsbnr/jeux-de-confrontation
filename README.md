# Jeux de confrontation

Trois mini-jeux de réflexion dans le terminal, en C, réunis dans un menu avec suivi des moyennes.

## Les jeux
1. **Nombre caché** — trouver un nombre aléatoire en 10 essais maximum.
2. **Suite mystère** — trouver U3 d'une suite Un+1 = a·Un + b en 2 essais.
3. **Mastermind** — trouver un code de 4 voyelles distinctes en 10 essais.

Le score d'une partie est le nombre d'essais (12 en cas d'échec). **Le score le plus bas est le meilleur.**

## Compiler et lancer
```bash
gcc -Wall -o jeux_confrontation jeux_confrontation.c
./jeux_confrontation
```

## Contenu
| Chemin | Rôle |
|---|---|
| `jeux_confrontation.c` | Programme complet |
| `brouillons/` | Versions de travail (un fichier par jeu, tests) |

## Auteur
Ahmet BASBUNAR

© 2025-2026 — tous droits réservés (voir `LICENSE.md`).
