
// Alberto Verdejo

#ifndef _HORAS
#define _HORAS

#include <iostream>
#include <iomanip>
#include <stdexcept>

class horas {
protected:
   int _hora;
   int _minuto;
   int _segundo;
   static bool check(int h, int m, int s) {
      return h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
   }
public:
   horas(int h = 0, int m = 0, int s = 0) {
      if (!check(h,m,s))
         throw std::invalid_argument("valores invalidos");
      else {
         _hora = h; _minuto = m; _segundo = s;
      }
   }
   // observadoras
   int hora() const { return _hora; }
   int minuto() const { return _minuto; }
   int segundo() const { return _segundo; }

   // operador de comparacion
   bool operator< (horas const& h) const {
      if (_hora < h._hora) return true;
      else if (_hora > h._hora) return false;
      else if (_minuto < h._minuto) return true;
      else if (_minuto > h._minuto) return false;
      else return _segundo < h._segundo;
   }

   void read(std::istream & i = std::cin) {
      char aux; int h, m, s;
      i >> h >> aux >> m >> aux >> s;
      if (!check(h, m, s))
         throw std::invalid_argument("valores invalidos");
      else {
         _hora = h; _minuto = m; _segundo = s;
      }
   }
   void print(std::ostream& o = std::cout) const {
      o << std::setfill('0') << std::setw(2) << _hora << ':'
         << std::setfill('0') << std::setw(2) << _minuto << ':'
         << std::setfill('0') << std::setw(2) << _segundo;
   }
};

inline std::ostream & operator<<(std::ostream & salida, horas const& h) {
   h.print(salida);
   return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h) {
   h.read(entrada);
   return entrada;
}

#endif
