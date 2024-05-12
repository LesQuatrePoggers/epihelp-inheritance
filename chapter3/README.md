# L'héritage en C++

## 3. Les types d'héritage (public, protected, private, virtual)

### 3.1. Les spécificateurs d'accès (public, private, protected)

Dans la section 1.1., je vous ai insinué qu'il existait d'autres types d'héritage différent du public, et bien c'est le moment de les voir.

Lorsque vous héritez d'une classe, vous avez la possibilité de spécifier le niveau d'accès des membres de cette classe parente dans la classe enfant. Les spécificateurs sont `public`, `private` et `protected`. Par défaut, si vous n'en spécifiez pas, le niveau d'accès est `private`.

La différence entre ces spécificateurs réside dans la façon dont les membres de la classe parente sont hérités dans la classe enfant. Dans le cas de l'héritage public, le niveau d'accès des membres de la classe parente reste inchangé dans la classe enfant. En revanche, avec l'héritage privé, tous les membres de la classe parente deviennent privés dans la classe enfant, ce qui signifie que tout ce qui étaient `public` et `protected` n'est plus accessible. En revanche, la classe enfante a toujours accès à ces membres (s'ils étaient `public` ou `protected` bien évidemment).

Voici un tableau récapitulatif:

| Clase parente | Héritage public | Héritage protégé | Héritage privé |
|---------------|-----------------|------------------|----------------|
| public | public | protected | private |
| protected | protected | protected | private |
| private | private | private | private |

Pour mieux, comprendre voici un petit code :

```cpp
class Base {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class PublicDerived: public Base {
  // x reste public
  // y reste protégé
  // z reste privé et n'est pas accessible depuis cette classe
};

class ProtectedDerived: protected Base {
  // x DEVIENT protégé
  // y reste protégé
  // z reste privé et n'est pas accessible depuis cette classe
};

class PrivateDerived: private Base {
  // x DEVIENT privé MAIS est toujours accessible depuis cette classe
  // y DEVIENT privé MAIS est toujours accessible depuis cette classe
  // z reste privé et n'est pas accessible depuis cette classe
};
```

#### Exercice

Il n'y a pas d'exercice pour cette section.

### 3.2. Le problème du diamant et l'héritage virtuelle

Le "problème du diamant" est une situation délicate qui se produit lorsqu'une classe hérite de deux classes qui elles-mêmes héritent d'une même classe de base. Cette configuration forme une structure en forme de diamant dans le diagramme d'héritage :

```
  A
 / \
B   C
 \ /
  D
```

En conséquence, la classe dérivée finale hérite indirectement des membres de la classe de base par l'intermédiaire de deux chemins différents. Nous pouvons regarder ce que cela donnerait en mémoire :

```
A   A
|   |
B   C
 \ /
  D
```

Cela peut entraîner des ambiguïtés pour le compilateur lors de l'accès à des membres ou méthodes à partir de la classe dérivée. Par exemple, si les deux classes intermédiaires redéfinissent un même attribut de la classe de base de manière différente, lequel de ces deux attributs devrait être utilisé par la classe dérivée ?

Pour résoudre ce problème, le langage C++ propose l'utilisation de l'*héritage virtuel*. Il suffit simplement de déclarer virtuel l'héritage des classes intermédiaires, pour permettre à la classe dérivée de n'avoir au final qu'une seule instance de la classe parente.

Voici un exemple en code :

```cpp
class A {
public:
    int getValue() const { return value; }
    void setValue(int value) { this->value = value; }
private:
    int value;
};

class B : public virtual A {
public:
    B() : A() {}
};

class C : public virtual A {
public:
    C() : A() {}
};

class D : public B, public C {
public:
    // Etant donnée que les classes B et C héritent virtuellement de la classe A
    // Nous avons besoin ici d'également appelé le constructeur de A, qui sera
    // la seul et unique instance de cette classe, et partagé entre B et C
    D(): A(), B(), C() {}
};
```

Nous pouvons maintenant regarder ce que cela donnerait en mémoire :

```
  A
 / \
B   C
 \ /
  D
```

Les classes B et C héritent virtuellement de la classe A, ce qui signifie que la classe D n'a qu'une seule instance de la classe A, partagée entre B et C.

#### Exercice

Mettez-vous dans le dossier [ex06](ex06)

Dans la classe Toolsmith (`include/Toolsmith.hpp`):
- Définissez l'héritage à `Villager` comme `virtual`

Dans la classe Weaponsmith (`include/Weaponsmith.hpp`):
- Définissez l'héritage à `Villager` comme `virtual`

Dans les fichiers `include/Smith.hpp` et `src/Smith.cpp`:
- Créez une nouvelle classe `Smith` qui hérite de `Toolsmith` et de `Weaponsmith` (**attention à l'ordre**)
- Créez un constructeur ne prenant aucun paramètre et appelant les constructeurs des classes mères (**attention à l'ordre**). Ne redéfinissez pas le nom. Afficher dans la sortie standarde `[Smith] Constructor`
- Créez un destructeur virtuelle qui affiche dans la sortie standarde `[Smith] Destructor`
- Spécialisez la méthode `getIdentifier` pour qu'elle retourne 84 (cette étape est obligatoire car la méthode est spécialisée dans ses deux classes mères)

Comme d'habitude, vous pouvez lancer les tests avec la commande suivante :

```bash
make tests_run
```

Si vous avez bien hérité dans l'ordre `Toolsmith` et `Weaponsmith` dans la classe `Smith`, la classe `Smith` devrait avoir comme nom `Weaponsmith` étant donné que `Weaponsmith` est la dernière classe héritée. En effet, son constructeur sera appelé en dernier.
