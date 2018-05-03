#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
// LIST_H_INCLUDED
template<typename T>
class Node{

  public:

    T data;
    Node<T> *next;

};


template<typename T>
class List {

  private :

    int length = 0;

    Node<T>  *firstElement ;

    Node<T>  *lastElement ;

  public:

    class iteratorList;

    List ();

   ~List();

    void push (T x);

    int Size();

    iteratorList End();

    iteratorList Begin();

    void Erase (iteratorList n);

    void Insert(iteratorList n,T x);

    T pop ();

    void forEach(void (*f)(iteratorList n));

    class iteratorList {

      public:

      Node <T> *N;

      T data ;

      bool operator++();

      bool operator==(iteratorList x );

      bool operator!=(iteratorList x );

      iteratorList operator+(int n );

   };
};
#include "List.cpp"
#endif


