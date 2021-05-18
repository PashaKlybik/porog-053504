#include <stdio.h>
#include <locale.h>
#include <string.h>

void recommendations(int n, int *KSISball, int *FREball, int *IEFball, int *FITIYball, int *FKPball)
{
	int KSIScount = 0,FREcount=0,IEFcount=0,FITIYcount=0,FKPcount=0;
	printf("Ваш итоговый балл:%d\n", n);
	for(int i=0;i<4;i++)
	{
		if (n >= KSISball[i])
			KSIScount++;
	}
	switch(KSIScount)
	{
	case 1:printf("Вы можете поступить на 1 специальность ФКСиС!\n");
		break;
	case 2:printf("Вы можете поступить на 2 специальности ФКСиС!\n");
		break;
	case 3:printf("Вы можете поступить на 3 специальности ФКСиС!\n");
		break;
	case 4:printf("Вы можете поступить на все специальности ФКСиС!\n");
		break;
	default:break;
	}

	for (int i = 0; i < 6; i++)
	{
		if (n >= FREball[i])
			FREcount++;
	}
	switch (FREcount)
	{
	case 1:printf("Вы можете поступить на 1 специальность ФРЭ!\n");
		break;
	case 2:printf("Вы можете поступить на 2 специальности ФРЭ!\n");
		break;
	case 3:printf("Вы можете поступить на 3 специальности ФРЭ!\n");
		break;
	case 4:printf("Вы можете поступить на 4 специальности ФРЭ!\n");
		break;
	case 5:printf("Вы можете поступить на 5 специальностей ФРЭ!\n");
		break;
	case 6:printf("Вы можете поступить на все специальности ФРЭ!\n");
		break;

	default:break;
	}

	for (int i = 0; i < 4; i++)
	{
		if (n >= IEFball[i])
			IEFcount++;
	}
	switch (IEFcount)
	{
	case 1:printf("Вы можете поступить на 1 специальность ИЭФ!\n");
		break;
	case 2:printf("Вы можете поступить на 2 специальности ИЭФ!\n");
		break;
	case 3:printf("Вы можете поступить на 3 специальности ИЭФ!\n");
		break;
	case 4:printf("Вы можете поступить на все специальности ИЭФ!\n");
		break;
	
	default:break;
	}

	for (int i = 0; i < 9; i++)
	{
		if (n >= FKPball[i])
			FKPcount++;
	}
	switch (FKPcount)
	{
	case 1:printf("Вы можете поступить на 1 специальность ФКП!\n");
		break;
	case 2:printf("Вы можете поступить на 2 специальности ФКП!\n");
		break;
	case 3:printf("Вы можете поступить на 3 специальности ФКП!\n");
		break;
	case 4:printf("Вы можете поступить на 4 специальности ФКП!\n");
		break;
	case 5:printf("Вы можете поступить на 5 специальностей ФКП!\n");
		break;
	case 6:printf("Вы можете поступить на 6 специальностей ФКП!\n");
		break;
	case 7:printf("Вы можете поступить на 7 специальностей ФКП!\n");
		break;
	case 8:printf("Вы можете поступить на 8 специальностей ФКП!\n");
		break;
	case 9:printf("Вы можете поступить на все специальности ФКП!\n");
		break;
	default:break;
	}
	

	for (int i = 0; i < 4; i++)
	{
		if (n >= FITIYball[i])
			FITIYcount++;
	}
	switch (FITIYcount)
	{
	case 1:printf("Вы можете поступить на 1 специальность ФИТиУ!\n");
		break;
	case 2:printf("Вы можете поступить на 2 специальности ФИТиУ!\n");
		break;
	case 3:printf("Вы можете поступить на 3 специальности ФИТиУ!\n");
		break;
	case 4:printf("Вы можете поступить на все специальности ФИТиУ!\n");
		break;

	default:break;
	}

	if (KSIScount ==0 && FKPcount == 0 && IEFcount == 0 && FITIYcount == 0 && FREcount == 0)
	{
		printf("Вам не стоит тратить свое время!\n");
	}
}
struct faculty
{
	
	char *name;
	int  students;
	int  date;
	int  ball[10];
	char *decan;
	char *specialities;
	char *qualification;
};

void showInfo(struct faculty facl)
{
	printf("-----------------------------%s-----------------------------\n", facl.name);
	printf("Количество студентов:%d\n", facl.students);
	printf("Дата образования:%d\n", facl.date);
	printf("Декан факультета:%s\n", facl.decan);
	printf("Квалификации:\n%s\n", facl.qualification);
	printf("Специальности:\t\t\t\t\t\t\t\t Проходной бал:\n%s", facl.specialities);
	
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int n = 0, avg = 0, language = 0, phisics = 0, math = 0;
	struct faculty RE, KSIS, ITIY, KP, IEF;
	RE.name = "ФРЭ";
	RE.ball[0] = 281; RE.ball[1] = 260; RE.ball[2] = 271; RE.ball[3] = 282; RE.ball[4] = 235; RE.ball[5] = 248;
	RE.students = 1200;
	RE.date = 1964;
	RE.decan = "Короткевич Александр Васильевич";
	RE.qualification = "1.Инженер электронной техники\n2.Инженер по радиоэлектронике\n3.Инженер по электронным системам\n4.Педагог-программист";
	RE.specialities = "1.Микро- и наноэлектронные технологии и системы\t\t\t\t\t281\n2.Нанотехнологии и наноматериалы в электронике\t\t\t\t\t260\n3.Радиотехника (программируемые радиоэлектронные средства)\t\t\t271\n4.Радиоэлектронная защита информации\t\t\t\t\t\t282\n5.Электронные и информационно-управляющие системы физических установок\t\t235\n6.Радиоинформатика\t\t\t\t\t\t\t\t248\n";
	KSIS.name = "ФКСиС";
	KSIS.ball[0] = 327; KSIS.ball[1] = 358; KSIS.ball[2] = 352; KSIS.ball[3] = 318;
	KSIS.students = 2000;
	KSIS.date = 1964;
	KSIS.decan = "Боброва Наталья Леонидовна";
	KSIS.qualification = "1.Инженер-программист\n2.Инженер-системный программист\n3.Инженер-системотехник.";
	KSIS.specialities = "1.Вычислительные машины, системы и сети\t\t\t\t\t\t327\n2.Программное обеспечение информационных технологий\t\t\t\t358\n3.Информатика и технологии программирования\t\t\t\t\t352\n4.Электронные вычислительные средства\t\t\t\t\t\t318\n";
	ITIY.students = 1900;
	ITIY.date = 1964;
	ITIY.name = "ФИТиУ";
	ITIY.ball[0] = 347; ITIY.ball[1] = 337; ITIY.ball[2] = 317; ITIY.ball[3] = 301; ITIY.ball[4] = 365;
	ITIY.decan = "Шилин Леонид Юрьевич";
	ITIY.qualification = "1.Инженер по информационным технологиям и управлению\n2.Инженер по информационным технологиям\n3.Инженер-системотехник\n4.Инженер по радиоэлектронике\n5.Инженер-системный программист-геймдизайнер";
	ITIY.specialities = "1.Автоматизированные системы обработки информации\t\t\t\t347\n2.Искусственный интеллект\t\t\t\t\t\t\t337\n3.Информационные технологии и управление в технических системах\t\t\t317\n4.Промышленная электроника\t\t\t\t\t\t\t301\n5.Информационные системы и технологии (в игровой индустрии)\t\t\t365\n";
	KP.students = 1400;
	KP.ball[0] = 312; KP.ball[1] = 308; KP.ball[2] = 331; KP.ball[3] = 307, KP.ball[4] = 309; KP.ball[5] = 336; KP.ball[6] = 314; KP.ball[7] = 329; KP.ball[8] = 351;
	KP.name = "ФКП";
	KP.decan = "Лихачевский Дмитрий Викторович";
	KP.date = 1973;
	KP.qualification = "1.Инженер по радиоэлектронике\n2.Инженер электронной техники\n3.Инженер-системотехник\n4.Инженер-проектировщик\n5.Инженер по электронным системам\n6.Программист.Бизнес-аналитик";
	KP.specialities = "1.Проектирования и производство программно-управляемых электронных средств\t312\n2.Моделирование и компьютерное проектирование радиоэлектронных средств\t\t308\n3.Программируемые мобильные системы\t\t\t\t\t\t331\n4.Программно-управляемые  электронно-оптические системы\t\t\t\t307\n5.Медицинская электроника\t\t\t\t\t\t\t309\n6.Инженерно-психологическое обеспечение информационных технологий\t\t336\n7.Электронные системы безопасности\t\t\t\t\t\t314\n8.Информационные системы и технологии (в обеспечении промышленной безопасности)\t329\n9.Информационные системы и технологии (в бизнес-менеджменте)\t\t\t351\n";
	IEF.name = "ИЭФ";
	IEF.decan = "Лаврова Ольга Игоревна";
	IEF.date = 1994;
	IEF.ball[0] = 333; IEF.ball[1] = 326; IEF.ball[2] = 366; IEF.ball[3]=363;
	IEF.students = 1300;
	IEF.qualification = "1.Инженер-программист-экономист\n2.Экономист-программист\n3.Системный программист-логистик\n4.Маркетолог-программист";
	IEF.specialities = "1.Информационные системы и технологии (в экономике)\t\t\t\t333\n2.Информационные системы и технологии (в логистике)\t\t\t\t326\n3.Электронный маркетинг\t\t\t\t\t\t\t\t366\n4.Экономика электронного бизнеса\t\t\t\t\t\t363\n";


	while (n != 7)
	{
	
	
	printf("------------------------------------------МЕНЮ------------------------------------------\n");
	printf("1-Вывод информации о факультете КСИС\n");
	printf("2-Вывод информации о факультете ИТИУ\n");
	printf("3-Вывод информации о факультете РЭ\n");
	printf("4-Вывод информации о факультете ИЭФ\n");
	printf("5-Вывод информации о факультете КП\n");
	printf("6-Получить рекомендации\n");
	printf("7-Выход из программы\n");
	scanf_s("%d", &n);
	
	
		switch (n)
		{
		case 1:
			showInfo(KSIS);
			break;
		case 2:
			showInfo(ITIY);
			break;
		case 3:
			showInfo(RE);
			break;
		case 4:
			showInfo(IEF);
			break;
		case 5:
			showInfo(KP);
			break;
		case 6:
			do
			{
				printf("Введите ваш балл по русскому языку:\n");
				scanf_s("%d", &language);
				if (language < 0 || language>100) printf("Ошибка.Повторите попытку!\n");
				
			} while (language < 0 || language>100);
			
			do
			{
				printf("Введите ваш балл по физике:\n");
				scanf_s("%d", &phisics);
				if (phisics < 0 || phisics>100) printf("Ошибка.Повторите попытку!\n");

			} while (phisics < 0 || phisics>100);

			do
			{
				printf("Введите ваш балл по математике:\n");
				scanf_s("%d", &math);
				if (math < 0 || math>100) printf("Ошибка.Повторите попытку!\n");

			} while (math < 0 || math>100);
			
			do
			{
				printf("Введите ваш средний балл:\n");
				scanf_s("%d", &avg);
				if (avg < 0 || avg>100) printf("Ошибка.Повторите попытку!\n");

			} while (avg < 0 || avg>100);
			
			n = avg + language + phisics + math;
			recommendations(n, KSIS.ball, RE.ball, IEF.ball, ITIY.ball, KP.ball);
			break;
		case 7:
			return 0;
		default:
			printf("Неверное значение, повторите ввод!\n");
		}
	}
	
	return 0;
}
