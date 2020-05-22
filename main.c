/*
 * Что конкретно хочу я видеть в своем коде:
 * 1. Общий интерфейс для управления всеми стратегиями вентиляции.
 * 2. Сделать полиморфизм, чтобы за указателем базового типа прятались разные стратегии
 * 	и у каждлой были свои значения переменных
 * 3. Сделать базовую реализацию какого-либо метода и не просто переопределить его, а расширить
 * в производном классе. Например, послал данные, характерные для любого режима, и дослал для
 * конкретного
 */



#include <stdio.h>
#include <stdlib.h>

typedef struct
{

	float code;
} Base;

typedef struct
{
	Base* base;
	int value;
} Derived;

void print_code(Base* b)
{
	printf("\n");
	printf("Code is: %f", b->code);
}

int main(void)
{
	Base* b = (Base*)calloc(1, sizeof(Base));

	Derived* d = (Derived*)calloc(1, sizeof(Derived));
	d->base = (Base*)calloc(1, sizeof(Base));

	b->code = 3.45;
	d->base->code = 7.86;
	d->value = 4.3;

	print_code(b);
	print_code(d->base);

	return 0;
}
