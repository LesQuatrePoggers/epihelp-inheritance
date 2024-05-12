# L'héritage en C++

## 1. Introduction

### 1.1 Héritage basique

En C++, pour hériter une classe d'une autre, il suffit d'ajouter à la fin de la déclaration du nom de la classe, deux-points, suivi du ou des noms des classes parentes, chacune précédée par un spécificateur d'accès. Dans ce chapitres et les quelques suivants, nous nous concentrerons uniquement sur l'héritage public.

Supposons que nous voulions modéliser les divers types de villageois dans Minecraft. Dans ce cas, nous pourrions avoir quelque chose comme suit :

```cpp
// Classe parente
class Villager {};

// Classe enfante
class Toolsmith : public Villager {};
```

Lorsqu'une classe hérite d'une autre, elle doit appeler le constructeur de ses classes parentes pour les initialiser. Si un des constructeurs de la classe parente ne prend aucun argument, cette étape est facultative. Voici la syntaxe:

```cpp
// Classe parente
class Villager {
public:
    Villager()
    {
        std::cout << "[Villager] Constructor" << std::endl;
    }
};

// Classe enfante
class Toolsmith : public Villager {
public:
    Toolsmith()
        : Villager(/* Potentiels arguments ici */)
    {
        std::cout << "[Toolsmith] Constructor" << std::endl;
    }
};
```

#### Exercice

Mettez-vous dans le dossier [ex01](ex01)

- Dans le fichier `include/Weaponsmith.hpp`, créer une nouvelle classe nommée `Weaponsmith` qui hérite publiquement de `Villager`
- Dans les fichier `include/Weaponsmith.hpp` et `src/Weaponsmith.cpp`, ajouter un constructeur à `Weaponsmith` qui écrit `[Weaponsmith] Constructor` dans la sortie standarde

Vous pouvez lancer les tests avec la commande suivante :

```bash
make tests_run
```

### 1.2 Partage des méthodes et attributs

Voyons maintenant comment les méthodes et attributs d'une classe sont partagés lors de l'héritage.

Vous savez probablement déjà qu'en C++, il est possible de déclarer des attributs et des méthodes d'une classe comme étant publics (avec `public:`) ou privés (avec `private:`). Cependant, il existe un troisième qualificateur : `protected:`. Voici un tableau récapitulatif de ces différentes visibilités :

| Spécificateur d'accès | Mot clef | Utilisable en dehors de la classe | Utilisable par la classe enfante |
|-----------------------|----------|-----------------------------------|----------------------------------|
| Public | `public:` | Oui | Oui |
| Protégé | `protected:` | Non | Oui |
| Privé | `private:` | Non | Non |

#### Exercice

Mettez-vous dans le dossier [ex02](ex02)

Dans la classe `Villager` (`include/Villager.hpp` et `src/Villager.cpp`):
- Créer un attribut *privé* de type `std::size_t` stockant un identifiant **unique**
- Créer un attribut *protégé* stockant sous forme de `std::string` le nom du personnage
- Créer une méthode *publique* appelée `getIdentifier` permettant de récupérer l'identifiant
- Créer une méthode *publique* appelée `getName` permettant de récupérer le nom du personnage
- Initialiser dans le constructeur *public* le nom du personnage à `Villager` et l'identifiant

Dans la classe `Toolsmith` (`src/Toolsmith.cpp`):
- Remplacer dans le constructeur *public* le nom du personnage par `Toolsmith`

Vous pouvez lancer les tests avec la commande suivante :

```bash
make tests_run
```

### 1.3 Spécialisation basique

Rien qu'avec ce que l'on vient de voir, nous pouvons déjà spécialiser du code d'une classe enfante par rapport à sa classe parente. Il suffit simplement de recopier l'exact signature d'une méthode d'une des classes parentes et de définir la méthode :

```cpp
class Foo {
public:
    void coucou(std::size_t times) const
    {
        for (; times != 0; times--)
            std::cout << "coucou" << std::endl;
    }
};

class Bar : public Foo {
public:
    void coucou(std::size_t times) const
    {
        for (; times != 0; times--)
            std::cout << "salutation" << std::endl;
    }
};
```

Cependant, un problème arrive lorsque nous souhaitons utiliser cette méthode au travers d'un pointeur ou d'une réference de la classe parente :

```cpp
Foo foo{};
foo.coucou(1); // 'coucou'

Bar bar{};
bar.coucou(1); // 'salutation'

Foo *foo_ptr = &bar;
foo_ptr->coucou(1); // 'coucou'
// La ligne précedente va également afficher 'coucou' malgré que le pointeur
// stocke l'addresse d'un objet de la classe `Bar`
```

Et c'est là qu'interviennent les méthodes virtuelles que nous verrons dans le chapitre suivant.

#### Exercice

Mettez-vous dans le dossier [ex03](ex03)

Dans la classe `Toolsmith` (`src/Toolsmith.cpp`):
- Spécialiser la méthode `getIdentifier` pour qu'elle retourne `42`

Vous pouvez lancer les tests avec la commande suivante :

```bash
make tests_run
```
