# L'héritage en C++

## 4. Notion diverses

### 4.1. Appelé une fonction membre de la classe parente

Il est possible d'appeler une fonction membre de la classe parente depuis la classe dérivée. Pour cela, il suffit de préciser le nom de la classe parente suivi de l'opérateur de résolution de portée `::`.

```cpp
class Base {
public:
    void foo()
    {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived: public Base {
public:
    void bar()
    {
        foo(); // Appel de la méthode foo de la classe Derived
        Base::foo(); // Appel de la méthode foo de la classe Base
    }
};
```

Cela est notamment utile lorsque la classe dérivée redéfinit une méthode de la classe parente, mais souhaite tout de même appeler la méthode de la classe parente.

```cpp
class Base {
public:
    void foo()
    {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived: public Base {
public:
    void foo()
    {
        Base::foo(); // Appel de la méthode foo de la classe Base
        std::cout << "Derived::foo()" << std::endl;
    }
};
```

#### Exercice

Il n'y a pas d'exercice pour cette section.

### 4.2. Les classes abstraites et interfaces

Une classe abstraite est une classe qui ne peut pas être instanciée. Elle est utilisée pour définir une interface commune à plusieurs classes dérivées. Pour déclarer une classe abstraite, il suffit de déclarer une ou plusieurs méthodes virtuelles pures en suffixant la déclaration de la méthode par `= 0`.

```cpp
class Abstract {
public:
    virtual void foo() const = 0;
    virtual void bar() const = 0;
};
```

Une classe dérivée d'une classe abstraite doit implémenter toutes les méthodes virtuelles pures de la classe parente. Si ce n'est pas le cas, la classe dérivée deviendra elle-même une classe abstraite.

```cpp
class Abstract {
public:
    virtual ~Abstract() = default;

    virtual void foo() const = 0;
    virtual void bar() const = 0;
};

class StillAbstract: public Abstract {
public:
    virtual ~StillAbstract() = default;

    void foo() const override
    {
        std::cout << "StillAbstract::foo()" << std::endl;
    }
};

class Concrete: public Abstract {
public:
    virtual ~Concrete() = default;

    void foo() const override
    {
        std::cout << "Concrete::foo()" << std::endl;
    }

    void bar() const override
    {
        std::cout << "Concrete::bar()" << std::endl;
    }
};
```

Lorsqu'une classe possède toutes ses méthodes abstraites avec aucun attribut, on appelle cela une *interface*. Certains langages de programmation, comme Java, permettent de définir explicitement des interfaces.

#### Exercice

Il n'y a pas d'exercice pour cette section.

### 4.3. Les classes et méthodes finales

Une classe finale est une classe qui ne peut pas être dérivée. Elle est utilisée pour empêcher la spécialisation d'une classe. Pour déclarer une classe finale, il suffit de préfixer la déclaration de la classe par le mot-clé `final`.

```cpp
class Base final {
public:
    void foo() const
    {
        std::cout << "Base::foo()" << std::endl;
    }
};

// Erreur de compilation : impossible de dériver de la classe finale Base
// class Derived: public Base {
// public:
//     void bar() const
//     {
//         std::cout << "Derived::bar()" << std::endl;
//     }
// };
```

Il est également possible de déclarer une méthode comme finale, empêchant ainsi sa redéfinition dans les classes dérivées.

```cpp
class Base {
public:
    virtual void foo() const
    {
        std::cout << "Base::foo()" << std::endl;
    }

    virtual void bar() const final
    {
        std::cout << "Base::bar()" << std::endl;
    }
};

class Derived: public Base {
public:
    void foo() const override
    {
        std::cout << "Derived::foo()" << std::endl;
    }

    // Erreur de compilation : impossible de redéfinir la méthode finale Base::bar
    // void bar() const override
    // {
    //     std::cout << "Derived::bar()" << std::endl;
    // }
};
```

#### Exercice

Il n'y a pas d'exercice pour cette section.

### 4.4. Les tables virtuelles et les 'fat pointers'

Les tables virtuelles sont un mécanisme utilisé par les compilateurs pour implémenter le polymorphisme en C++. Lorsqu'une classe contient au moins une méthode virtuelle, le compilateur crée une table virtuelle pour cette classe. Cette table contient les adresses des méthodes virtuelles de la classe, ainsi que des informations supplémentaires pour permettre au programme de les appeler correctement.

Les tables virtuelles sont stockées dans la mémoire de l'objet, un pointeur vers cette table est ajouté à l'objet. Ce pointeur est ce qu'on appelle un 'fat pointer', car il contient à la fois l'adresse de l'objet et l'adresse de la table virtuelle.

Voici un exemple en code :

```cpp
class Base {
public:
    virtual void foo() const
    {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived: public Base {
public:
    void foo() const override
    {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main()
{
    Derived derived;

    // Ici, base_ptr est un 'fat pointer' qui contient à la fois l'adresse de l'objet 'derived' et l'adresse de la table virtuelle de la classe 'Derived'
    Base *base_ptr = &derived;

    base_ptr->foo(); // 'Derived::foo()'
    return 0;
}
```

Dans certain langages de programmation, tel que le Rust, les fat pointers sont désigné explicitement par le programmeur à l'aide du mot clef `dyn`.

#### Exercice

Il n'y a pas d'exercice pour cette section.
