
#include "funcionesAES.h"


int main () {

  std::cout << "Bienvenido al programa de cifrado AES" << std::endl;

  std::vector<std::vector<std::string>> key = {
    {"00", "04", "08", "0c"},
    {"01", "05", "09", "0d"},
    {"02", "06", "0a", "0e"},
    {"03", "07", "0b", "0f"}
  };


  int bloque = 1;
  std::cout << "Introduzca la clave de cifrado poniendo un 0: o use la por defecto poniendo un 1" << std::endl;

  std::cin >> bloque;
  if (bloque == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> key[j][i];
      }
    }
  }

  

  std::cout << "La clave de cifrado es: " << std::endl;

  printMatrix(key);

  int clave = 1;

  std::cout << "Introduzca el bloque de texto 1 poniendo un 0: o use la por defecto poniendo un 1" << std::endl;

  std::cin >> clave;
  
  std::vector<std::vector<std::string>> state = {
    {"00", "44", "88", "cc"},
    {"11", "55", "99", "dd"},
    {"22", "66", "aa", "ee"},
    {"33", "77", "bb", "ff"}
  };
  if (clave == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> state[j][i];
      }
    }
  }

  std::cout << "El bloque de texto 1 es: " << std::endl;

  printMatrix(state);

  std::vector<std::vector<std::string>> IV = {
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"}
  };

  int clave2 = 1;
  std::cout << "Introduzca el bloque de texto 2 poniendo un 0: o use la por defecto poniendo un 1" << std::endl;

  std::cin >> clave2;
  
  std::vector<std::vector<std::string>> state2 = {
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"}
  };
   std::vector<std::vector<std::string>> state2Plus = {
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "00"},
    {"00", "00", "00", "--"}
  };
  if (clave2 == 0) {
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        std::cin >> state[j][i];
      }
    }
  }

  std::cout << "El bloque de texto 2 es: " << std::endl;

  printMatrix(state2);


  

  std::vector<std::vector<std::vector<std::string>>> keySchedule = KeySchedules(key);

  std::cout << "Los bloques de texto cifrado son: " << std::endl;

  modeCBC(state, state2, keySchedule, IV);

  std::cout << "Parte OPCIONAL: Cipher stealing." << std::endl;
  std::cout << "Los bloques de texto cifrado son: " << std::endl;

  modeCBCstealing(state, state2Plus, keySchedule, IV);
  

  







  return 0;


}