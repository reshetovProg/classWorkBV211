#include <iostream>
using namespace std;
#define task 3

int main()
{
    srand(time(NULL));
#if task==1
    /*
    (2б) Пользователь вводит 4 вещественных числа. 
    Вывести на экран максимальное из них.*/
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    float max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;
    cout << max;

#elif task==2
    /*
    (2б) Вывести все целые числа от 
    a до b в порядке убывания*/
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    for (int i = b; i >= a; i--) {
        cout << i << " ";
    }
#elif task==3
    /*
    (2б) Пользователь вводит сторону квадрата. 
    Вывести на экран квадрат с заданной стороной, 
    заполненный целыми числами с шагом 1, 
    начиная с 5, в порядке возрастания. 
    
    */
    int side;
    cin >> side;
    for (int i = 0, k=5; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cout << k++ << " ";
        }
        cout << endl;
    }

#endif
    
}
