[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Library: Ncurses](https://img.shields.io/badge/UI-Ncurses-yellow.svg?style=for-the-badge)](#)
[![Module](https://img.shields.io/badge/Module-B--PSU--100-informational?style=for-the-badge)](#)

# 📊 MyTop — Moniteur Système & Gestionnaire de Processus en Temps Réel

**MyTop** est une réimplémentation interactive de la commande Unix `top` en langage C, utilisant la bibliothèque **Ncurses**. Le programme inspecte le système de fichiers virtuel `/proc` de Linux pour restituer dynamiquement l'état des ressources machine et des processus en cours d'exécution.

---

## 🚀 Indicateurs & Métriques Système

- **En-tête Global** :
  - Heure courante et durée d'activité du système (*Uptime*).
  - Nombre d'utilisateurs connectés (lecture des sessions via `utmp`).
  - Décompte des tâches : total, en exécution (*running*), en veille (*sleeping*), arrêtées (*stopped*), zombies.
- **Ressources CPU & Mémoire** :
  - Pourcentage d'utilisation du processeur par dérivation des ticks jiffies dans `/proc/stat`.
  - Consommation mémoire vive (RAM totale, libre, utilisée, partagée, buffers/cache) via `/proc/meminfo`.
- **Tableau des Processus** :
  - Détection et énumération des répertoires `/proc/[PID]/`.
  - Colonnes d'affichage : `PID`, `USER`, `PR` (priorité), `NI` (nice), `VIRT` (mémoire virtuelle), `RES` (mémoire résidente), `SHR` (mémoire partagée), `S` (état), `%CPU`, `%MEM`, `TIME+` (temps CPU cumulé), `COMMAND`.

---

## ⌨️ Raccourcis & Contrôles Interactifs

- **`q`** : Quitter proprement le moniteur et restaurer l'état du terminal.
- **Rafraîchissement Automatique** : Mise à jour périodique des statistiques avec gestion des signaux de redimensionnement de fenêtre (`SIGWINCH`).

---

## 🛠️ Compilation & Lancement

```bash
make        # Génère le binaire 'my_top'
make clean  # Nettoie les fichiers objets
make fclean # Supprime les fichiers objets et l'exécutable
make re     # Recompile l'ensemble

./my_top    # Lancer le moniteur interactif
```
