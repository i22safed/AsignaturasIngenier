#ifndef LISTAORDENADADOBLEMENTEENLAZADA_HPP
#define LISTAORDENADADOBLEMENTEENLAZADA_HPP

#include <cassert>
#include "edi_List.hpp"
#include "nodoDoblementeenlazado.hpp"

using namespace std;

using namespace edi;

namespace edi {
template <class T>

  class ListaOrdenadaDoblementeEnlazada: public Lista<T>
  {
    private:

      nodoDoblementeenlazado<T> * _cabeza;
      nodoDoblementeenlazado<T> * _cola;

      int _numeroElementos;

    public:


      nodoDoblementeenlazado<T> * getCabeza() const
      {
        return _cabeza;
      }

      nodoDoblementeenlazado<T> * getCola()
      {
        return _cola;
      }

      int getNumeroElementos() const
      {
        return _numeroElementos;
      }


      void setCabeza(nodoDoblementeenlazado<T> * cabeza)
      {
        _cabeza=cabeza;
      }

      void setCola(nodoDoblementeenlazado<T> * cola)
      {
        _cola=cola;
      }

      void setNumeroElementos(int numeroElementos)
      {
        _numeroElementos=numeroElementos;
      }

      ListaOrdenadaDoblementeEnlazada()
      {
        _numeroElementos=0;
        _cabeza=0;
        _cola=0;

        assert(estaVacia());
      }

      virtual bool estaVacia() const
      {
        return _cabeza==0;
      }


      virtual bool esUltimo(const int posterior) const
      {
        return (getNumeroElementos() -1)==posterior;
      }


      virtual bool esValida(const int posterior) const
      {
         return ((posterior >= 0) && (posterior <= getNumeroElementos() - 1));
      }

      virtual const T& dato(const int posterior) const
      {
        int indice=0;

        assert(/*not*/ esValida(posterior));

        nodoDoblementeenlazado<T> * aux=getCabeza();

        while((aux !=0)&&(indice<posterior))
        {
          indice++;
          aux=aux->getSiguiente();
        }

        return aux->getDato();
      }

      virtual  int buscaDato (const T &date, const int desde) const
      {
        assert(/*not */esValida(desde));

        int indice=0;

        nodoDoblementeenlazado<T> * aux=getCabeza();

        while((aux !=0) && (indice<desde))
        {
          indice++;
          aux=aux->getSiguiente();
        }

        while((aux!=0) && (aux->getDato()!=date))
        {
          aux=aux->getSiguiente();
          indice ++;
        }

        if(aux==0)
        {
          return -1;
        }

        else
        {
          return indice;
        }
      }

      virtual void inserta(const T &date)
      {
        nodoDoblementeenlazado<T> * aux=getCabeza();
        nodoDoblementeenlazado<T> * anterior=0;
        nodoDoblementeenlazado<T> * nuevo=0;

        bool found=false;

        while((aux!=0) && (aux->getDato() < date))
        {

          anterior=aux;
          aux=aux->getSiguiente();
        }

        if(aux==getCabeza())
        {
          nuevo=new nodoDoblementeenlazado<T>(date, aux, 0);
          if (estaVacia())
          {
          	setCola(nuevo);
          }
          setCabeza(nuevo);
        }

        else
        {
          nuevo=new nodoDoblementeenlazado<T>(date, aux, anterior);

          anterior->setSiguiente(nuevo);

          if (aux != 0)
          {
          	aux->setAnterior(nuevo);
          }
          else
          {
          	setCola(nuevo);
          }
        }

        setNumeroElementos(getNumeroElementos()+1);

      }

      virtual void borrarPosicion(int posicion)
      {
        nodoDoblementeenlazado<T> * aux=getCabeza();

        nodoDoblementeenlazado<T> * anterior=0;

        int indice=0;

        assert (estaVacia() || (/*not*/ esValida(posicion)));

        while((aux!=0) && (indice < posicion)) //
        {
          anterior=aux;
          aux=aux->getSiguiente();
          indice ++;
        }

        if(getCabeza() == aux)
        {
          setCabeza(aux->getSiguiente());

          if (aux->getSiguiente() == 0)
          {
            setCola(0);
            setCabeza(0);
          }
          else
          {
            setCabeza(aux->getSiguiente());
            getCabeza()->setAnterior(0);
          }
        }

        else
        {
          if(aux->getSiguiente() != 0 )
          {
            anterior->setSiguiente(aux->getSiguiente());
            aux->getSiguiente()->setAnterior(anterior);
          }
          else
          {
            anterior->setSiguiente(aux->getSiguiente());
            setCola(anterior);
          }
        }
        setNumeroElementos(getNumeroElementos()-1);
        delete(aux);

      }
  };
}
 #endif
