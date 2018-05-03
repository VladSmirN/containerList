
#include<iostream>

template<typename T>
  typename List<T>::iteratorList List<T>::Begin() {

    List<T>::iteratorList ret;

    if(!List<T>::length) {

      std::cout<<"Warning: There is no initial element"<<std::endl;

      ret.N =NULL;
      ret.data =NULL;

      return ret;

    }


    ret.N = lastElement;
    ret.data = lastElement->data;

    return ret;

  }


template<typename T>
  List<T>::List(){

    firstElement = NULL;
    lastElement = NULL;

  }
template<typename T>
  List<T>::~List(){
    Node<T> * del = lastElement;
    Node<T> * p;

    while(length && del-> next != NULL){

      p = del->next;
      delete del;
      del = p;

    }

    if (length == 1 && del == this->firstElement )
      delete del;

  }

template<typename T>
  void List<T>:: push (T x) {

    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = NULL;

    if(!length){

      this->firstElement = newNode;
      this->lastElement  = newNode;

    }
    else {

      this->firstElement->next = newNode;
      this->firstElement = newNode ;

    }

    this->length++;
  }


template<typename T>
  int List<T>:: Size () {

     return this->length;

  }

template<typename T>
  typename List<T>::iteratorList List<T>::End(){

    iteratorList ret;

    if(!length) {

      std::cout<<"Warning: There is no end element"<<std::endl;

      ret.N =NULL;
      ret.data =NULL;

      return ret;

    }

    ret.N = firstElement;
    ret.data = firstElement->data;

    return ret;

  }

template<typename T>
  void List<T>::Erase (iteratorList n) {

    iteratorList Back;
    iteratorList Front;
    iteratorList it ;

      switch(length){

        case 0:

          std::cout<<"Warning: You can not delete an item in an empty container"<<std::endl;

          return;

        break;

        case 1:

          if(n == Begin()) {

            delete firstElement;
            firstElement = NULL;
            lastElement = NULL;
            length--;

            return;

          }

        break;

        case 2:

            // ситуация , когда  искомый  элемент  первый , рассматпивается в конце метода

          it = Begin();

          if(it+1 == n) {

            lastElement = (it).N;
            firstElement = (it).N;
            delete (it+1).N;
            length--;

            return;

          }

        break;

        default:

          Back =  Begin();
          Front = Back + 2;
          it = Back + 1;

          while(it != End()) {

            if(it == n) {

              Back.N->next =  Front.N;
              delete it.N;
              length--;

              return;

            }

            ++Back;
            ++it;

             //нежелательно  обращаться   к элементу   вне  списка,  если  убрать   условие  будет  предупреждение об этом

            if(Front != End())
              ++Front;

          }

        break;

     }

     if (n == End()) {

       it = Begin();

       while(it+1 != End()){ ++it; }
       firstElement = it.N;
       delete  End().N;
       length--;

       return ;

     }

     if (n == Begin()) {

       lastElement = Begin().N->next;
       delete Begin().N;
       length--;

       return ;

     }
   }

template<typename T>
  void List<T>::Insert(iteratorList n,T x) {

    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = NULL;

    if(n == End()){

      push(x);

      return;

    }

    for(iteratorList it = Begin();it != End();++it ){

      if (n == it){

        iteratorList Front = it+1;
        it.N->next =  newNode ;
        newNode->next =Front .N;
        length++;

        return;
      }
    }
  }

template<typename T>
  T List<T>::pop (){

    T ans = End().data;
    Erase(End());

    return ans;

  }
template<typename T>
  void List<T>::forEach(void (*f)(iteratorList n)) {
     for( iteratorList it = Begin() ;it != End();++it ){

       f(it);

     }

   f(End());

  }

template<typename T>
  bool List<T>::iteratorList::operator++() {

    if(N->next != NULL){
      N =  N->next;
      data = N->data;

     return 1;

    }
    else return 0;

  }

template<typename T>
  bool List<T>::iteratorList::operator==(iteratorList x ) {

    if(x.N == this->N && x.data == this->data)
      return 1;
    else
      return 0;

  }

template<typename T>
  bool List<T>::iteratorList::operator!=(iteratorList x ) {

    if(x.N == this->N && x.data == this->data)
      return 0;
    else
      return 1;

  }


template<typename T>
  typename List<T>::iteratorList List<T>::iteratorList::operator+(int n){

  iteratorList ans ;
  ans.data = data;
  ans.N = N;

  for(int i = 0;i < n ;++i){

    if(!++ans)  {

      std::cout<<"Warning: this iterator does not exist, the iterator will be returned to the last element"<<std::endl;

      return ans;

    }
  }

  return ans;

}
