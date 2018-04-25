#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    //La lista nueva esta vacia, por ende su longitud es 0
    _longitud = 0;

    //No hay principio ni fin cuando recien se crea la lista
    _principio = nullptr;
    _fin = nullptr;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; } 

template <typename T>
Lista<T>::~Lista() {
    //Hay que borrar todos los nodos

    Nodo* nodoActual = _principio;

    while(nodoActual != nullptr){
        //Guerdamos el nodo que sigue
        Nodo* siguiente = nodoActual->siguiente;

        //Borramos el nodo actual
        delete nodoActual;

        //Pasamos al siguiente nodo
        nodoActual = siguiente;
    }

}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {

    //Guardo la longitud de la lista
    int longitudDeListaABorrar = _longitud;

    //Elimino todos los elementos de la lista actual
    for(int i = 0; i < longitudDeListaABorrar; i++){
        eliminar(0);
    }

    //Reinicio la longitud
    _longitud = 0;

    //Agrego los elementos de la lista a copiar
    for(int i = 0; i < l.longitud(); i++){
        agregarAtras(l.iesimo(i));
    }

    std::cout << "LA LONGITUD DE LA NUEVA LISTA ES: " << _longitud << std::endl;

    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    //Agrega un elemento al principio de la lista

    //Creo el nuevo nodo
    Nodo* nuevoElem = new Nodo(elem);

    //Le asigno el nuevo valor al nodo
    //nuevoElem->valor = elem;

    //std::cout << "VALOR DEl NUEVO NODO: " << nuevoElem->valor << std::endl;

    //Si la lista no tiene elementos
    if(_longitud == 0) {
        std::cout << "SE AGREGA EL PRIMER ELEMENTO A LA LISTA" << std::endl;

        //Apunto el principio y el fin de la lista al nuevo elemento (ya que solo hay un elemento)
        _principio = nuevoElem;
        _fin = nuevoElem;
    }
    else {
        //Apunto el anterior de principio al nuevo elem
        _principio->anterior = nuevoElem;

        //Apunto el elemento siguiente del nuevo elemento al principio anterior de la lista
        nuevoElem->siguiente = _principio;

        //Apunto al nuevo principio de la lista
        _principio = nuevoElem;
    }

    //Aumento la longitud de la lista ya que se agregó un elemento
    _longitud++;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    //Agrega un elemento al final de la lista

    //Creo el nuevo nodo
    Nodo* nuevoElem = new Nodo(elem);

    //Le asigno el nuevo valor al nodo
    //nuevoElem->valor = elem;

    //Si el primer elemento de la lista es nulo, entonces es nueva
    if(_principio == nullptr) {
        //Apunto el principio y el fin de la lista al nuevo elemento (ya que solo hay un elemento)
        _principio = nuevoElem;
        _fin = nuevoElem;
    }
    else {
        //El primer elemento no fue nulo, entonces habia más de un elemento
        //Al final anterior le apunto como siguiente al elemento nuevo
        _fin->siguiente = nuevoElem;

        //Hago que el nuevo elemento apunte al final anterior
        nuevoElem->anterior = _fin;

        //Ahora apunto al final que corresponde
        _fin = nuevoElem;
    }

    //Aumento la longitud de la lista ya que se agregó un elemento
    _longitud++;
}

template <typename T>
int Lista<T>::longitud() const {
    return _longitud;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    //Hay que devolver el i esimo elemento de la lista
    //Ahora, para optimizar, si el elemento que nos piden esta en una posición mayor a la mitad del largo
    //nos convendria recorrer la lista desde el final en lugar del principio

    std::cout << "ENTRE AL iesimo CONST" << std::endl;

    //T valorDeseado;
    Nodo* nodoActual;

    if(i > (_longitud/2)){
        //Hay que recorrerlo desde el final

        std::cout << "RECORRO DESDE EL FINAL" << std::endl;

        nodoActual = _fin;

        for(int pos = (_longitud - 1); pos > i; pos--){
            nodoActual = nodoActual->anterior;
        }

        std::cout << "ANTES DE ASIGNAR" << std::endl;
        std::cout << "VALOR A ASIGNAR: " << nodoActual->valor << std::endl;
        std::cout << "DESPUES DE ASIGNAR (NO MORI :) )" << std::endl;

        //valorDeseado = nodoActual->valor;
    }

    else{
        //Hay que recorrerlo desde el principio

        std::cout << "RECORRO DESDE EL PRINCIPIO" << std::endl;

        nodoActual = _principio;

        for(int pos = 0; pos < i; pos++){
            std::cout << "VALOR DE POS: " << pos << std::endl;
            nodoActual = nodoActual->siguiente;
        }

        std::cout << "ANTES DE ASIGNAR" << std::endl;
        std::cout << "VALOR DEL PUNTERO ANTES DE ASIGNAR: " << nodoActual->valor << std::endl;
        std::cout << "DESPUES DE ASIGNAR (NO MORI :) )" << std::endl;

        //valorDeseado = nodoActual->valor;
    }

    //std::cout << "EL VALOR DESEADO ES " << valorDeseado << std::endl;
    std::cout << "VALOR DEL PUNTERO NODOACTUAL: " << nodoActual->valor << std::endl;

    //return valorDeseado;
    return nodoActual->valor;
}

template  <typename T>
typename Lista<T>::Nodo* Lista<T>::_iesimoNodo(Nat i) {
    Nodo* punteroDeseado = nullptr;

    //Usamos la forma de recorrer la lista que usamos en iesimo

    if(i > (_longitud/2)){
        //Hay que recorrerlo desde el final

        Nodo* nodoActual = _fin;

        for(int pos = (_longitud - 1); pos > i; pos--){
            nodoActual = nodoActual->anterior;
        }

        //Al salir de ese ciclo nodoActual deberia estar apuntando al lugar correcto
        punteroDeseado = nodoActual;

    }

    else{
        //Hay que recorrerlo desde el principio

        Nodo* nodoActual = _principio;

        for(int pos = 0; pos < i; pos++){
            nodoActual = nodoActual->siguiente;
        }

        //Al salir de ese ciclo nodoActual deberia estar apuntando al lugar correcto
        punteroDeseado = nodoActual;

    }

    //

    return punteroDeseado;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    //Elimina el iesimo elemento de la lista

    //Si la longitud es 0 no hacemos nada
    if(_longitud == 0)
        return;

    Nodo* nodoAEliminar = _iesimoNodo(i);

    //Si elimino el primero
    if(_principio == nodoAEliminar){

        //Si solo habia un nodo
        if(_longitud == 1){
            //Borro el elemento
            delete _principio;

            //Reasigno los punteros de principio y fin de la lista como si la hubiese creado de cero
            _principio = nullptr;
            _fin = nullptr;
        }

        //Si habia mas de un nodo
        else{
            //Consigo el siguiente elemento
            Nodo* nodoSiguiente = _iesimoNodo(i + 1);

            //Apunto el anterior del segundo elemento a nulo
            nodoSiguiente->anterior = nullptr;

            //Borro el primer nodo
            delete _principio;

            //Indico que el segundo nodo es ahora el principio de la lista
            _principio = nodoSiguiente;
        }
    }

    //Si elimino el final
    else if (_fin == nodoAEliminar) {

        //En este punto se que hay mas de un nodo, sino hubiese entrado en la anterior
        Nodo* nodoAnterior = _iesimoNodo(i - 1);

        nodoAnterior->siguiente = nullptr;

        delete _fin;

        _fin = nodoAnterior;
    }

    //Si elimino un nodo en medio
    else {
        //Consigo punteros al elemento que antecede y al elemento que sigue al que voy a eliminar
        Nodo* nodoAnterior = _iesimoNodo(i - 1);
        Nodo* nodoSiguiente = _iesimoNodo(i + 1);

        //Cambio las conecciones de la lista a las que corresponden
        nodoAnterior->siguiente = nodoSiguiente;
        nodoSiguiente->anterior = nodoAnterior;

        //Elimino el nodo deseado
        delete nodoAEliminar;
    }

    //La longitud de la lista es uno menos ahora
    _longitud--;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    //Por ahora va a ser un copy-paste de la anterior

    std::cout << "ENTRE AL iesimo NO CONST" << std::endl;

    //T valorDeseado;
    Nodo* nodoActual;

    if(i > (_longitud/2)){
        //Hay que recorrerlo desde el final

        std::cout << "RECORRO DESDE EL FINAL" << std::endl;

        nodoActual = _fin;

        for(int pos = (_longitud - 1); pos > i; pos--){
            nodoActual = nodoActual->anterior;
        }

        std::cout << "ANTES DE ASIGNAR" << std::endl;
        std::cout << "VALOR A ASIGNAR: " << nodoActual->valor << std::endl;
        std::cout << "DESPUES DE ASIGNAR (NO MORI :) )" << std::endl;

        //valorDeseado = nodoActual->valor;
    }

    else{
        //Hay que recorrerlo desde el principio

        std::cout << "RECORRO DESDE EL PRINCIPIO" << std::endl;

        nodoActual = _principio;

        for(int pos = 0; pos < i; pos++){
            std::cout << "VALOR DE POS: " << pos << std::endl;
            nodoActual = nodoActual->siguiente;
        }

        std::cout << "ANTES DE ASIGNAR" << std::endl;
        std::cout << "VALOR DEL PUNTERO ANTES DE ASIGNAR: " << nodoActual->valor << std::endl;
        std::cout << "DESPUES DE ASIGNAR (NO MORI :) )" << std::endl;

        //valorDeseado = nodoActual->valor;
    }

    //std::cout << "EL VALOR DESEADO ES " << valorDeseado << std::endl;
    std::cout << "VALOR DEL PUNTERO NODOACTUAL: " << nodoActual->valor << std::endl;

    //return valorDeseado;
    return nodoActual->valor;
}

//Opcional !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
	// Completar
}