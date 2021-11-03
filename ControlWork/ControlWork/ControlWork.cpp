#include <iostream>
#include <ctime>
using namespace std;
int main(){
    setlocale(LC_ALL,".1251");
    time_t now = time(0);
    char* dt = ctime(&now);
    cout<<"Текущая дата и время равно:\n"<<dt<<endl;
    cout<<"Для того, чтобы удалить объектный и исполняемые файлы, используйте make uninstall"<<endl;
    cout<<"Для копирования файла в каталог, используйте make install"<<endl;
    cout<<"Для удаления программы из системы, используйте make clean"<<endl;
}