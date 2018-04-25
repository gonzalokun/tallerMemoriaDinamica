#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <ostream>

typedef unsigned long Nat;

template <typename T>
class Lista {
public:

    /* Constructor por defecto de la clase Lista. */
    Lista();

    /* Constructor por copia de la clase Lista. */
    Lista(const Lista& l);

    /* Destructor de la clase Lista. */
    ~Lista();

    /* Operador asignación */
    Lista& operator=(const Lista& aCopiar);

    /* Agrega un elemento al principio de la lista. */
    void agregarAdelante(const T& elem);

    /* Agrega un elemento al final de la lista. */
    void agregarAtras(const T& elem);

    /* Devuelve la cantidad de elementos que contiene la lista. */
    int longitud() const;

    /* Devuelve el elemento en la i-ésima posición de la lista,
     * como una referencia inmutable.
     * Precondición: 0 <= i < this->longitud */
    const T& iesimo(Nat i) const;

    /* Devuelve el elemento en la i-ésima posición de la lista,
     * como una referencia mutable.
     * Precondición: 0 <= i < this->longitud */
    T& iesimo(Nat i);

    /* Elimina el i-ésimo elemento de la Lista.
     * Precondición: 0 <= i < this->longitud */
    void eliminar(Nat i);

    /* Muestra la lista en un std::ostream
     * formato de salida: [a_0, a_1, a_2, ...]
     * donde a_i es el resultado del "mostrar" del alumno i de la lista (ya definido)
     * @param o
     */
    void mostrar(std::ostream& o);

    /**
     * Utiliza el método mostrar(os) para sobrecargar el operador <<
     */
    friend std::ostream& operator<<(std::ostream& os, Lista& l) {
        l.mostrar(os);
        return os;
    }

private:

    struct Nodo {
        //Apuntamos el anterior y el siguiente de un nuevo modo a nulo
        Nodo(T elem) : valor(elem), anterior(nullptr), siguiente(nullptr) {};
        T valor;
        Nodo* anterior;
        Nodo* siguiente;
    };

    //Guardo la longitud por separado asi es más rápido
    int _longitud;

    //Puntero al primer elemento
    Nodo* _principio;

    //Puntero al ultimo elemento
    Nodo* _fin;

    //Devuelve un puntero al iesimo nodo de la lista
    Nodo* _iesimoNodo(Nat i);
};

#include "Lista.hpp"

#endif
