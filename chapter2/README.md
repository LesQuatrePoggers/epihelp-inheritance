# L'héritage en C++

## 2. Les méthodes virtuelles

### 2.1. Régler le soucis du dernier chapitre

Pour régler le problème du chapitre précedent, il est nécessaire de déclarer la méthode *virtuelle* grâce au mot clef `virtual`.

Voici en code ce que cela donne :

```cpp
class Foo {
public:
    //! Ici nous déclarons la méthode coucou virtuelle
    virtual void coucou(std::size_t times) const
    {
        for (; times != 0; times--)
            std::cout << "coucou" << std::endl;
    }
};

class Bar : public Foo {
public:
    //? Le virtual ici est falcutatif, une fois que la méthode a été déclarée virtuelle dans la classe parente, elle le sera dans tous les classes enfantes.
    virtual void coucou(std::size_t times) const
    {
        for (; times != 0; times--)
            std::cout << "salutation" << std::endl;
    }
};
```

Et maintenant, si nous essayons d'utiliser la méthode coucou de la classe Bar au travers d'un pointeur vers Foo, cela a le comportement attendu :

```cpp
Foo foo{};
foo.coucou(1); // 'coucou'

Bar bar{};
bar.coucou(1); // 'salutation'

Foo *foo_ptr = &bar;
foo_ptr->coucou(1); // 'salutation'
```

#### Exercice

Mettez-vous dans le dossier [ex04](ex04)

Dans la classe `Villager` (`include/Villager.hpp`):
- Déclarer la méthode `getIdentifier` comme virtuelle

Dans la classe `Toolsmith` (`src/Toolsmith.cpp`):
- Spécialiser la méthode `getIdentifier` pour qu'elle retourne `42`

Vous pouvez lancer les tests avec la commande suivante :

```bash
make tests_run
```

### 2.2. Les destructeurs virtuels

Lorsque l'on fait de l'héritage, il est nécessaire de faire attention à une chose en particulier : ne pas oublier de déclarer le destructeur de la classe parente `virtual`.

En effet, prenons le code suivant :

```cpp
class Base {
public:
    ~Base()
    {
        std::cout << "[Base] Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived()
    {
        std::cout << "[Derived] Destructor" << std::endl;
    }
};

// Qqpart dans le code
Base *base = new Derived();

//! UNDEFINED BEHAVIOR
delete base;
```

La dernière ligne de l'exemple n'appelera pas le destructeur de la classe dérivée. En effet, lorsque l'on demande de *free* la mémoire alloué par l'opérateur *new*, cela appelle le destructeur. Or, dans ce cas, étant donné que le destructeur n'a pas été declaré virtuelle, le compilateur ne connaît pas l'existence du destructeur de la classe `Derived`. C'est même pire que ça, c'est un comportement indéfini. Pour en savoir plus, je vous invite à aller lire [cette réponse](https://stackoverflow.com/a/461224).

#### Exercice

Mettez-vous dans le dossier [ex05](ex05)

Dans la classe `Villager` (`include/Villager.hpp` et `src/Villager.cpp`):
- Créer un destructeur virtuel qui affiche `[Villager] Destructor`

Dans la classe `Toolsmith` (`src/Toolsmith.cpp` et `include/Toolsmith.hpp`):
- Créer un destructeur virtuel qui affiche `[Toolsmith] Destructor`

Vous pouvez lancer les tests avec la commande suivante :

```bash
make tests_run
```
