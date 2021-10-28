#include <iostream>

using namespace std;

int main()
{
    //Variables introduction and types
    cout << "Ve introduciendo los numeros(n>0): " << endl;
    int cont, position, max_lenght, old_data, init_pos;
    cont=0; position=0;max_lenght=0;init_pos=0;

    //Start of the loop
    int new_data = 0;
    while (new_data >= 0){
        cin >> new_data;
        //Start counting the length of the list when the condition applies
        if (old_data <= new_data){
            cont++;
        }
        //In case of the condition not being met, calculate the maximum value and starting position
        else {
            if(max_lenght<cont){
                max_lenght=cont;
                init_pos = position - max_lenght;
                cont=1;
            }
        }
        //Mandatory variables declarations
        old_data = new_data;
        position++;
    }
    cout << "La longitud maxima empieza en " << init_pos << " y la longitud maxima es " << max_lenght << endl;
    return 0; //Cuz I like C.
}
