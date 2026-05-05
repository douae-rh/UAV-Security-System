# Système de Collision pour Essaim Autonome (UAV)

## Description
Projet industriel réalisé dans le cadre du cours de **Programmation Avancée en C** à l'École des Sciences de l'Information (ESI). 

L'objectif est d'identifier en temps réel (< 1ms) les deux drones les plus proches parmi 10 000 pour éviter un crash catastrophique.

## Spécifications Techniques
*   **Langage** : C.
*   **Contrainte Mémoire** : Allocation dynamique via `malloc` et navigation exclusive par **arithmétique des pointeurs** (interdiction des crochets `[]`).
*   **Algorithme** : Optimisation spatiale avec une complexité en $O(n \log n)$.

## Structure du Dépôt
*   `main.c` : Code source industriel[cite: 1].
*   `conception.pdf` : Documentation architecturale (Livrable 2)[cite: 1].
*   `audit.pdf` : Preuve mathématique de la complexité (Livrable 3)[cite: 1].