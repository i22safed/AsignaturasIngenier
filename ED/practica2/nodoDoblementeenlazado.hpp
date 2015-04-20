#ifndef NODODOBLEMENTEENLAZADO_HPP
#define NODODOBLEMENTEENLAZADO_HPP

using namespace std;

namespace edi
{

  template <class T>

  class  nodoDoblementeenlazado
  {
    private:
      T _datos;

      nodoDoblementeenlazado<T> * _siguiente;
      nodoDoblementeenlazado<T> * _anterior;


    public:

      nodoDoblementeenlazado(const T& dato, nodoDoblementeenlazado<T>* siguiente, nodoDoblementeenlazado<T>* anterior)
      {
        setDato(dato);

        setSiguiente(siguiente);
        setAnterior(anterior);
      }

       ~nodoDoblementeenlazado () {}

      const  T& getDato() const
      {
				return _datos;
      }

       const nodoDoblementeenlazado<T>* getSiguiente() const
      {
        return _siguiente;
      }

      const nodoDoblementeenlazado<T>* getAnterior() const
      {
        return _anterior;
      }

       nodoDoblementeenlazado<T>* getSiguiente()
      {
        return _siguiente;
      }

      nodoDoblementeenlazado<T>* getAnterior()
      {
        return _anterior;
      }

       void setDato (const T& dato)
      {
        _datos=dato;
      }

       void setSiguiente(nodoDoblementeenlazado<T>* siguiente)
      {
				_siguiente=siguiente;
      }

      void setAnterior(nodoDoblementeenlazado<T>* anterior)
      {
        _anterior=anterior;
      }

  };

}

#endif
