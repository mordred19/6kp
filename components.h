#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct _components
{
	char name[11];   //Фамилия держателя
	int cproc;       //Число процессоров
	int tproc;	     //Тип процессоров
	int memory;		 //Объем памяти
	char typev[20];   //Тип видеоконтроллера
	int vmemory;     //Объем видеопамяти
	char carrier[23];//Тип ЖД подключения
	int cquantity;	 //Число винчестеров
	int capacity;	 //Емкость винчестеров
	int devices;	 //Количество контроллеров и внешних устройств
	char os[6];     //Операционная система
} components;

#endif
