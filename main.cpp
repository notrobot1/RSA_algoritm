#include <iostream>
#include <cmath>
#include <cstring>
#include <conio.h>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // time()
// проверяем числа на взаимопростость))
int gcd(int x, int y)
{
    return y ? gcd(y,x%y) : x;
}

void encrypt(int e, int mod){
int x = 11; //шифруем число х
if( x >mod){
        std::cout << "exit";
    exit;
}
int setup1 = pow(x,e); // возведение в степень
int setup2 = setup1 % mod; // зашифрованное сообщение
std::cout << setup2;
}

void decrypt(int d, int mod){
int x = 2;
int setup1 = pow(x,d);
int setup2 = setup1 % mod;
std::cout << setup2;

}

int  sundaram(int n, int p, int q, int f){


    int *a = new int [n], i, j, k;
    memset(a, 0, sizeof(int) * n);
    for(i = 1; 3*i+1 < n; i++){
 	  for(j = 1; (k = i+j+2*i*j) < n && j <= i; j++){
 		a[k] = 1;
 	  }
    }
    for(i = 1; i < n; i++){
 	  if(a[i] == 0){
           int numb =(2 * i + 1);
           // из простых чисел выбираем то, что меньше функции эйлера и взаимопростое с функцией эйлера
        if(numb < f && gcd(numb,f) == 1  ){
            return numb;
        }

      }
    }
    delete [] a;

 }

//функция определения простых чисел
int primeNumber(int n){
//int n = 5;
for (int i = 2; i<=sqrt(n)+1; i++) {
    if (n % i == 0) {
        //число не простое
        return 0;
    }

}
  //число простое
  return n;

}





int main()
{
int p = primeNumber(3);
int q = primeNumber(7);
int mod = p * q;

 //функция эллера
int f = (p - 1)*(q -1);

int e = sundaram(1000, p, q, f);
//массив из е и мод - публичный ключ
int publicKey[2] = {e, mod};


//Определение числа e, для которого является истинным
//соотношение (e*d)%((p_simple-1)*(q_simple-1))=1.
srand(time(NULL));
int random = rand();
random = 17; ////////
unsigned int d = 0, e_simple = 0;
while (e_simple !=1 && d != random ){
d += 1;
e_simple = (d*p)%f;
}

//d mod
int privateKey[2] = {d,mod};


encrypt(publicKey[0], publicKey[1]);
decrypt(privateKey[0], privateKey[1]);
std::cout << "\n" << publicKey[0]<< "."<<publicKey[1] <<","<<privateKey[0]<<"."<<privateKey[1];

}
