#include <stdio.h>
#include <string.h>
#include "components.h"

int readComponents(components *p);

int main(int argc, char *argv[])

{

	components p;

	FILE *file = NULL;

	if (argc != 3)

	{

		printf("Использование: %s файл флаг\nФлаги:\n-a - создание нового файла\n-b - добавить запись в конец\n-с - добавить запись в начало\n", argv[0]);

		return 1;

	}

	if (!strcmp(argv[2], "-a"))

	{

		file = fopen(argv[1], "wb");

		if (file == NULL)

		{

			printf("Произошла ошибка при открытии файла\n");

			return 1;

		}

		printf("Образец:\n");

		printf("Smirnov 1 32 8 PCI 2 SCSI/IDE 1 256 15 WIN\n");

		while (readComponents(&p))//чтобы прервать ввод Ctrl+D

		fwrite(&p, sizeof(p), 1, file);

		fclose(file);

		return 0;

	}

	if (!strcmp(argv[2], "-b"))

	{

		file = fopen(argv[1], "ab");

		if (file == NULL)

		{

			printf("Произошла ошибка при открытии файла\n");

			return 1;

		}

		printf("Образец:\n");

		printf("Smirnov 1 32 8 PCI 2 SCSI/IDE 1 256 15 WIN\n");

		while (readComponents(&p))//чтобы прервать ввод Ctrl+D

		fwrite(&p, sizeof(p), 1, file);

		fclose(file);

		return 0;

	}

	if (!strcmp(argv[2], "-c"))

	{

		file = fopen(argv[1], "rb");

		if (file == NULL)

		{

		printf("Произошла ошибка при открытии файла\n");

		return 1;

	}

	FILE *temp = fopen("temp","wb");

	while (fread(&p, sizeof(p), 1, file) == 1)//чтобы прервать ввод Ctrl+D

	fwrite(&p, sizeof(p), 1, temp);

	fclose(file);

	fclose(temp);

	file = fopen(argv[1], "wb");

	if (file == NULL)

	{

		printf("Произошла ошибка при открытии файла\n");

		return 1;

	}

	printf("Образец:\n");

	printf("Smirnov 1 32 8 PCI 2 SCSI/IDE 1 256 15 WIN\n");

	while (readComponents(&p))//чтобы прервать ввод Ctrl+D

	fwrite(&p, sizeof(p), 1, file);

	temp = fopen("temp","rb");

	while (fread(&p, sizeof(p), 1, temp) == 1)

	{

		fwrite(&p, sizeof(p), 1, file);

	}

	fclose(temp);

	remove("temp");

	fclose(file);

	return 0;

	}

}

int readComponents(components *p)
{
	int ret = scanf("%s %d %d %d %s %d %s %d %d %d %s",
		p->name,
		&p->cproc,
		&p->tproc,
		&p->memory,
		p->typev,
		&p->vmemory,
		p->carrier,
		&p->cquantity,
		&p->capacity,
		&p->devices,
		p->os

);

return (ret == 11);
}